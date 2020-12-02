#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int option1;
	double x, z, a, c, summand1, summand2, summand3, Result, function;

	cout << "Please enter z: ";
	cin >> z;
	cout << " \nPlease enter c: ";
	cin >> c;
	cout << " \nPlease enter a: ";
	cin >> a;

	if (z <= 1) {
		x = pow(z, 2) + 1;
	}
	else {
		x = 1 / sqrt(z - 1);
	}

	cout << "\nThere are three functions: ";
	cout << "\n1. function = 2 * x" << endl;
	cout << "2. function = pow(x, 2)" << endl;
	cout << "3. function = x / 3\n" << endl;

	cout << "Please pick one of them functions: ";
	cin >> option1;

	switch (option1)
	{
	case 1:
		function = 2 * x;
		cout << "\nfunction = 2 * x" << endl;
		break;
	case 2:
		function = pow(x, 2);
		cout <<"\nfunction = pow(x, 2)" << endl;
		break;
	case 3:
		function = x / 3;
		cout << "\nfunction = x / 3" << endl;
		break;
	default:
		cout << "\nRestart and try again !" << endl;
		return 0;
	}

	summand1 = a * log(fabs(x));
	summand2 = exp(x);
	summand3 = c * pow(sin(pow(function,2) - 1), 3);

	Result = summand1 + summand2 + summand3;
	cout << "\nResult is: " << Result << "\n";

	return 0;
}
