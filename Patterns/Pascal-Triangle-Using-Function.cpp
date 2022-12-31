/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/

#include <iostream>

using namespace std;

long fact (int num)
{
    long f = 1;
    int i = 1;

    while (i <= num)
    {
        f = f*i;
        i++;
    }

    return f;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i= 1; i < n; i++)
    {
        if (i == 1)
        {
            for (int j = 1; j <= n-1; j++)
                cout << " ";
            cout << " 1" << endl;
        }

        for (int a = 1; a <= n-i; a++)
            cout << " ";

        for (int j = 0; j <= i; j++)
            cout << fact(i)/(fact(j)*fact(i - j)) << " ";

        cout << endl;
    }
    return 0;
}
