#pragma once
#include <array>
#include <concepts>
#include <limits>
#include <algorithm>


template<typename T>
class NamedType
{
  public:
    using Type = T;
    NamedType() = default;
    constexpr explicit NamedType(const T &value) : m_value(value)
    {}
    constexpr explicit NamedType(T &&value) : m_value(std::move(value))
    {}

    constexpr NamedType &operator=(T value)
    {
        m_value = value;
        return *this;
    }
    constexpr T operator()() const
    {
        return m_value;
    }

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
    template<typename Type>
    concept IsContainer = requires(Type data) { data.begin(); };

    template<typename Type>
    concept InputConcept = std::is_same_v<Type, Ohm> || std::is_same_v<Type, Temperature> || IsContainer<Type>;

    struct Base : NamedType<float>
    {
        using NamedType::NamedType;
    };

    struct Constants
    {
        static inline constexpr float A_FACTOR = 0.0039083F;
        static inline constexpr float B_FACTOR = -0.0000005775F;
    };

    inline constexpr Temperature OFFSET{ 273.15F };

    constexpr float sqrt(Base base, float curr, float prev)
    {
        return curr == prev ? curr : sqrt(base, 0.5F * (curr + base() / curr), curr);
    }

    constexpr float pow(Base base, int y)
    {
        return y == 0 ? 1.0F : base() * pow(base, y - 1);
    }

    constexpr float sqrt(float x)
    {
        return x >= 0 && x < std::numeric_limits<float>::infinity() ? sqrt(Base{ x }, x, 0) : std::numeric_limits<float>::quiet_NaN();
    }

    template<typename Type>
    constexpr auto calculateTemperatureImpl(const Ohm value)
    {
        return Temperature{ (-1 * details::Constants::A_FACTOR * Type::R0
                              + details::sqrt(
                                details::pow(details::Base{ details::Constants::A_FACTOR * Type::R0 }, 2) - 4 * details::Constants::B_FACTOR * Type::R0 * (Type::R0 - value())))
                            / (2 * details::Constants::B_FACTOR * Type::R0) };
    }

    template<typename Type>
    constexpr auto calculateOhmImpl(const Temperature value)
    {
        return Ohm{ Type::R0 * (1 + details::Constants::A_FACTOR * value()) };
    }

    template<typename Type, size_t N, InputConcept T>
    constexpr auto calculateContainerImpl(const std::array<T, N> &inputData)
    {
        static_assert(details::InputConcept<T>, "Type in container not supported!");

        if constexpr (std::is_same_v<T, Ohm>) {
            std::array<Temperature, N> temp;
            std::transform(inputData.begin(), inputData.end(), temp.begin(), [](const auto& val){
                return calculateTemperatureImpl<Type>(val);
            });
            return temp;
        }

        if constexpr (std::is_same_v<T, Temperature>) {
            std::array<Ohm, N> temp;
            std::transform(inputData.begin(), inputData.end(), temp.begin(), [](const auto& val){
                return calculateOhmImpl<Type>(val);
            });
            return temp;
        }
    }
}// namespace details

namespace unit_literals {
    constexpr auto operator""_Temp(long double value)
    {
        return Temperature{ static_cast<Temperature::Type>(value) };
    }
    constexpr auto operator""_Ohm(long double value)
    {
        return Ohm{ static_cast<Ohm::Type>(value) };
    }
    constexpr auto operator""_Volt(long double value)
    {
        return Volt{ static_cast<Volt::Type>(value) };
    }
}// namespace unit_literals

struct PT100
{
    static inline constexpr float R0 = 100.0F;
};

struct PT1000
{
    static inline constexpr float R0 = 1000.0F;
};

template<typename Type, details::InputConcept Input>
constexpr auto calculate(Input data)
{
    static_assert(details::InputConcept<Input> || details::IsContainer<Input>, "Input not supported!");

    if constexpr (std::is_same_v<Input, Ohm>) {
        return details::calculateTemperatureImpl<Type>(data);
    }
    if constexpr (std::is_same_v<Input, Temperature>) {
        return details::calculateOhmImpl<Type>(data);
    }

    if constexpr (details::IsContainer<Input>) {
        return details::calculateContainerImpl<Type>(data);
    }
}
}// namespace PTCalculator
