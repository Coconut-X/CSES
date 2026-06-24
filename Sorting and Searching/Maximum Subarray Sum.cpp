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

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    //ussing kadanes algorithm
    long long cur = arr[0], res = arr[0];
    for(int i = 1; i < n; i++){
        cur = max(arr[i], cur + arr[i]);
        res = max(res, cur);
    }

    cout << res << endl;

    return 0;
}