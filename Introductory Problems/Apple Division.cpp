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

long long method1(vector<long long> &a, long long &total, long long sum1, long long sum2, int index, vector<vector<vector<long long>>>& dp){
    if(index == a.size()){
        return abs(sum1 - sum2);
    }
    //if(dp[index][sum1][sum2] != -1) return dp[index][sum1][sum2];
    //add ai to s1
    long long ais1 = method1(a, total, sum1 + a[index], sum2, index + 1, dp);

    long long ais2 = method1(a, total, sum1,  a[index] + sum2, index + 1, dp);
    
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
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(0,vector<long long>(0,-1))); /// not used

    cout << method1(a, total, 0, 0, 0, dp);

    return 0;
}