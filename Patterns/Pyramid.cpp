/*
Pyramid

    *
   ***
  *****
 *******
*********
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;

    cout << "Pyramid Pattern" << endl;
    int temp = n;

    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j < temp; j++)
            cout << " ";
        temp--;
    
        for(int k = 1; k <= 2*i - 1; k++)
            cout << "*";
    
        cout << endl;
    }
    return 0;
}
