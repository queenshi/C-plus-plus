/*
Numerical Spiral Pattern

 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/

#include <iostream>

using namespace std;

int main() {
    int n,m,l,k=1;
    cout << "Enter The Number of Lines : ";
    cin >> n;

    cout << "\nNumerical Spiral Pattern: " << endl;
    m = (l = n);
    int a[m][n];
    int row = 0, col = 0;
    while(k <= l*l) 
    {
        for(int i = col; i < n; i++)
            a[row][i] = k++;
        row++;
    
        for(int i = row; i < m; i++)
            a[i][n-1] = k++;
        n --;
    
        if(row < m)
            for(int i = n-1; i >= col; i--)
                a[m-1][i] = k++;
        m--;
    
        if(col < n)
            for(int i = m-1; i >= row; i--)
                a[i][col] = k++;
        col++;
    }
    for(int i = 0; i < l; i++) 
    {
        for(int j = 0; j < l; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
