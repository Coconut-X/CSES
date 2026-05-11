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

//https://cses.fi/problemset/task/1755

int main(){
    fastc;
    string s;
    cin >> s;

    int n = s.size();

    set<char> chars;
    unordered_map<char, int> charCount;

    for(char c : s){
        charCount[c]++;
        chars.insert(c);
    }

    int oddcount = 0;
    char odd = '-';
    int f = 0;
    for(auto &e: chars){
        if(charCount[e]%2 == 1){
            oddcount++;
            odd = e;
            f = charCount[e];   
            charCount[e] = 0;
        }
        if(oddcount == 2){
            cout << "NO SOLUTION" <<endl;
            return 0;
        }
    }

    string ns = "";
    for(char e: chars){
        ns.append(charCount[e] / 2, e);
    }
    string nexthalf = ns;
    reverse(nexthalf.begin(), nexthalf.end());

    if(odd != '-'){
        ns.append(f, odd);
    }
    ns+=nexthalf;
    cout << ns << endl;

    return 0;
}