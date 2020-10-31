#include <iostream>
#include <locale.h>
#include "fraction/fraction.h"
#include "polynomial/polynomial.h"

using namespace mathTools;
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    fraction a2(4, 10);
    fraction b2(1, 4);
    fraction c2;
    cout << "даны дроби:\nA:";
    a2.print();
    cout << "B:";
    b2.print();
    cout  << "A + B = ";
    c2 = a2 + b2;
    c2.print();
    cout << "A - B = ";
    c2 = a2 - b2;
    c2.print();
    cout << "A * B = ";
    c2 = a2 * b2;
    c2.print();
    cout << "A / B = ";
    c2 = a2 / b2;
    c2.print();

    fraction C(6, 4);
    int chislitel;
    int cel = C.divMode(chislitel);
    C.print();
    cout << " = " << cel << " " << chislitel << "/" << C.getDenominator();


    cout << "\n\nДаны полиномы:\nА: ";

    double* m = new double[5];
    m[0] = -2; m[1] = 16; m[2] = 0; m[3] = 15; m[4] = 18;
    polynomial a(5,m);
    a.print();

    cout << "B: ";
    double* m1 = new double[3];
    m1[0] = -2; m1[1] = 1; m1[2] = 2; 
    polynomial b(3, m1);
    polynomial c;
    b.print();
    cout << "B(2) = ";
    cout << b(2) << "\n\n";

    cout << "A / B = ";
    c = a / b;
    c.print();

    cout << "A % B = ";
    c = a % b;
    c.print();

    cout << "A + B = ";
    c = a + b;
    c.print();

    cout << "A - B = ";
    c = a - b;
    c.print();
    
}