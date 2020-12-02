#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	double x, y, z, a, b, c, d, avraam, Result;

	cout << " Please enter x = ";
	cin >> x;
	cout << " Please enter y = ";
	cin >> y;
	cout << " Please enter z = ";
	cin >> z;

	a = pow(y, x + 1);
	b = cbrt(fabs(y - 2)) + 3;
	c = x + y / 2;
	d = 2 * fabs(x + y);
	avraam = pow(x + 1, -1 / sin(z));

	Result = (a / b) + (c * avraam / d);

	cout << " Result = " << Result << endl;

	return 0;
}

