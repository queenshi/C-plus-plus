#include <iostream>

using namespace std;

int main()
{
    int a, b, c, choice, l, largest;
    cout << "Enter 3 Numbers: ";
    cin >> a >> b >> c;
    cout << "<=====Which method you want to apply=====>\n";
    cout << ": 1. Using Ternary Operator\n";
    cout << ": 2. Using If-else Method\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        l = (a > b)? a : b;
        largest = (l > c)? l : c;
        cout << "\nLargest Number Among 3 Numbers is " << largest << endl << endl;
        break;
    case 2:
        if(a > b)
        {
            if(a > c)
                cout << a << " is Largest number." << endl;
            else if (c > b)
                cout << c << " is Largest number." << endl;
            else
                cout << b << " is Largest number." << endl;
        }
        else
        {
            if (b > c)
                cout << b << " is Largest number." << endl;
            else if (c > a)
                cout << c << " is Largest number." << endl;
            else
                cout << a << " is Largest number." << endl;
        }
        break;
    default:
        cout << "Enter Wrong Choice!!\n";
    }
    return 0;
}
