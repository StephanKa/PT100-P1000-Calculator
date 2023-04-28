#include "include/version.hpp"
#include <PTCalculator.h>
#include <fmt/format.h>

int main()
{
    fmt::print("Version: {}.{}-{}\n", Version::Major, Version::Minor, Version::Patch);
    constexpr auto Resistance = 175.86F;
    constexpr auto result = PTCalculator::calculate<PTCalculator::PT100>(Resistance);
    fmt::print("Resistance: {} Ohm\nTemperature: {:.2f} °C\n", Resistance, result);
    return 0;
}
