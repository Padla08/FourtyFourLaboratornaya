#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Задание 1: Инициализация массива из 10 случайных чисел в диапазоне [0, 100]
    const int n = 10;
    vector<double> arr(n);
    random_device rd;
    minstd_rand gen(rd());
    uniform_real_distribution<> dis(0, 100);
    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }
    cout << "Задание 1: Массив из 10 случайных чисел в диапазоне [0, 100]:" << endl;
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Задание 2: Вычисление среднего значения и суммы квадратов разностей
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    double average = sum / n;
    double sum_of_squares = 0;
    for (int i = 0; i < n; ++i) {
        sum_of_squares += (arr[i] - average) * (arr[i] - average);
    }
    cout << "Задание 2: Сумма квадратов разностей: " << sum_of_squares << endl;

    // Задание 3: Замена первого и последнего разрядов чётных элементов с чётным номером
    for (int i = 0; i < n; i += 2) {
        int num = static_cast<int>(arr[i]);
        if (num >= 10 && num < 100) {
            int first_digit = num / 10;
            int last_digit = num % 10;
            arr[i] = last_digit * 10 + first_digit;
        }
    }
    cout << "Задание 3: Массив после замены первого и последнего разрядов:" << endl;
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Задание 4: Сдвиг элементов массива на одну позицию вправо
    rotate(arr.begin(), arr.begin() + 1, arr.end());
    cout << "Задание 4: Массив после сдвига на одну позицию вправо:" << endl;
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Задание 5: Инициализация массива из 50 случайных чисел в диапазоне [-10, 10]
    const int m = 50;
    vector<int> arr2(m);
    uniform_int_distribution<> dis2(-10, 10);
    for (int i = 0; i < m; ++i) {
        arr2[i] = dis2(gen);
    }
    cout << "Задание 5: Массив из 50 случайных чисел в диапазоне [-10, 10]:" << endl;
    for (const auto& num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Подсчёт количества вхождений каждого числа в массиве
    map<int, int> count;
    for (int i = 0; i < m; ++i) {
        count[arr2[i]]++;
    }
    cout << "Задание 5: Количество вхождений каждого числа в массиве:" << endl;
    for (const auto& pair : count) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Удаление повторяющихся элементов из массива
    sort(arr2.begin(), arr2.end());
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
    cout << "Задание 5: Массив после удаления повторяющихся элементов:" << endl;
    for (const auto& num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}