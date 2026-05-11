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

///https://cses.fi/problemset/task/1617

int main(){
    fastc;

    long long mod = 1e9 + 7;
    long long n;
    cin >> n;
    //dont use pow function because it uses double and can cause precision issues, use fast exponentiation instead
    //also pow can give overflow for large n because it wont take mod at each step
    //so we will use fast exponentiation to calculate (2^n) % mod
    long long result = 1;
    for(long long i = 0; i < n; i++){
        result = (result * 2) % mod;
    }
    cout << result << endl;

    return 0;
}