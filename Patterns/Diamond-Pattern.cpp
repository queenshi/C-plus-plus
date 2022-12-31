/*
        * 
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Printing Diamond Pattern
    for(int i = 1; i <= 2*n-1; i++) 
    {
        // Upper Triangle
        if(i <= n) {
        for(int j = 0; j < n-i; j++)
            cout << "  ";
        for(int k = 0; k < 2*i -1; k++)
            cout << "* ";
        }

        // Lower Triangle
        else {
        for(int j = 0; j < i-n; j++)
            cout << "  ";
        for(int k = 0; k < 4*n-2*i-1; k++)
            cout << "* ";
        }

        // Starting a new line
        cout << endl;
    }
    return 0;
}
