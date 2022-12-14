/*
HourGlass Pattern

* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
*/

#include <iostream>

using namespace std;

int main() {

    int num, n, r, c, sp;
    cout << "Enter The Number of Lines : ";
    cin >> num;

    cout << "HourGlass Pattern" << endl;
    n = num;
    for (r = 1; r <= num; r++) {

        for (sp = 1; sp <= r; sp++)
            cout << " ";

        for (c = 1; c <= n; c++)
            cout << "*";

        for (c = num - r; c >= 1; c--)
            cout << "*";
        n--;

        cout << endl;
    }
    for (r = 2; r <= num; r++) {

        for (sp = num - r + 1; sp >= 1; sp--)
            cout << " ";

        for (c = 1; c <= r; c++)
            cout << "*";

        for (c = r - 1; c >= 1; c--)
            cout << "*";

        cout << endl;
    }
    return 0;
}
