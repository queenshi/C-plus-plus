#include <iostream>

using namespace std;

int main()
{
    int n;
    double mul=1;
    cout << "Enter a Number: ";
    cin >> n;
    for (int j= 1; j<= n; j++)
    {
        if (j >= 1)
            mul = mul*j;
        else
            mul = mul*1;
    }
    cout << endl;
    cout << "Factorial of " << n << " is " << mul << endl << endl;
    return 0;
}
