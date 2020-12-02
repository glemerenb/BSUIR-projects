#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;


int find_min_index(int** matrix, int row, int column);
int find_max_index(int** matrix, int row, int column);
void print_matrix(int** matrix, int row, int column);
int getValue();

int main() {
    srand(time(0));

    int** matrix;
    int i, j, row, column;
    int chose_input;
    int min_index_i;
    int max_index_i;

    cout << "How many lines do you want to have?\n"
        << "Enter a number: ";
    while ((row = getValue()) < 2) { 
        cout << "To perform our task, we must use no less than 1 elements in the matrix width.\nEnter number: "; 
    }

    cout << "How many columns do you want to have?\n"
        << "Enter a number: ";
    while ((column = getValue()) < 2) { cout << "To perform our task, we must use no less than 1 elements in the matrix length.\nEnter number: "; }

    matrix = new int* [row];

    for (i = 0; i < row; ++i)
        matrix[i] = new int[column];

    cout << "Enter 0 to use random number or ELSE to input numbers: ";
    chose_input = getValue();

    if (chose_input == 0) {
        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                matrix[i][j] = rand() % 100 - 50;
            }
        }
        print_matrix(matrix, row, column);
    } else {
        cout << "\nLet's fill our array with numbers: \n";

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                cout << "\np[" << i << "][" << j << "] = ";
                matrix[i][j] = getValue();
            }
        }
        print_matrix(matrix, row, column);
    }



    min_index_i = find_min_index(matrix, row, column);
    max_index_i = find_max_index(matrix, row, column);

    if (min_index_i != max_index_i) {     
    //    for (int j = 0; j < column; j++) {     
            int *temp = matrix[min_index_i];
            matrix[min_index_i] = matrix[max_index_i];
            matrix[max_index_i] = temp;
   //     }
    }
    else {
        cout << "\nSince the minimum and maximum elements are on the same line, we cannot perform our original task. Please, try again.\n";
        return 0;
    }

    cout << "\nReplace the row with the largest element by the row with the smallest element.\n";

    print_matrix(matrix, row, column);

    for (i = 0; i < row; ++i)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}

int getValue()
{
    while (true) // the cycle continues until the user enters the correct value
    {
        int length;
        cin >> length;

        // check for previous extraction
        if (cin.fail()) // if the previous extraction was unsuccessful
        {
            cin.clear(); // then we return "cin" to the normal operation mode.
            cin.ignore(32767, '\n'); // and delete previous input values from the input buffer.         
            cout << "Oops, that input is invalid.  Please try again.\n";
            cout << "Enter a number: ";
        }
        else
        {
            cin.ignore(32767, '\n'); // delete unnecessary values
            return length;
        }
    }
}

void print_matrix(int** p, int row, int column)
{
    cout << endl << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << p[i][j] << "  ";
        }
        cout << endl << endl;
    }
}


int find_min_index(int** p, int row, int column) {
    int min_index_i = 0;
    int min_index_j = 0;
    int min = p[0][0];

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j)
            if (p[i][j] < min)
            {
                min = p[i][j];
                min_index_i = i;
                min_index_j = j;
            }
    }

    cout << "\nMin element = " << min;
    cout << "  Min index = [" << min_index_i << "][" << min_index_j << "]" << endl;

    return min_index_i;
}

int find_max_index(int** p, int row, int column) {
    int max_index_i = 0;
    int max_index_j = 0;
    int max = p[0][0];

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j)
            if (p[i][j] > max)
            {
                max = p[i][j];
                max_index_i = i;
                max_index_j = j;
            }
    }

    cout << "\nMax element = " << max;
    cout << "  Max index = [" << max_index_i << "][" << max_index_j << "]" << endl;

    return max_index_i;
}
