#include <iostream>

using namespace std;

int main()
{
    int n, a, sum = 0;
    cout << "Enter a Number: ";
    cin >> n;
    a = n;
    while (n > 0)
    {
        int temp = n%10;
        sum = sum + temp;
        n = n/10;
    }
    if (a%sum == 0)
        cout << endl << a << " is a Niven Number or Harshad Number.\n" << endl;
    else
        cout << endl << a << " is not a Niven Number or Harshad Number.\n" << endl;
    return 0;
}
