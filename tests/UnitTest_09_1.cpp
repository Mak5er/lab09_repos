// UnitTest_09_1.cpp
// Рева Максим
// Модульний тест для багатомодульного проекту Lab_09_1 (простори імен nsVar, nsDod, nsSum)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cmath>
#include "../Lab_09_1/var.h"
#include "../Lab_09_1/dod.h"
#include "../Lab_09_1/sum.h"

using namespace nsVar;
using namespace nsDod;
using namespace nsSum;

TEST_SUITE("UnitTest_09_1")
{
    TEST_CASE("nsDod::dod - recurrence relation a_n = a_{n-1} * (x^2 / n)")
    {
        x = 2.0;
        a = 1.0;
        n = 1;
        dod();
        CHECK(a == doctest::Approx(4.0).epsilon(1e-7));

        n = 2;
        dod();
        CHECK(a == doctest::Approx(8.0).epsilon(1e-7));

        x = 1.0;
        a = 1.0;
        n = 1;
        dod();
        CHECK(a == doctest::Approx(1.0).epsilon(1e-7));

        x = 0.0;
        a = 1.0;
        n = 1;
        dod();
        CHECK(a == doctest::Approx(0.0).epsilon(1e-7));
    }

    TEST_CASE("nsSum::sum - Taylor series for exp(x^2)")
    {
        e = 1e-6;

        x = 0.0;
        sum();
        CHECK(s == doctest::Approx(1.0).epsilon(1e-6));
        CHECK(n == 1);

        x = 0.5;
        sum();
        CHECK(s == doctest::Approx(std::exp(0.25)).epsilon(1e-6));

        x = 1.0;
        sum();
        CHECK(s == doctest::Approx(std::exp(1.0)).epsilon(1e-6));

        x = -1.0;
        sum();
        CHECK(s == doctest::Approx(std::exp(1.0)).epsilon(1e-6));

        x = 1.5;
        sum();
        CHECK(s == doctest::Approx(std::exp(2.25)).epsilon(1e-6));
    }
}
