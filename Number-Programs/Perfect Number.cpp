#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter a Number: ";
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum = sum + i;
    }
    if (sum == n and sum != 0)
        cout << endl << n << " is a Perfect Number.\n" << endl;
    else
        cout << endl << n << " is a not Perfect Number.\n" << endl;
    return 0;
}
