#include <iostream>
#include <cmath>

using namespace std;

const double epsilon = 0.5e-8;

double phi_x(double x) {
    double sum = 0;
    double k = 1;
    double phi;

    do {
        phi = 1.0 / (k * (k + x));
        sum += phi;
        k++;
    } while (phi > epsilon);

    return sum;
}

double fast_series(double x, double phi_1) {
    return phi_x(x) - phi_1;
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << "Вычисление ф(x) для x от 0 до 1.0 с шагом 0.1:" << endl;
    for (double i = 0; i <= 1.0; i += 0.1) {
        cout << "ф(" << i << ") = " << phi_x(i) << endl;
    }

    double sum = 0;
    double k = 1;
    double phi;

    do {
        phi = 1.0 / (k * (k + 1));
        sum += phi;
        k++;
    } while (phi > epsilon);

    cout << endl << "Разность ф(x) - ф(1):" << endl;
    for (double i = 0; i <= 1.0; i += 0.1) {
        cout << "ф(" << i << ") - ф(1) = " << fast_series(i, sum) << endl;
    }

    return 0;
}
