/*
Pascal's Triangle

    1
   121
  12321
 1234321
123454321
*/

#include <iostream>

using namespace std;

int main() {
    int n, c, k, number = 1;
    cout << "Enter The Number of Lines : ";
    cin >> n;

    cout << "Pascal's Triangle" << endl;
    for(int i = 0;  i < n; i++) 
    {
        for(int j = 0; j < n-i-1; j++)
            cout << " ";
    
        for(int k = 0; k <= i; k++)
            cout << k+1;
    
        for(int l = i; l > 0; l--)
            cout << l;
    
        cout << endl;
    }
    return 0;
}
