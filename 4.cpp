#include <iostream>
#include <vector>
#include <random>
#include <functional>
using namespace std;
// Функция, которая реализует игру
void playGame(function<bool(int, const vector<bool>&, const vector<bool>&)> algorithm1,
              function<bool(int, const vector<bool>&, const vector<bool>&)> algorithm2) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(100, 200);
    int rounds = dis(gen);

    vector<bool> algorithm1Choices(rounds);
    vector<bool> algorithm2Choices(rounds);
    int algorithm1Score = 0;
    int algorithm2Score = 0;

    for (int round = 0; round < rounds; ++round) {
        bool algorithm1Choice = algorithm1(round, algorithm1Choices, algorithm2Choices);
        bool algorithm2Choice = algorithm2(round, algorithm2Choices, algorithm1Choices);

        algorithm1Choices[round] = algorithm1Choice;
        algorithm2Choices[round] = algorithm2Choice;

        if (algorithm1Choice && algorithm2Choice) {
            algorithm1Score += 24;
            algorithm2Score += 24;
        } else if (algorithm1Choice) {
            algorithm2Score += 20;
        } else if (algorithm2Choice) {
            algorithm1Score += 20;
        } else {
            algorithm1Score += 4;
            algorithm2Score += 4;
        }
    }

    cout << "Algorithm 1 Score: " << algorithm1Score << endl;
    cout << "Algorithm 2 Score: " << algorithm2Score << endl;
}

// Примеры алгоритмов
bool algorithm1(int round, const vector<bool>& selfChoices, const vector<bool>& enemyChoices) {
    // Алгоритм всегда соглашается
    return true;
}

bool algorithm2(int round, const vector<bool>& selfChoices, const vector<bool>& enemyChoices) {
    // Алгоритм всегда предает
    return false;
}

bool algorithm3(int round, const vector<bool>& selfChoices, const vector<bool>& enemyChoices) {
    // Алгоритм соглашается, если противник не предался в предыдущих раундах
    for (int i = 0; i < round; ++i) {
        if (!enemyChoices[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Запуск игры с каждым из алгоритмов
    for (int i = 0; i < 3; ++i) {
        cout << "Game " << i + 1 << ":" << endl;
        playGame(algorithm1, algorithm2);
        playGame(algorithm1, algorithm3);
        playGame(algorithm2, algorithm3);
        cout << endl;
    }

    return 0;
}