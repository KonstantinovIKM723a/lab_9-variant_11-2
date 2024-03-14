#include <iostream>
#include "windows.h"
#include <cmath>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 5;
    int a[N][N];

    //Ініціалізуємо значення елементів масиву цілими числами від -5 до 5
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = rand() % 11 - 5;


    //Знайти суму модулів елементів, розташованих нижче головної діагоналі
    int sum_abs = 0;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            sum_abs += abs(a[i][j]);


    cout << sum_abs;

}