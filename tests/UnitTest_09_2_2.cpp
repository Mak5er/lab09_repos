// UnitTest_09_2_2.cpp
// Рева Максим
// Модульний тест для Lab_09_2_2 (доведення співвідношення 1/H^2 = 1/a^2 + 1/b^2)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cmath>
#define main lab_09_2_2_main
#include "../Lab_09_2_2/Lab_09_2_2.cpp"
#undef main

TEST_SUITE("UnitTest_09_2_2")
{
    TEST_CASE("IsValidTriangle and ExtractRightTriangle checks")
    {
        CHECK(IsValidTriangle(3.0, 4.0, 5.0) == true);
        CHECK(IsValidTriangle(1.0, 2.0, 3.0) == false);
        CHECK(IsValidTriangle(-3.0, 4.0, 5.0) == false);

        double a = 0.0, b = 0.0, c = 0.0;
        CHECK(ExtractRightTriangle(3.0, 4.0, 5.0, a, b, c) == true);
        CHECK(c == doctest::Approx(5.0));

        // Перевірка незалежності від порядку сторін
        CHECK(ExtractRightTriangle(13.0, 5.0, 12.0, a, b, c) == true);
        CHECK(c == doctest::Approx(13.0));

        // Непрямокутний трикутник
        CHECK(ExtractRightTriangle(3.0, 4.0, 6.0, a, b, c) == false);
        CHECK(ExtractRightTriangle(5.0, 5.0, 5.0, a, b, c) == false);
    }

    TEST_CASE("CalcHeight and ProveRelation: 1/H^2 == 1/a^2 + 1/b^2")
    {
        double a = 0.0, b = 0.0, c = 0.0;
        double lhs = 0.0, rhs = 0.0;

        REQUIRE(ExtractRightTriangle(3.0, 4.0, 5.0, a, b, c));
        double H1 = CalcHeight(a, b, c);
        CHECK(H1 == doctest::Approx(2.4).epsilon(1e-7));
        CHECK(ProveRelation(a, b, H1, lhs, rhs) == true);
        CHECK(lhs == doctest::Approx(rhs).epsilon(1e-7));

        REQUIRE(ExtractRightTriangle(5.0, 12.0, 13.0, a, b, c));
        double H2 = CalcHeight(a, b, c);
        CHECK(H2 == doctest::Approx(60.0 / 13.0).epsilon(1e-7));
        CHECK(ProveRelation(a, b, H2, lhs, rhs) == true);
        CHECK(lhs == doctest::Approx(rhs).epsilon(1e-7));

        REQUIRE(ExtractRightTriangle(1.0, 1.0, std::sqrt(2.0), a, b, c));
        double H3 = CalcHeight(a, b, c);
        CHECK(H3 == doctest::Approx(std::sqrt(2.0) / 2.0).epsilon(1e-6));
        CHECK(ProveRelation(a, b, H3, lhs, rhs) == true);
        CHECK(lhs == doctest::Approx(rhs).epsilon(1e-6));
    }
}
