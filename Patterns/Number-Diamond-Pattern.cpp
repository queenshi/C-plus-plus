/*
        1 
      1 2 3
    1 2 3 4 5
  1 2 3 4 5 6 7
1 2 3 4 5 6 7 8 9
  1 2 3 4 5 6 7
    1 2 3 4 5
      1 2 3
        1
*/

#include <iostream>

using namespace std;

int main()
{
    int n, a = 2;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= 2*n - 1; i++)
    {
        // Upper Triangle
        if (i <= n)
        {
            for (int k = n-i; k >= 1; k--)
                cout << "  ";
            for (int j = 1; j <= 2*i - 1; j++)
                cout << j << " ";
        }

        // Lower Triangle
        else
        {
            for (int j = 1; j <= i-n; j++)
                cout << "  ";
            for (int k = 1; k <= 2*n-a-1; k++)
                cout << k << " ";
            a = a + 2;
        }

        // Starting a new line
        cout << endl;
    }
    return 0;
}
