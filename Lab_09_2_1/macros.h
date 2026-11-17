// macros.h
// Рева Максим
// Лабораторна робота № 9.2.1 (Директиви препроцесора. Частина 1)
// Заголовний файл з макровизначеннями та умовами розгалуження
// Варіант 23

#pragma once

#include <iostream>
#include <iomanip>

// Значення параметра z для умовної компіляції препроцесором
#ifndef Z
#define Z 2
#endif

// Макроси математичних операцій та логічних виразів
#ifdef MAX
#undef MAX
#endif
#ifdef MIN
#undef MIN
#endif
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(v)    (((v) < 0) ? (-(v)) : (v))
#define SQR(v)    ((v) * (v))
#define CUBE(v)   ((v) * (v) * (v))

// Логічні умови вибору гілки обчислення w за значенням z
#define IN_BRANCH_1(z) (((z) > 1) && ((z) < 3))
#define IN_BRANCH_2(z) ((z) > 3)

// Макроси виведення результатів
#define PRINTR(val) std::cout << #val << " = " << std::fixed << std::setprecision(4) << (val) << std::endl
#define PRINT_MSG(msg) std::cout << (msg) << std::endl
