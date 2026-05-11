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

//https://cses.fi/problemset/task/1754

void method1(){
    
    long long a, b;
    cin >> a >> b;

    // at each move we remove a total of 3 coins, so the total number of coins must be divisible by 3
    if((a+b)%3 != 0){
        cout << "NO" << endl;
        return;
    }

    //we can only remove 2 coins from one pile and 1 coin from the other pile
    //so the number of coins in one pile cannot be more than twice the number of coins in the other pile
    
    if(2*a >= b and 2*b >= a){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

void method1Cleaned(){
    long long a, b;
    cin >> a >> b;

    if((a+b)%3 == 0 and 2*a >= b and 2*b >= a){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

//important note/technique
// a number is divisible by 3 if the sum of its digits is divisible by 3
//not used here but just for info

int main(){
    fastc;

    int t;
    cin >> t;
    while (t--)
    {
        method1Cleaned();
    }
    


    return 0;
}