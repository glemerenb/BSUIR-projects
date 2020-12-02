#include <iostream>

using namespace std;

int find_max_index(int* array, int length);
int find_min_index(int* array, int length);


int getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        int length;
        cout << " Enter number: ";

        cin >> length;

        // Проверка на предыдущее извлечение
        if (cin.fail()) // если предыдущее извлечение оказалось неудачным
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера         
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n'); // удаляем лишние значения
            return length;
        }
    }
}

int main()
{
    int i;
    int result1;
    int result = 1;
    int* array;
    int max_index, min_index, length;

    cout << "What long array you want to use? " << endl;
    while ((length = getValue()) < 2) { cout << "Array should consists at least of 2 elements."; }

    array = new int[length]; // new operator is used to allocate memory

    for (int i = 0; i < length; i++)
    {
        cout << "Fill the array with numbers " << endl;
        array[i] = getValue();
    }

    for (i = 0; i < length - 1; i++)
        for (int j = i + 1; j < length; j++)
            if (array[i] == array[j]) {
                for (int k = j; k < length - 1; k++)
                    array[k] = array[k + 1];
                length--;
                j--;
            }

    cout << endl << "You have entered:";
    for (int i = 0; i < length; i++) {
        cout << " " << array[i];
    }
    cout << '.' << endl;

    if (length < 2) {
        cout << "We can not calculate out tasks, when array consists of one elements. Please try again";
        return 0;
    }
    if (length < 3) {
        cout << "We can not calculate out tasks, when array consists of two elements. Please try again";
        return 0;
    }

    max_index = find_max_index(array, length);
    min_index = find_min_index(array, length);

    if (min_index != max_index) {
        for (int i = 0; i < length; i++) {
            result *= array[i];
        }

        result1 = result / array[max_index] / array[min_index];

    }
    else {
        cout << "We can't find a product between the same elements. Please, try again!";
        return 0;
    }
    cout << "Result of production is: " << result1 << endl;

    delete[] array;
    return 0;
}

int find_max_index(int* array, int length)
{
    int max_index = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[i] > array[max_index])
        {
            max_index = i;
        }
    }

    cout << endl << "Index of largest element : " << max_index << endl;

    return max_index;
}

int find_min_index(int* array, int length)
{
    int min_index = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[i] < array[min_index])
        {
            min_index = i;
        }
    }

    cout << "Index of smallest element : " << min_index << endl;

    return min_index;
}
