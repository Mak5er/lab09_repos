// Lab_09_2_1.cpp
// Рева Максим
// Лабораторна робота № 9.2.1
// Директиви препроцесора (Частина 1): умовна компіляція та макроси
// Варіант 23

#include <iostream>
#include "macros.h"

using namespace std;

// Обчислення значення виразу w з використанням директив умовної компіляції
double CalcW(double x, double y, double z)
{
#if IN_BRANCH_1(Z)
    // Гілка 1 (1 < z < 3): w = max(|x| + |y| + |z|, x^3)
    return MAX(ABS(x) + ABS(y) + ABS(z), CUBE(x));
#elif IN_BRANCH_2(Z)
    // Гілка 2 (z > 3): w = min(2x + y, (2y - z)^2)
    return MIN(2.0 * x + y, SQR(2.0 * y - z));
#else
    #error "Macro Z must satisfy either 1 < Z < 3 or Z > 3"
#endif
}

int main()
{
    double x = 0.0, y = 0.0;
    const double z = static_cast<double>(Z);

#if IN_BRANCH_1(Z)
    PRINT_MSG("Compiled branch 1 (1 < z < 3): w = max(|x| + |y| + |z|, x^3)");
#elif IN_BRANCH_2(Z)
    PRINT_MSG("Compiled branch 2 (z > 3): w = min(2x + y, (2y - z)^2)");
#endif

    cout << "Preprocessor constant z = " << z << endl;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    double w = CalcW(x, y, z);
    PRINTR(w);

    return 0;
}
