#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <tuple>

using namespace std;

// Объявление функции f(x) = (x - 6)^2 + ln(x)
static double f(double x) {
    return pow(x - 6, 2) + log(x);
}

// Объявление производной функции f(x)
static double df(double x) {
    return 2 * (x - 6) + 1 / x;
}

// Объявление функции для метода половинного деления
static void bisectionMethod(double a, double b, double eps, vector<tuple<double, double, double, double>>& bisection, double& res) {
    int N = 0;
    while ((b - a) >= eps && N < 100) {
        double c = (a + b) / 2;
        bisection.emplace_back(N, a, b, b - a);
        if (f(c) == 0) {
            break;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        N++;
        res = c;
    }
}

// Объявление функции для метода Ньютона
static void newtonMethod(double x0, double eps, vector<tuple<double, double, double, double>>& newton, double& res) {
    int N = 0;
    while (abs(f(x0)) >= eps && N < 100) {
        double x1 = x0 - f(x0) / df(x0);
        double diff = abs(x1 - x0);
        newton.emplace_back(N, x0, x1, diff);
        if (diff < eps) {
            break;
        }
        x0 = x1;
        N++;
        res = x0;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    double a = 1, b = 10, eps = 0.0001; // Задание начальных значений интервала и точности
    double res; // Переменная для хранения результата
    vector<tuple<double, double, double, double>> bisection; // Вектор для хранения результатов метода половинного деления
    vector<tuple<double, double, double, double>> newton; // Вектор для хранения результатов метода Ньютона

    // Решение уравнения методом половинного деления
    bisectionMethod(a, b, eps, bisection, res);
    cout << "Метод половинного деления:" << endl;
    cout << "N" << setw(20) << "a" << setw(20) << "b" << setw(20) << "b - a" << endl;
    for (tuple<double, double, double, double> i : bisection) {
        cout << get<0>(i) << setw(20) << get<1>(i) << setw(20) << get<2>(i) << setw(20) << get<3>(i) << endl;
    }
    cout << "Корень: " << res << endl;

    // Решение уравнения методом Ньютона
    double x0 = 9; // Начальное приближение
    newtonMethod(x0, eps, newton, res);
    cout << "Метод Ньютона:" << endl;
    cout << "N" << setw(20) << "x0" << setw(20) << "x1" << setw(20) << "x1 - x0" << endl;
    for (tuple<double, double, double, double> i : newton) {
        cout << get<0>(i) << setw(20) << get<1>(i) << setw(20) << get<2>(i) << setw(20) << get<3>(i) << endl;
    }
    cout << "Корень: " << res << endl;

    return 0;
}