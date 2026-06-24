#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <list>
#include <climits>
#include <sstream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'


/*
DRY RUN (CSES Sample Input):
Input: 
3
5 8
2 4
3 9

1. After Populating allTimes (unordered):
   [{5, 1}, {8, -1}, {2, 1}, {4, -1}, {3, 1}, {9, -1}]

2. After sort(allTimes.begin(), allTimes.end()):
   [{2,  1},  // Cust 2 enters
    {3,  1},  // Cust 3 enters
    {4, -1},  // Cust 2 leaves
    {5,  1},  // Cust 1 enters
    {8, -1},  // Cust 1 leaves
    {9, -1}]  // Cust 3 leaves

3. Loop Execution:
   i = 0 | time = 2 | change =  1 | cur = 1 | res = max(0, 1) = 1
   i = 1 | time = 3 | change =  1 | cur = 2 | res = max(1, 2) = 2  <- Peak
   i = 2 | time = 4 | change = -1 | cur = 1 | res = max(2, 1) = 2
   i = 3 | time = 5 | change =  1 | cur = 2 | res = max(2, 2) = 2
   i = 4 | time = 8 | change = -1 | cur = 1 | res = max(2, 1) = 2
   i = 5 | time = 9 | change = -1 | cur = 0 | res = max(2, 0) = 2

Output: 2
*/


int main(){
    fastc;
    //Problem: given start and end or time for arrival of person, tell max number or people in the shop at any time
    int n;
    cin >> n;
    
    vector<pair<int,int>> allTimes;
    //for entering we use +1 and for leaving event we use -1
    //we place all start,end in single array and then sort them chronologically then find max running peak
    
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        allTimes.push_back({start,1});
        allTimes.push_back({end,-1});
    }
    sort(allTimes.begin(), allTimes.end());

    int res = 0, cur = 0;
    for(int i = 0; i < 2*n; i++){
        cur+=allTimes[i].second;
        res = max(res,cur);
    }

    cout << res;

    return 0;
}