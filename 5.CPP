#include <iostream>
#include <vector>

using namespace std;

class LCG {
private:
    unsigned long long seed; // Текущее состояние генератора
    const unsigned long long a = 6364136223846793005; // Множитель
    const unsigned long long c = 1442695040888963407; // Приращение
    const unsigned long long m = 18446744073709551616ULL; // Модуль, 2^64 для 64-битного целого без знака

public:
    LCG(unsigned long long seed) : seed(seed) {} // Конструктор, принимающий начальное значение

    unsigned long long generate() {
        seed = (a * seed + c) % m; // Генерация следующего числа
        return seed; // Возвращение сгенерированного числа
    }
};

int main() {
    // Пример использования
    unsigned long long seed = 123456789; // Пример начального значения, замените на свое
    LCG lcg(seed); // Создание экземпляра генератора с заданным начальным значением

    // Генерация псевдослучайных чисел
    for (int k = 0; k < 100; k++) {
        cout << lcg.generate() << " "; // Генерация и вывод числа
        if ((k + 1) % 10 == 0) cout << endl; // Перенос строки после каждых 10 чисел
    }
    cout << endl;

    return 0;
}