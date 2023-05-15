#include <bits/stdc++.h>
using namespace std;

vector<string> digit = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

vector<string> denominations = {"", "Thousand", "Million", "Billion", "Trillion"};

vector<string> tens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

vector<string> ties = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string input;

string add(const string &s1, const string &s2) {
    if(s1.size() && s2.size())
        return s1 + " " + s2;
    return s1 + s2;
}

string convert(int idx, int level) {
    if(idx >= (int)input.size())
        return "";
    string cur = "";
    int od, td, hd;
    od = int(input[idx] - '0'), td = int(input[idx + 1] - '0'), hd = int(input[idx + 2] - '0');
    if(hd) cur = add(cur, add(digit[hd], "Hundred"));
    if(td) {
        if(td == 1) cur = add(cur, tens[od]);
        else {
            cur = add(cur, ties[td - 1]);
            if(od) cur = add(cur, digit[od]);
        }
    }
    else if(od) cur = add(cur, digit[od]);
    if(cur != "") cur = add(cur, denominations[level]);
    return add(convert(idx + 3, level + 1), cur);
}

int main() {
    cout << "Enter Number : ";
    cin >> input;
    while ((int)input.size() % 3 != 0)
        input = "0" + input;
    reverse(input.begin(), input.end());
    cout << "In Words : ";
    if(input == "000") cout << "Zero" << endl;
    else cout << convert(0, 0) << endl;
    return 0;
}
