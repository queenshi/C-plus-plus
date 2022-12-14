/*
Floyd's Triangle

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

#include <iostream>

using namespace std;

int main() {
    int n, a = 1;
    cout << "Enter the number of lines : ";
    cin >> n;

    cout << "\nFloyd's Triangle " << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++) 
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }
    return 0;
}
