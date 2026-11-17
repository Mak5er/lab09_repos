// Lab_09_2_2.cpp
// Рева Максим
// Лабораторна робота № 9.2.2
// Директиви препроцесора (Частина 2): доведення співвідношення 1/H^2 = 1/a^2 + 1/b^2
// Варіант 23

#include <iostream>
#include <cassert>
#include "triangle_macros.h"

using namespace std;

// Перевірка існування трикутника зі сторонами s1, s2, s3
bool IsValidTriangle(double s1, double s2, double s3)
{
    return IS_TRIANGLE(s1, s2, s3);
}

// Визначення катетів (a, b), гіпотенузи (c) та перевірка прямокутності трикутника
bool ExtractRightTriangle(double s1, double s2, double s3, double &a, double &b, double &c)
{
    if (!IsValidTriangle(s1, s2, s3))
        return false;

    c = MAX3(s1, s2, s3);
    if (c == s1)
    {
        a = s2;
        b = s3;
    }
    else if (c == s2)
    {
        a = s1;
        b = s3;
    }
    else
    {
        a = s1;
        b = s2;
    }

    return IS_RIGHT_TRIANGLE(a, b, c);
}

// Обчислення висоти H, проведеної до гіпотенузи c
double CalcHeight(double a, double b, double c)
{
    assert(a > 0 && b > 0 && c > 0);
    return CALC_HEIGHT(a, b, c);
}

// Перевірка тотожності 1/H^2 = 1/a^2 + 1/b^2
bool ProveRelation(double a, double b, double H, double &lhs, double &rhs)
{
    assert(a > 0 && b > 0 && H > 0);
    lhs = INV_SQR(H);
    rhs = INV_SQR(a) + INV_SQR(b);
    return ABS(lhs - rhs) < EPS;
}

int main()
{
    double s1 = 0.0, s2 = 0.0, s3 = 0.0;
    cout << "Enter triangle sides (s1 s2 s3): ";
    if (!(cin >> s1 >> s2 >> s3))
    {
        cout << "Input error!" << endl;
        return 1;
    }

    LOG_DIAG("Validating triangle existence");
    if (!IsValidTriangle(s1, s2, s3))
    {
        cout << "Triangle with sides (" << s1 << ", " << s2 << ", " << s3 << ") does not exist." << endl;
        return 0;
    }

    double a = 0.0, b = 0.0, c = 0.0;
    if (!ExtractRightTriangle(s1, s2, s3, a, b, c))
    {
        cout << "Triangle (" << s1 << ", " << s2 << ", " << s3 << ") is NOT right-angled." << endl;
        return 0;
    }

    LOG_DIAG("Right triangle confirmed; computing H and inverse squares");
    cout << "Triangle is right-angled: legs a = " << a << ", b = " << b << ", hypotenuse c = " << c << endl;

    double H = CalcHeight(a, b, c);
    double lhs = 0.0, rhs = 0.0;
    bool proven = ProveRelation(a, b, H, lhs, rhs);

    PRINT_VAL("H", H);
    PRINT_VAL("1 / H^2", lhs);
    PRINT_VAL("1 / a^2 + 1 / b^2", rhs);

    if (proven)
        cout << "Identity 1/H^2 = 1/a^2 + 1/b^2 PROVEN (|LHS - RHS| < " << EPS << ")." << endl;
    else
        cout << "Identity NOT satisfied." << endl;

    return 0;
}
