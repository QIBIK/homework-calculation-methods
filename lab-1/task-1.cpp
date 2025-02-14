#include <iostream>
#include <cmath>
using namespace std;


long int factorial(int x) {
	long long res = 1;
	if (x > 16) {
		x = 16;
	}
	for (int i = 1; i <= x; i++) {
		res *= i;
	}
	return res;
}

long double erf(double x, int n) {
	const long double c = 2 / sqrt(3.14159265358979323846264338);
	long double result = 0;

	for (int i = 0; i <= n; i++) {
		result += (pow(-1, i) * pow(x, 2 * i + 1)) / ((factorial(i)) * (2 * i + 1));
	}

	return c * result;
}

int main()
{
	double n = 10;

	double x1 = 0.5;
	double x2 = 1.0;
	double x3 = 1.5;

	cout << "erf(0.5): " << erf(x1, n) << endl
		<< "erf(1.0): " << erf(x2, n) << endl
		<< "erf(1.5): " << erf(x3, n) << endl;

	cout << endl << erf(x1)
		<< endl << erf(x2)
		<< endl << erf(x3);


	return 0;
}