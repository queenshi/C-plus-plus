/*
        1
      2 2 2
    3 3 3 3 3
  4 4 4 4 4 4 4
5 5 5 5 5 5 5 5 5
  4 4 4 4 4 4 4
    3 3 3 3 3
      2 2 2
        1
*/

#include <iostream>

using namespace std;

int main()
{
  int n, a = 1;
  cout << "Enter a number: ";
  cin >> n;

  // Treat i as No. of Rows, j as No. of Spaces, and k as Digits that to be printed.
  for(int i = 1; i <= 2*n-1; i++) {

    // Upper Triangle
    if(i <= n) {
      for(int j = 0; j < n-i; j++)
        cout << "  ";
      for(int k = 0; k < 2*i -1; k++)
        cout << a << " ";
      a++;
    }

    // Lower Triangle
    else {
      a--;
      for(int j = 0; j < i-n; j++)
        cout << "  ";
      for(int k = 0; k < 4*n-2*i-1; k++)
        cout << a-1 << " ";
    }

    // Starting a new line
    cout << endl;
  }
  return 0;
}