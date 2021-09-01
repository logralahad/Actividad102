// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <random>
#define lln long long int

using namespace std;
//hacia adelante
void esquema_explicito(double r0, double delta_t) {
    vector<double> y_(5);
    y_[0] = r0;

    for (int i = 0; i < 4; i++)
    {
        double rn = y_[i];
        y_[i + 1] = rn + (delta_t * (1 + (4 * rn)));
    }

    printf("   Y0: %1.8f   |   Y1: %1.8f   |   Y2: %1.8f   |   Y3: %1.8f\n",
        y_[0], y_[1], y_[2], y_[3]);
}

//hacia atras
void esquema_implicito(double r0, double delta_t) {
    vector<double> z_(5);
    z_[0] = r0;

    for (int i = 0; i < 4; i++)
    {
        double zn = z_[i];
        double numerador = (-1 * zn) + (-1 * delta_t);
        double denominador = (4 * delta_t) - 1;

        z_[i + 1] = numerador / denominador;
    }

    printf("   Z0: %1.8f   |   Z1: %1.8f   |   Z2: %1.8f   |   Z3: %1.8f\n",
        z_[0], z_[1], z_[2], z_[3]);
}

int main()
{
    double delta_t = (double)1 / (double)10;
    double valor_real = 0.1229561744;
    double valor_real2 = 0.3063852321;
    double valor_real3 = 0.5800292307;
    printf("   t: %1.8f   |   rt: %1.8f   |   r2t: %1.8f   |   r3t: %1.8f\n",
        delta_t, valor_real, valor_real2, valor_real3);

    int n = 10;
    double r0 = 0;
    esquema_explicito(r0, delta_t);
    esquema_implicito(r0, delta_t);

}
    
    
/*
//hacia adelante
void esquema_explicito(double r0, double delta_t) {
    vector<double> y_(5);
    y_[0] = r0;

    for (int i = 0; i < 4; i++)
    {
        double rn = y_[i];
        y_[i + 1] = rn + (delta_t * (1 - (4 * rn)));
    }

    printf("   Y0: %1.8f   |   Y1: %1.8f   |   Y2: %1.8f   |   Y3: %1.8f\n",
        y_[0], y_[1], y_[2], y_[3]);
}

//hacia atras
void esquema_implicito(double r0, double delta_t) {
    vector<double> z_(5);
    z_[0] = r0;

    for (int i = 0; i < 4; i++)
    {
        double zn = z_[i];
        double numerador = (-1 * zn) - (-1 * delta_t);
        double denominador = (4 * delta_t) - 1;

        z_[i + 1] = numerador / denominador;
    }

    printf("   Z0: %1.8f   |   Z1: %1.8f   |   Z2: %1.8f   |   Z3: %1.8f\n",
        z_[0], z_[1], z_[2], z_[3]);
}

int main()
{
    double delta_t = (double)1 / (double)10;
    double valor_real = 0.1229561744;
    double valor_real2 = 0.3063852321;
    double valor_real3 = 0.5800292307;
    printf("   t: %1.8f   |   rt: %1.8f   |   r2t: %1.8f   |   r3t: %1.8f\n",
        delta_t, valor_real, valor_real2, valor_real3);

    int n = 10;
    double r0 = 0;
    esquema_explicito(r0, delta_t);
    esquema_implicito(r0, delta_t);

}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
