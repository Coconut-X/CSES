#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

//https://cses.fi/problemset/task/1068z
//simulation problem

int main(){
    fastc;

    long long n;
    cin >> n;

    while(n!=1){
        cout << n << " ";
        if(n&1) n*=3, n++;
        else n >>= 1;
    }
    cout << n << " ";


    return 0;
}