// triangle_macros.h
// Рева Максим
// Лабораторна робота № 9.2.2 (Директиви препроцесора. Частина 2)
// Заголовний файл з макросами геометричних перевірок та діагностики
// Варіант 23

#pragma once

#include <iostream>
#include <iomanip>

#define EPS 1e-6

// Базові математичні макроси
#define SQR(v) ((v) * (v))
#define ABS(v) (((v) < 0) ? (-(v)) : (v))
#define MAX2(a, b) (((a) > (b)) ? (a) : (b))
#define MAX3(a, b, c) MAX2(MAX2(a, b), (c))

// Макроси перевірки існування та прямокутності трикутника
#define IS_TRIANGLE(a, b, c) \
    (((a) > 0) && ((b) > 0) && ((c) > 0) && \
     (((a) + (b)) > (c)) && (((a) + (c)) > (b)) && (((b) + (c)) > (a)))

#define IS_RIGHT_TRIANGLE(a, b, hyp) (ABS(SQR(a) + SQR(b) - SQR(hyp)) < EPS)

// Макроси обчислення висоти H до гіпотенузи та оберненого квадрата
#define CALC_HEIGHT(a, b, hyp) (((a) * (b)) / (hyp))
#define INV_SQR(v) (1.0 / SQR(v))

// Макрос форматованого виводу величини
#define PRINT_VAL(label, val) \
    std::cout << (label) << " = " << std::fixed << std::setprecision(6) << (val) << std::endl

// Умовна компіляція діагностичних повідомлень за допомогою __FILE__ і __LINE__
#ifdef DEBUG_DIAG
#define LOG_DIAG(msg) \
    std::cout << "[DIAG " << __FILE__ << ":" << __LINE__ << "] " << (msg) << std::endl
#else
#define LOG_DIAG(msg) ((void)0)
#endif
