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

//https://cses.fi/problemset/task/1092

int main(){
    fastc;

    long long n;
    cin >> n;
    long long sum = n*(n+1)/2;
    if(sum%2 == 1){
        cout << "NO" << endl;
        return 0;
        //cannot split odd num in 2 equal parts
    }
    long long target = sum /2;

    vector<long long> a;
    vector<long long> b;
    long long s1 = 0, s2 = 0;
    ////greedy approach, start from n and keep adding to set a until we reach target, if we exceed target add to set b
    for(long long i = n; i >= 1; i--){
        if(s1+i <= target){
            a.push_back(i);
            s1+=i;
        }
        else{
            b.push_back(i);
            s2+=i;
        }
    }
    cout << "YES" << endl;

    cout << a.size() << endl;
    for(auto num: a) cout << num << " ";
    cout << endl;
    cout << b.size() << endl;
    for(auto num: b) cout << num << " ";



    return 0;
}