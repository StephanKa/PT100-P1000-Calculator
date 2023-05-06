#include "include/version.hpp"
#include <PTCalculator.h>
#include <fmt/format.h>

using namespace PTCalculator::unit_literals;

int main()
{
    fmt::print("Version: {}.{}-{}\n", Version::Major, Version::Minor, Version::Patch);
    constexpr auto ResistancePt100 = 175.86_Ohm;
    constexpr auto ResistancePt1000 = 1758.56_Ohm;
    constexpr auto resultPt100 = PTCalculator::calculate<PTCalculator::PT100>(ResistancePt100);
    fmt::print("\nPT100 Input Ohm\nResistance: {:.2f} Ohm\nTemperature: {:.2f} °C\n", ResistancePt100(), resultPt100());

    constexpr auto resultPt1000 = PTCalculator::calculate<PTCalculator::PT1000>(ResistancePt1000);
    fmt::print("\nPT1000 Input Ohm\nResistance: {:.2f} Ohm\nTemperature: {:.2f} °C\n", ResistancePt1000(), resultPt1000());

    constexpr auto resultOhmPt1000 = PTCalculator::calculate<PTCalculator::PT1000>(resultPt1000);
    fmt::print("\nPT1000 Input Temperature\nResistance: {:.2f} Ohm\nTemperature: {:.2f} °C\n", resultOhmPt1000(), resultPt1000());

    constexpr auto containerResult = PTCalculator::calculate<PTCalculator::PT1000>(std::array{ 1000.0_Ohm, 2000.0_Ohm, 3000.0_Ohm, 4000.0_Ohm });
    for (const auto &temp : containerResult) {
        fmt::print("Test: {} Ohm\n", temp());
    }

    return 0;
}
