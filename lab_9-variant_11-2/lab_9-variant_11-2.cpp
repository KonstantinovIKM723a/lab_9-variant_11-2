#include <iostream>
#include "windows.h"
#include <cmath>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 5;
    int a[N][N];

    //Ініціалізуємо значення елементів масиву цілими числами від -9 до 9
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = rand() % 19 - 9;

    //Виводимо масив на екран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    //Знайти суму модулів елементів, розташованих нижче головної діагоналі
    int sum_abs = 0;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            sum_abs += abs(a[i][j]);
    cout << "Сума модулів елементів, розташованих нижче головної діагоналі: " << sum_abs << endl;

    //Вибрати елементи, які більші суми додатних елементів головної діагоналі масиву

    //Обчислимо суму додатних елементів на головної діагоналі
    int sum_pos_main_diag = 0;
    for (int i = 0; i < N; i++) if (a[i][i] > 0) sum_pos_main_diag += a[i][i];

    if (sum_pos_main_diag == 0) {
        cout << "На головної діагоналі нема додатних елементів";
    }
    else {
        cout << "Сума додатних елементів головної діагоналі: " << sum_pos_main_diag << endl;
        cout << "Елементи, які більші суми додатних елементів головної діагоналі: ";
        int counter = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a[i][j] > sum_pos_main_diag) { 
                    counter++;
                    cout << a[i][j] << " ";
                }
            }
        }
        if (counter == 0) cout << "таких елементів нема";
    }
    cout << endl;
}