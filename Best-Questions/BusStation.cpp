/*
Statement:
Given a route in a straight line. N buses operate between various bus stations.There is a workstation at the start of the route. The distances of the 
bus stations from the workstation are calculated. The transportation authority wishes to decrease the number of buses that it operates in the city. 
If any buses are found to have overlapping routes, then these buses will be replaced by a single bus. The authority wishes to determine how many 
buses will remain after the buses with overlapping routes have been eliminated.

Write an algorithm to find how many buses will remain after the buses with overlapping routes have been eliminated.

Input:
The first line of the input consists of two space-separated integers - busStation_row and busStation_col, representing the number of buses running 
on the route(N) and number of bus stations for each bus showing the starting and ending bus stations(M).
The next N lines consist of M space-separated integers representing the distance of the starting and ending bus stations of N buses from the workstation.

Output:
Print an integer representing how many buses will remain after the buses with overlapping routes have been eliminated.

Constraints:
0 <= busStation_row <= 10^5
0 <= busStations[i][0] < busStations[i][1] <= 10^6, busStations are the starting and ending bus stations of a bus.
0 < i < busStation_row

Example 1
Input:
4 2
2 8
6 10
12 14
12 20

Output:
2

Explanation:
The buses running between bus stations [2, 8] and [6, 10] are combined into one.
Similarly, the buses running between bus stations [12, 14] and [12, 20] are combined into one.
So, the total number of buses running on the route are 2.

Example 2
Input:
6 2
10 17
34 42
56 65
100 101
105 110
115 119

Output:
6

Solution:
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int u, w;
        cin >> u >> w;
        v.push_back(make_pair(u, w));
    }
    sort(v.begin(), v.end(), compare);
    stack<pair<int, int>> st;
    for(int i = 0; i < v.size(); i++) {
        st.push(v[i]);
    }
    int count = 0;
    while (!st.empty()) {
        pair<int,int> y = st.top();
        st.pop();
        count++;
        if(y.second >= st.top().first) {
            if(st.size() > 0) {
                st.pop();
            }
        }
    }
    cout << count;
}