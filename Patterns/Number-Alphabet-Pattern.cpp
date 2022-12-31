/*
1 
A B
2 3 4
C D E F
5 6 7 8 9
G H I J K L
10 11 12 13 14 15 16
M  N  O  P  Q  R  S  T
17 18 19 20 21 22 23 24 25
*/

#include <iostream>

using namespace std;

int main()
{
    int n, b = 1, p=1;
    cout << "Enter No. of Lines: ";
    cin >> n;

    // Here b will print numbers and p will handle the printing of characters.
    for (int i = 1; i <= n; i++)
    {
        // If row will of even number then printing the characters
        if (i%2 == 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if(b <= 10)
                    cout << char(64 + p) << " ";
                else
                    cout << char(64 + p) << "  ";
                p++;
            }
        }

        // else printing the numbers in that row
        else
        {
            for (int j = 1; j <= i; j++)
            {
                cout << b << " ";
                b++;
            }
        }

        // Starting a new line
        cout << endl;
    }
    return 0;
}
