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

int main(){
    fastc;

    ///easy problem but learnt something
    ///on other platforms the unordered_map solutions is acceptable but gives tle on csses cases
    //unordered map is O(1) on average but worst case is O(n), so we can use map instead of unordered_map, which is O(logn) in worst case scenario
    //map is self balancing red black tree, so it is always O(logn) in worst case scenario
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, pair<int,int>> mep;
    for(int i = 0; i < n; i++){
        if(mep.find(arr[i]) == mep.end()){
            mep[t - arr[i]] = {arr[i],i};
        }
        else{
            cout << mep[arr[i]].second + 1 << " " << i + 1 << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}