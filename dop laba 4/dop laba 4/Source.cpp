#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

double S_X(double, int);
double Y_X(double, int);
double func_differ(double, int);
void print(double min_number, double max_number, double step, int num_of_operation, double (*ff)(double, int));

int getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        int variable;
        cin >> variable;

        // Проверка на предыдущее извлечение
        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else {
            cin.ignore(32767, '\n'); // удаляем лишние значения
            return variable;
        }
    }
}

int main() {
    double min_number, max_number, step;
    int option, option1, num_of_operation;


    cout << "Enter 0 to use data from base, or 1 to input another values: ";
    option = getValue();

    switch (option)
    {
    case 0:
        min_number = 0.1;
        max_number = 1;
        step = 0.1;
        num_of_operation = 16;

        break;
    case 1:
        cout << "Enter min_number: ";
        min_number = getValue();
        cout << "Enter max_number: ";
        max_number = getValue();
        cout << "Enter num_of_operation: ";
        num_of_operation = getValue();
        cout << "Enter step: ";
        step = getValue();
        cout << endl;
        
        break;
    default:
        cout << "Incorrect input. Calculating standart a,b,h,n\n";
        min_number = 0.1;
        max_number = 1.0;
        step = 0.1;
        num_of_operation = 14;

        break;
    }

    cout << "\nThere are three functions: ";
    cout << "\n1. function = S(x)" << endl;
    cout << "2. function = Y(x)" << endl;
    cout << "3. function = |Y(x) - S(x)|\n" << endl;

    cout << "Please pick one of them functions: ";
    option1 = getValue();

    switch (option1) {
    case 1:
        cout << "\nfunction = S(x):\n\n";
        print(min_number, max_number, step, num_of_operation, S_X);

        break;
    case 2:
        cout << "\nfunction = Y(x)" << endl;
        print(min_number, max_number, step, num_of_operation, Y_X);

        break;
    case 3:
        cout << "\nfunction = Y(x) - S(x)" << endl;
        print(min_number, max_number, step, num_of_operation, func_differ);

        break;
    default:
        cout << "\nRestart and try again !" << endl;
        return 0;
    }
    return 0;
}


double S_X(double min_number, int num_of_operation) {

    double z = 1;
    double sum = 1;
    for (double k = 1; k <= num_of_operation; ++k) {
        z *= min_number / k;
        sum += z * cos(k * M_PI_4);
    }

    return sum;
}

double Y_X(double min_number, int num_of_operation) {
    return cos(min_number * sin(M_PI_4)) * exp(min_number * cos(M_PI_4));
}

double func_differ(double min_number, int num_of_operation) { return fabs(Y_X(min_number, num_of_operation) - S_X(min_number, num_of_operation)); }

void print(double min_number, double max_number, double step, int num_of_operation, double (*ff)(double, int))
{
    for (double x = min_number; x <= max_number; x += step) {
        printf("|x = %f   Y(x) = %14e |\n", x, ff(x, num_of_operation));
    }
}