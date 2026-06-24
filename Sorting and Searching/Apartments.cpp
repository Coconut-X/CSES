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
using vi = vector<long long>;
using vll = vector<ll>;
#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main(){
    fastc;

    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long>app(n);
    vector<long long> apart(m);
    for(auto &e: app) cin >> e;
    for(auto &e: apart) cin >> e;

    sort(app.begin(), app.end());
    sort(apart.begin(), apart.end());

    //4 3 5
    // 45 60 60 80
    //30 60 75
    int count = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(apart[j] < app[i] - k){
            j++;
        }
        else if (apart[j] > app[i] + k){
            i++;
        }
        else{
            count ++;
            i++;
            j++;
        }
    }   
    cout << count << endl;

    return 0;
}