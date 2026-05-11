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

//https://cses.fi/problemset/task/1618

//proof
//number of trailing zeroes in n! is equal to the number of times 10 is a factor in the numbers from 1 to n
//10 is made of 2 and 5, and there are usually more factors of 2 than 5 in a factorial, so we can just count the number of factors of 5 in the numbers from 1 to n
//to count the number of factors of 5 in n!, we can count the number of multiples of 5, then the number of multiples of 25 (because they contribute an extra factor of 5), then the number of multiples of 125, and so on until we exceed n

int main(){
    fastc;

    long long n;
    cin >> n;

    long long count = 0;
    
    for(long long i = 5; n/i>=1; i*=5){
        count += n/i;
    }

    cout << count << endl;

    return 0;
}