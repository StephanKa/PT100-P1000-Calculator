#include <catch2/catch_all.hpp>
#include <PTCalculator.h>

using namespace PTCalculator::unit_literals;

constexpr auto EPSILON = 0.1;
constexpr bool operator==(const Temperature &lhs, const Temperature &rhs)
{
    return static_cast<double>(std::fabs(lhs() - rhs())) <= EPSILON;
}

constexpr bool operator==(const Ohm &lhs, const Ohm &rhs)
{
    return static_cast<double>(std::fabs(lhs() - rhs())) <= EPSILON;
}

TEST_CASE("[constexpr PT100]")
{
    SECTION("Ohm to temperature 0°C")
    {
        constexpr auto resistancePt100 = 100.0_Ohm;
        STATIC_REQUIRE(0.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 100°C")
    {
        constexpr auto resistancePt100 = 138.51_Ohm;
        STATIC_REQUIRE(100.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 200°C")
    {
        constexpr auto resistancePt100 = 175.86_Ohm;
        STATIC_REQUIRE(200.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 300°C")
    {
        constexpr auto resistancePt100 = 212.05_Ohm;
        STATIC_REQUIRE(300.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 400°C")
    {
        constexpr auto resistancePt100 = 247.09_Ohm;
        STATIC_REQUIRE(400.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 500°C")
    {
        constexpr auto resistancePt100 = 280.98_Ohm;
        STATIC_REQUIRE(500.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 600°C")
    {
        constexpr auto resistancePt100 = 313.71_Ohm;
        STATIC_REQUIRE(600.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 700°C")
    {
        constexpr auto resistancePt100 = 345.28_Ohm;
        STATIC_REQUIRE(700.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }
    SECTION("Ohm to temperature 800°C")
    {
        constexpr auto resistancePt100 = 375.70_Ohm;
        STATIC_REQUIRE(800.0_Temp == PTCalculator::calculate<PTCalculator::PT100>(resistancePt100));
    }

    SECTION("100°C Temperature to Ohm")
    {
        constexpr auto temperaturePt100 = 100.0_Temp;
        constexpr auto res = PTCalculator::calculate<PTCalculator::PT100>(temperaturePt100);
        STATIC_REQUIRE(139.0_Ohm == res);
    }
    SECTION("200°C Temperature to Ohm")
    {
        constexpr auto temperaturePt100 = 200.0_Temp;
        STATIC_REQUIRE(178.1_Ohm == PTCalculator::calculate<PTCalculator::PT100>(temperaturePt100));
    }
    SECTION("300°C Temperature to Ohm")
    {
        constexpr auto temperaturePt100 = 300.0_Temp;
        STATIC_REQUIRE(217.2_Ohm == PTCalculator::calculate<PTCalculator::PT100>(temperaturePt100));
    }
    SECTION("400°C Temperature to Ohm")
    {
        constexpr auto temperaturePt100 = 400.0_Temp;
        STATIC_REQUIRE(256.3_Ohm == PTCalculator::calculate<PTCalculator::PT100>(temperaturePt100));
    }
}

TEST_CASE("[constexpr PT1000]")
{
    SECTION("Ohm to temperature 0°C")
    {
        constexpr auto resistancePt1000 = 1000.0_Ohm;
        STATIC_REQUIRE(0.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 100°C")
    {
        constexpr auto resistancePt1000 = 1385.1_Ohm;
        STATIC_REQUIRE(100.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 200°C")
    {
        constexpr auto resistancePt1000 = 1758.6_Ohm;
        STATIC_REQUIRE(200.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 300°C")
    {
        constexpr auto resistancePt1000 = 2120.5_Ohm;
        STATIC_REQUIRE(300.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 400°C")
    {
        constexpr auto resistancePt1000 = 2470.9_Ohm;
        STATIC_REQUIRE(400.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 500°C")
    {
        constexpr auto resistancePt1000 = 2809.8_Ohm;
        STATIC_REQUIRE(500.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 600°C")
    {
        constexpr auto resistancePt1000 = 3137.1_Ohm;
        STATIC_REQUIRE(600.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 700°C")
    {
        constexpr auto resistancePt1000 = 3452.8_Ohm;
        STATIC_REQUIRE(700.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }
    SECTION("Ohm to temperature 800°C")
    {
        constexpr auto resistancePt1000 = 3757.0_Ohm;
        STATIC_REQUIRE(800.0_Temp == PTCalculator::calculate<PTCalculator::PT1000>(resistancePt1000));
    }

    SECTION("100°C Temperature to Ohm")
    {
        constexpr auto temperaturePt1000 = 100.0_Temp;
        STATIC_REQUIRE(1390.8_Ohm == PTCalculator::calculate<PTCalculator::PT1000>(temperaturePt1000));
    }
    SECTION("200°C Temperature to Ohm")
    {
        constexpr auto temperaturePt1000 = 200.0_Temp;
        STATIC_REQUIRE(1781.6_Ohm == PTCalculator::calculate<PTCalculator::PT1000>(temperaturePt1000));
    }
    SECTION("300°C Temperature to Ohm")
    {
        constexpr auto temperaturePt1000 = 300.0_Temp;
        STATIC_REQUIRE(2172.4_Ohm == PTCalculator::calculate<PTCalculator::PT1000>(temperaturePt1000));
    }
    SECTION("400°C Temperature to Ohm")
    {
        constexpr auto temperaturePt1000 = 400.0_Temp;
        STATIC_REQUIRE(2563.3_Ohm == PTCalculator::calculate<PTCalculator::PT1000>(temperaturePt1000));
    }
}

TEST_CASE("[constexpr test different container]")
{
    SECTION("PT100 std::array Temperature to Ohm")
    {
        constexpr auto check = std::array{139.0_Ohm, 178.1_Ohm, 217.2_Ohm, 256.3_Ohm};
        constexpr auto result = PTCalculator::calculate<PTCalculator::PT100>(std::array{ 100.0_Temp, 200.0_Temp, 300.0_Temp, 400.0_Temp });
        STATIC_REQUIRE(check == result);
    }

    SECTION("PT1000 std::array Temperature to Ohm")
    {
        constexpr auto check = std::array{1390.8_Ohm, 1781.6_Ohm, 2172.4_Ohm, 2563.3_Ohm};
        constexpr auto result = PTCalculator::calculate<PTCalculator::PT1000>(std::array{ 100.0_Temp, 200.0_Temp, 300.0_Temp, 400.0_Temp });
        STATIC_REQUIRE(check == result);
    }

    SECTION("PT100 std::array Temperature to Ohm")
    {
        constexpr auto check = std::array{0.0_Temp, 266.3_Temp, 557.6_Temp, 882.7_Temp};
        constexpr auto result = PTCalculator::calculate<PTCalculator::PT100>(std::array{ 100.0_Ohm, 200.0_Ohm, 300.0_Ohm, 400.0_Ohm });
        STATIC_REQUIRE(check == result);
    }

    SECTION("PT1000 std::array Ohm to Temperature")
    {
        constexpr auto check = std::array{0.0_Temp, 266.3_Temp, 557.6_Temp, 882.7_Temp};
        constexpr auto result = PTCalculator::calculate<PTCalculator::PT1000>(std::array{ 1000.0_Ohm, 2000.0_Ohm, 3000.0_Ohm, 4000.0_Ohm });
        STATIC_REQUIRE(check == result);
    }
}
