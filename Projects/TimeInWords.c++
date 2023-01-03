#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string dict(int n) {
    map<int, string> m = {{0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, 
                        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, 
                        {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {16, "sixteen"}, {17, "seventeen"}, 
                        {18, "eighteen"}, {19, "ninteen"}, {20, "twenty"}, {21, "twenty one"}, {22, "twenty two"}, 
                        {23, "twenty three"}, {24, "twenty four"}, {25, "twenty five"}, {26, "twenty six"}, 
                        {27, "twenty seven"}, {28, "twenty eight"}, {29, "twenty nine"}};

    return m[n];
}

string timeInWords(int h, int m) {
    string ans;
    if(m == 0) {
        string temp = dict(h);
        string a = " o' clock";
        ans = temp + a;
    }
    else if(m <= 30) {
        string temp = dict(h), a;
        if(m == 1)
            a = "one minute past ";
        else if(m == 15)
            a = "quarter past ";
        else if(m == 30)
            a = "half past ";
        else {
            string no = dict(m);
            a = " minutes past ";
            a = no + a;
        }
        ans = a + temp;
    }
    else {
        string temp = dict(h+1), a;
        if(h == 12)
            temp = dict(1);
        if(m == 45)
            a = "quarter to ";
        else if(m == 59)
            a = "one minute to ";
        else {
            string no = dict(60-m);
            a = " minutes to ";
            a = no + a;
        }
        ans = a + temp;
    }
    return ans;
}

int main() {
    int h, m;
    cout << "Enter Hours: ";
    cin >> h;
    cout << "Enter Minutes: ";
    cin >> m;
    string result = timeInWords(h, m);
    cout << result << endl;
    return 0;
}
