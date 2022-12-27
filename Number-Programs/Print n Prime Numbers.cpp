#include <iostream>

using namespace std;

int main()
{
    int flag, n, countx = 0;
    cout << "Enter a Number: ";
    cin >> n;

    for(int i=2; i<=n; i++)
    {
        flag=1;
        for(int j=2; j<=i/2; j++)
        {
            if(i%j == 0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}
