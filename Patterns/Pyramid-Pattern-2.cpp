/*
    *
   *A*
  *A*A*
 *A*A*A*
*A*A*A*A*
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
            cout << " ";

        if (i == 1)
            cout << "*";

        else
        {
            for (int k = 1; k <= i-1; k++)
                cout << "*A";

            for (int l = 1; l <= 1; l++)
                cout << "*";
        }

        cout << endl;
    }
    return 0;
}
