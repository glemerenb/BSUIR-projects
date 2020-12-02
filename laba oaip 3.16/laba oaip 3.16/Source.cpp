#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

double getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        double variable;
        cin >> variable;

        // Проверка на предыдущее извлечение
        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            cin.ignore(32767, '\n'); // удаляем лишние значения
            return variable;
        }
    }
}

int main() {
    double y_x, k, func_abs, min_number, max_number, step, num_of_operation;
    double sum, z;
    int option;

    cout << "Enter 0 or another symbols to use data from base, or numbers to input values: ";
    cin >> option;

    switch (option)
    {
    case 0:
        min_number = 0.1;
        max_number = 1;
        step = 0.1;
        num_of_operation = 16;

        break;
    default:
        cout << "Enter min_number: ";
        min_number = getValue();
        cout << "Enter max_number: ";
        max_number = getValue();
        cout << "Enter num_of_operation: ";
        num_of_operation = getValue();
        cout << "Enter step: ";
        step = getValue();
        cout << endl;
    }

    printf("|----------------------------------------------------------------------------------------------------------| \n");
    while (min_number <= max_number) {
        y_x = cos(min_number * sin(M_PI_4)) * exp(min_number * cos(M_PI_4));
        sum = z = 1;
        for (k = 1; k <= num_of_operation; k++) {
            z *= min_number / k;
            sum += z * cos(k * M_PI_4);
        }
        func_abs = fabs(y_x - sum);
        printf("|x = %14e; |  S(x) = %14e;  | Y(x) = %14e;  |  |Y(x) - S(x)| = %14e|\n", min_number, sum, y_x, func_abs);
        min_number += step;
    }
    printf("|----------------------------------------------------------------------------------------------------------|");
    return 0;
}