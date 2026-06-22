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

int processQuery(long long k){
    //1-9 -> 9
    //10-99 ->90
    long long digits = 1;
    long long l = 1, r = 9;
    long long index = 1;
    long long curdigit = 1;
    while(true){
        long long range = r - l + 1;
        
        if (digits * range >= k) {
            long long actual_num = l + (k - 1) / digits;
            string s = to_string(actual_num);
            char c = s[(k - 1) % digits];
            return c - '0';
        } 
        else {
            k -= digits * range;
            l *= 10;
            r = r * 10 + 9;
            digits++;
        }
    }
}


int main(){
    fastc;

    int q;
    cin >> q;
    while(q--){
        long long k;
        cin >> k;
        cout << processQuery(k) << endl;
    }

    return 0;
}