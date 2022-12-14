/*
Write the programs of checking the Amicable Numbers.
Ex- (220 & 284) are Amicable numbers.
*/

#include <iostream>

using namespace std;

int main() {
    int a, b, sum1 = 0, sum2 = 0;
    cin >> a >> b;
    
    for(int i = 1; i < a; i++)
    {
        if(a%i == 0) {
            sum1 = sum1 + i;
            cout << i << "  ";
        }
    }
    cout << endl << endl;

    for(int j = 1; j < b; j++)
    {
        if(b%j == 0) {
            sum2 = sum2 + j;
            cout << j << "  ";
        }
    }
    cout << endl << endl;

    if (a == sum2 and b == sum1)
        cout << "\nEntered Numbers are Amicable Numbers\n";
    else
        cout << "\nEntered Numbers are not Amicable Numbers\n";
    return 0;
}
