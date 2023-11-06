#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<Windows.h>

using namespace std;

int generateRandomNumber() {
    system("chcp 1251");
    system("cls");
    srand(time(0));
    return rand() % 9000 + 1000;
}

string getUserGuess() {
    string guess;
    cout << "Введіть вашу догадку (чотирицифрове число): ";
    cin >> guess;
    return guess;
}

void checkGuess(const string& secretNumber, const string& userGuess, int& attempts) {
    if (userGuess.length() != 4) {
        cout << "Будь ласка, введіть чотирицифрове число." << endl;
        checkGuess(secretNumber, getUserGuess(), attempts);
        return;
    }

    int bulls = 0, cows = 0;

    for (int i = 0; i < 4; i++) {
        if (userGuess[i] == secretNumber[i]) {
            bulls++;
        }
        else if (secretNumber.find(userGuess[i]) != string::npos) {
            cows++;
        }
    }

    cout << "Бики: " << bulls << ", Корови: " << cows << endl;

    if (bulls == 4) {
        cout << "Ви вгадали число! Спроб: " << attempts << endl;
        return;
    }

    attempts++;
    checkGuess(secretNumber, getUserGuess(), attempts);
}

int main() {
    system("chcp 1251");
    system("cls");
    string secretNumber = to_string(generateRandomNumber());
    int attempts = 1;

    cout << "Ласкаво просимо до гри 'Бики та корови'!" << endl;

    checkGuess(secretNumber, getUserGuess(), attempts);

    return 0;
}
