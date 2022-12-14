/*
Enter a number : 5

Circular Pattern: 
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5 
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter A Number: ";
    cin >> n;

    cout << "\nCircular Pattern: \n";
    for(int i = n; i >= 1; i--) {
        
        for(int j = n; j > i; j--)
            cout << j << " ";
        
        for(int j = 1; j < (i*2); j++)
            cout << i << " ";
        
        for(int j = i+1; j <= n; j++)
            cout << j << " ";
        
        printf("\n");
    }
    for(int i = 1; i < n; i++) {
        
        for(int j = n; j > i; j--)
            cout << j << " ";
        
        for(int j = 1; j < i*2; j++)
            cout << i+1 << " ";
        
        for(int j = i+1; j <= n; j++)
            cout << j << " ";
        
        printf("\n");
    }
    return 0;
}
