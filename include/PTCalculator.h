#pragma once

#include <limits>
template<typename T> class NamedType
{
  public:
    using Type = T;
    NamedType() = default;
    constexpr explicit NamedType(const T &value) : m_value(value) {}
    constexpr explicit NamedType(T &&value) : m_value(std::move(value)) {}

    constexpr NamedType &operator=(T value)
    {
        m_value = value;
        return *this;
    }
    constexpr T operator()() const { return m_value; }

  private:
    T m_value{};
};

struct Temperature : public NamedType<float>
{
    using NamedType::NamedType;
};

struct Ohm : NamedType<float>
{
    using NamedType::NamedType;
};

struct Volt : NamedType<float>
{
    using NamedType::NamedType;
};

namespace PTCalculator {
namespace details {
    struct OhmTemperature
    {
        OhmTemperature() = default;
        constexpr OhmTemperature(const Ohm &resist, const Temperature &temperature) : resistance(resist()), temp(temperature()){};
        constexpr OhmTemperature(float resist, float temperature) : resistance(resist), temp(temperature){};
        Ohm resistance;
        Temperature temp;
    };

    struct VoltTemperature
    {
        VoltTemperature() = default;
        constexpr VoltTemperature(const Volt &volt, const Temperature &temperature) : voltage(volt()), temp(temperature()){};
        constexpr VoltTemperature(float volt, float temperature) : voltage(volt), temp(temperature){};
        Volt voltage;
        Temperature temp;
    };

    struct Constants
    {
        static inline constexpr float A_FACTOR = 0.0039083F;
        static inline constexpr float B_FACTOR = -0.0000005775F;
    };

    namespace unit_literals {
        constexpr auto operator""_Temp(long double value) { return Temperature{ static_cast<Temperature::Type>(value) }; }
        constexpr auto operator""_Ohm(long double value) { return Ohm{ static_cast<Ohm::Type>(value) }; }
        constexpr auto operator""_Volt(long double value) { return Volt{ static_cast<Volt::Type>(value) }; }
    }// namespace unit_literals

    inline constexpr Temperature OFFSET{ 273.15F };

    constexpr float sqrtNewtonRaphson(float x, float curr, float prev)
    {
        return curr == prev
                 ? curr
                 : sqrtNewtonRaphson(x, 0.5F * (curr + x / curr), curr);
    }

    constexpr float pow(float x, int y) { return y == 0 ? 1.0F : x * pow(x, y - 1); }

    constexpr float  sqrt(float x)
    {
        return x >= 0 && x < std::numeric_limits<float>::infinity()
                 ? sqrtNewtonRaphson(x, x, 0)
                 : std::numeric_limits<float>::quiet_NaN();
    }
}// namespace details

struct PT100
{
    static inline constexpr float R0 = 100.0F;
};

struct PT1000
{
    static inline constexpr float R0 = 1000.0F;
};

template<typename Type> constexpr auto calculate(float resistance)
{
    return (-1 * details::Constants::A_FACTOR * Type::R0
             + details::sqrt(details::pow(details::Constants::A_FACTOR * Type::R0, 2) - 4 * details::Constants::B_FACTOR * Type::R0 * (Type::R0 - resistance)))
           / (2 * details::Constants::B_FACTOR * Type::R0);
}
}// namespace PTCalculator
