#include <iostream>

using namespace std;

int main()
{
    int n, countx = 0;
    cout << "Enter a Number: ";
    cin >> n;

    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (n%i == 0)
                countx++;
        }
    }
    else
        cout << "\nYou have entered either a negative number or zero." << endl;


    if (countx == 2)
        cout << "\nEntered number is a prime number." << endl;
    else
        cout << "\nEntered number is not a prime number." << endl;

    return 0;
}
