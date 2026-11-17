// UnitTest_09_2_1.cpp
// Рева Максим
// Модульний тест для Lab_09_2_1 (макроси та умовна компіляція)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_09_2_1_main
#include "../Lab_09_2_1/Lab_09_2_1.cpp"
#undef main

TEST_SUITE("UnitTest_09_2_1")
{
    TEST_CASE("Preprocessor macros MAX, MIN, ABS, SQR, CUBE and branch predicates")
    {
        CHECK(MAX(3, 7) == 7);
        CHECK(MAX(-2, -5) == -2);
        CHECK(MIN(3, 7) == 3);
        CHECK(MIN(-2, -5) == -5);
        CHECK(ABS(-12.5) == doctest::Approx(12.5));
        CHECK(ABS(4.0) == doctest::Approx(4.0));
        CHECK(SQR(-5) == 25);
        CHECK(CUBE(-3) == -27);
        CHECK(CUBE(2) == 8);

        CHECK(IN_BRANCH_1(2) == true);
        CHECK(IN_BRANCH_1(3) == false);
        CHECK(IN_BRANCH_2(5) == true);
        CHECK(IN_BRANCH_2(2) == false);
    }

    TEST_CASE("CalcW under conditionally compiled Z branch")
    {
#if IN_BRANCH_1(Z)
        // Branch 1: max(|x| + |y| + |z|, x^3)
        CHECK(CalcW(3.0, -4.0, Z) == doctest::Approx(27.0));
        CHECK(CalcW(-3.0, 4.0, Z) == doctest::Approx(7.0 + ABS(Z)));
        CHECK(CalcW(1.0, 2.0, Z) == doctest::Approx(3.0 + ABS(Z)));
#elif IN_BRANCH_2(Z)
        // Branch 2: min(2x + y, (2y - z)^2)
        CHECK(CalcW(1.0, 2.0, Z) == doctest::Approx(MIN(4.0, SQR(4.0 - Z))));
        CHECK(CalcW(-2.0, 1.0, Z) == doctest::Approx(-3.0));
#endif
    }
}
