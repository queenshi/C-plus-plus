/*
       *
     *   *
   *       *
 *           *
   *       *
     *   *
       *
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Making Hollow Diamond or Outline of a Diamond
    for (int i = 1; i <= 2*n -1; i++)
    {
        // Upper Triangle
        if (i <= n)
        {
            for (int j = n-i; j >= 1; j--)
                cout << "  ";
            for (int k = 1; k <= 2*i - 1; k++)
            {
                if(k == 1 or k == 2*i - 1)
                    cout << "* ";
                else
                    cout << "  ";
            }
        }

        // Lower Triangle
        else
        {
            for (int j = 1; j <= i-n; j++)
                cout << "  ";
            for (int k = 4*n-2*i-1; k >= 1; k--)
            {
                if(k == 1 or k == 4*n-2*i-1)
                    cout << "* ";
                else
                    cout << "  ";
            }
        }

        // Starting New line
        cout << endl;
    }
    return 0;
}
