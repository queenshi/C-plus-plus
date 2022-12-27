#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter a Number: ";
    cin >> n;
    int m = n*n;
    while (m > 0)
    {
        int temp = m%10;
        sum = sum + temp;
        m = m/10;
    }
    if (sum == n)
        cout << n << " is A Neon Number." << endl;
    else
        cout << n << " is not A Neon Number." << endl;
    return 0;
}
