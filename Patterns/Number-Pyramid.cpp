/*
Number Pyramid

    1
   232
  34543
 4567654
567898765
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;

    cout << "Number Pyramid Pattern" << endl;
    int space = n-1;
    for(int i = 1; i <= n; i++) 
    {
        int num = i;
        for(int j = 1; j <= space; j++)
            cout << " ";
        space--;
    
        for(int k = 1; k <= i; k++, num++)
            cout << num;
        num -= 2;
    
        for(int l = 1; l < i; l++, num--)
            cout << num;
        cout << endl;
    }
    return 0;
}
