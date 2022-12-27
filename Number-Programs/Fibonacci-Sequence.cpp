#include <iostream>
using namespace std;

int main()
{
  int n, temp = 0, same = 1;
  cout << "Enter a Number: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << temp << ", ";
    cout << same << ", ";
    temp = temp + same;
    same = temp + same;
  }
  return 0;
}
