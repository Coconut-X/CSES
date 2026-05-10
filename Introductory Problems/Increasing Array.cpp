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

//https://cses.fi/problemset/task/1094
//single pass
int main(){
    fastc;

    int n;
    cin >> n;

    vector<long long> a(n);
    for(auto &num: a) cin >> num;

    long long moves = 0;

    for(int i = 1; i < n; i++){
        long long difference = a[i-1] - a[i];
        if(difference > 0){
            moves += difference;
            a[i] += difference;  //or a[i] = a[i - 1]
        }
    }
    cout << moves << endl;


    return 0;
}