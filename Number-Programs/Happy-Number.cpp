#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = true;
    vector<int> a;
    a.push_back(n);
    while(n != 1) {
        int temp = 0;
        while(n > 0) {
            temp += pow(n%10, 2);
            n /= 10;
        }
        if(find(a.begin(), a.end(), temp) != a.end()) {
            flag = false;
            break;
        }
        a.push_back(temp);
        n = temp;
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}