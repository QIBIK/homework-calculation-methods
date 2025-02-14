#include <iostream>
#include <cmath>
using namespace std;


double func(double x) {
    long double phi;
    const double epsilon = 0.5e-8;
    double sum = 0;
    double k = 1;

    do {
        phi = ((1 / k) - (1 / (k + 1)));
        sum += phi;
        k++;
    } while (phi > epsilon);

    return sum;
}

double sum_series(double x) {
    double sum = 0;
    const double epsilon = 0.5e-8;
    double k = 1;
    long double phi;
        
    do {
        phi = 1 / (k * (k + x));
        sum += phi;
        k++;
    } while (phi > epsilon);

    return sum;
}

int main()
{
    setlocale(LC_ALL, "rus");
    for (double i = 0; i <= 1.0; i += 0.1) {
        cout << i << ") " << sum_series(i) << endl;
    }

    cout << "Разность: " << sum_series(1) - func(1);

    return 0;
}
