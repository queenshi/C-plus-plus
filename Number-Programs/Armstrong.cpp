#include <iostream>

using namespace std;

int mul(int num1, int t)
{
    int multiply, l;
    multiply = 1;
    for (l = 0; l < t; l++)
    {
        multiply = multiply * num1;
    }
    return multiply;
}

int main() 
{
    int numbers[50], count = 0, n, a;
    cout << "\nEnter A Number: ";
    cin >> n;
    a = n;
    while (a > 0)
    {
        a = a/10;
        count++;
    }
    a = n;
    for (int i = 0; i < count; ++i)
    {
        int temp = a%10;
        numbers[i] = temp;
        a = a/10;
    }
    int sum = 0;
    a = n;
    for (int k = 0; k < count; ++k)
    {
        sum = sum + mul(numbers[k],count);
    }
    if (sum == n)
        cout << endl << n << " is an Armstrong Number.\n\n";
    else
        cout << endl << n << " is not an Armstrong Number.\n\n";
    return 0;
}