#include <iostream>

using namespace std;

int main()
{
    int n, a, rev = 0;
    cout << "Enter a Number: ";
    cin >> n;
    a = n;
    while(a > 0)
    {
        rev = rev*10;
        rev = rev + a%10;
        a = a/10;
    }
    if (n == rev)
        cout << endl << n << " is Palindrome.\n" << endl;
    else
        cout << endl << n << " is not Palindrome.\n" << endl;
    return 0;
}
