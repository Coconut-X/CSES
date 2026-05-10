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

//https://cses.fi/problemset/task/1069
// two pointer, sliding window, line sweep

int main(){
    fastc;

    string s;
    cin >> s;
    int maxLen = 1;
    int curlen = 1;

    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]) curlen++;
        else maxLen = max(maxLen, curlen), curlen = 1;
    }
    //if loop was exited due to i == s.size() and curlen > maxLen, it will never be updated inside the loop
    //thats why take max again outside
    cout << max(maxLen, curlen) << endl; 


    return 0;
}