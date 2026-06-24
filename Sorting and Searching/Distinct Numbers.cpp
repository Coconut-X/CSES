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
    set<int> unique;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        unique.insert(x);
    }   
    cout << unique.size();

    return 0;
}