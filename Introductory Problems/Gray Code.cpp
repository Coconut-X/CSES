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

long long reverseBinary(long long n){
    long long res = 0;
    while(n > 0){
        res <<= 1;
        res |= (n & 1);
        n >>= 1;
    }
    return res;
}

long long appendOne_On_Left(long long toAdd, long long currentNum){
    //current num is the k between 1-n where n was input
    //toAdd is the number we have to add one on its left
    //placing one on left is like adding 2^curentNum to the number
    return toAdd + (1LL << currentNum);
}

vector<long long> mirror(vector<long long> a){
    reverse(a.begin(), a.end());
    return a;
}


int main(){
    fastc;

    long long n;
    cin >> n;
    //                  00, 01, 11, 10
    vector<long long> a = {0,1,3,2}; //initial for 2;

    if(n == 1){
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    if(n == 2){
        
        cout << "00" << endl <<"01" << endl << "11" << endl << "10"<< endl;
        
        return 0;
    }

    for(int i = 3; i <= n; i++){
        vector<long long> b = mirror(a);
        for(long long &x : b){
            x = appendOne_On_Left(x, i-1);
        }
        a.insert(a.end(), b.begin(), b.end());
    }

    //we need to append zeros to the left of the numbers in a to make them n bits long
    for (long long x : a) {
        for (int i = n - 1; i >= 0; i--) {
            if ((x >> i) & 1) cout << '1';
            else cout << '0';
        }
        cout << endl;
    }

    //bit manipulation approach:
    /*Anumber of the form 1<<k has aone bit in position k and all other bits are zero,
    so we can use such numbers to access single bits of numbers. In particular, the
    kth bit of a number is one exactly when x & (1<<k) is not zero. */
    //reference: https://cses.fi/book/book.pdf page 97

    return 0;
}