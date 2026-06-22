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

long long method1(vector<long long> &a, long long &total, long long sum1, long long sum2, int index){
    if(index == a.size()) return abs(sum1 - sum2);
    //since every element must be used, put it either in first stack or second one
    long long ais1 = method1(a, total, sum1 + a[index], sum2, index + 1);
    long long ais2 = method1(a, total, sum1,  a[index] + sum2, index + 1);
    return min(ais1, ais2);
}

int main(){
    fastc;

    long long n;
    long long total = 0;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    cout << method1(a, total, 0, 0, 0);

    return 0;
}