// Lab_09_1.cpp
// Рева Максим
// Лабораторна робота № 9.1
// Простори імен: табулювання функції e^(x^2) за допомогою ряду Тейлора
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    // Введення початкових параметрів табулювання
    cout << "x_p = ";
    cin >> x_p;
    cout << "x_k = ";
    cin >> x_k;
    cout << "dx  = ";
    cin >> dx;
    cout << "eps = ";
    cin >> e;

    if (dx <= 0 || e <= 0)
    {
        cout << "Error: dx and eps must be positive!" << endl;
        return 1;
    }

    // Заголовок і шапка таблиці результатів
    cout << "\nTaylor series tabulation for f(x) = exp(x^2):" << endl;
    cout << "+----------+--------------+--------------+--------+" << endl;
    cout << "|    x     |   exp(x^2)   |      S       |   n    |" << endl;
    cout << "+----------+--------------+--------------+--------+" << endl;

    cout << fixed;
    x = x_p;
    while (x <= x_k + dx / 2.0)
    {
        sum(); // виклик підпрограми обчислення суми ряду

        cout << "| " << setw(8) << setprecision(2) << x << " | "
             << setw(12) << setprecision(5) << exp(x * x) << " | "
             << setw(12) << setprecision(5) << s << " | "
             << setw(6) << n << " |" << endl;

        x += dx;
    }

    cout << "+----------+--------------+--------------+--------+" << endl;
    return 0;
}
