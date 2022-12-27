#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() 
{
    float a, b, c, r1, r2;
    double temp, d, e;

    cout << "Enter the value of a = ";
    cin >> a;
    cout << endl << "Enter the value of b = ";
    cin >> b;
    cout << endl << "Enter the value of c = ";
    cin >> c;

    d = (b*b)-(4*a*c);

    if (d >= 0) {
        cout << "\nDiscriminant is positive. So, Roots are real." << endl << endl;
        e = sqrt(d);
        r1 = (-b+e)/(2*a);
        r2 = (-b-e)/(2*a);
        cout << "Roots of the equation are: " << r1 << " and " << r2 << endl;
    }
    else {
        cout << "\nDiscriminant is negative. So, Roots are imaginary." << endl << endl;
        temp = -d;
        e = sqrt(temp);
        float real = (-b)/(2*a);
        float imag = e/(2*a);
        cout << "Roots of the equation are: (" << real << " + " << imag << "i) and (" << real << " - " << imag << "i)" << endl;
    }
    return 0;
}
