#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

constexpr int NUM_BINS = 10; // Количество интервалов для критерия хи-квадрат

// Функция для вычисления значения критерия хи-квадрат
static double chiSquare(const vector<int>& observed, const vector<int>& expected) {
    double chiSquareValue = 0.0;
    for (size_t i = 0; i < observed.size(); ++i) {
        if (expected[i] != 0) {
            chiSquareValue += pow(observed[i] - expected[i], 2) / expected[i];
        }
    }
    return chiSquareValue;
}

int main() {
    setlocale(LC_ALL, "ru");

    minstd_rand gen;
    uniform_int_distribution<> dis(1, 100); // Генерация чисел от 1 до 100

    // Размеры массивов
    vector<int> arraySizes = { 50, 100, 1000 };
    for (int arraySize : arraySizes) {
        vector<int> array(arraySize); // Динамическое выделение памяти для массива

        // Заполнение массива
        for (int& num : array) {
            num = dis(gen);
        }

        // Вычисление наблюдаемых частот для каждого интервала
        vector<int> observed(NUM_BINS, 0);
        for (int num : array) {
            int bin = (num - 1) / (100 / NUM_BINS);
            ++observed[bin];
        }

        // Вычисление ожидаемых частот, предполагая равномерное распределение
        vector<int> expected(NUM_BINS, arraySize / NUM_BINS);

        // Вычисление значения критерия хи-квадрат
        double chiSquareValue = chiSquare(observed, expected);

        // Вывод результатов
        cout << "Размер массива: " << arraySize << endl;
        cout << "Значение критерия хи-квадрат: " << chiSquareValue << endl;

        // Проведение проверки гипотезы
        double criticalValue = 16.919; // Критическое значение для 9 степеней свободы при alpha = 0.05
        if (chiSquareValue > criticalValue) {
            cout << "Гипотеза отвергнута: Распределение не является примерно равномерным." << endl;
        }
        else {
            cout << "Гипотеза принята: Распределение примерно равномерное." << endl;
        }

        // Вычисление ожидаемого и фактического среднего
        double expectedMean = 50.5; // Ожидаемое среднее для равномерного распределения от 1 до 100
        double actualMean = 0.0;

        for (int num : array) {
            actualMean += num;
        }
        actualMean /= arraySize;

        cout << "Ожидаемое среднее: " << expectedMean << endl;
        cout << "Фактическое среднее: " << actualMean << endl;
        cout << endl;
    }

    return 0;
}