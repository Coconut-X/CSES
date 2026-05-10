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

//https://cses.fi/problemset/task/1083
//use formula n*n+1/2 to find what the total sum must have been if no number was missing
// subtract the current sum to find missing number

void method1(){
    long long n;
    cin >> n;
    long long mustbe = n*(n+1)/2;
    long long sum = 0;
    for(int i = 0; i < n - 1; i++){ // one less loop because one number missing
        int input;
        cin >> input;
        sum+=input;
    }

    int missing = mustbe - sum;
    cout << missing << endl;
}

//using xor property that a^a = 0 and a^0 = a, we can find the missing number by xoring all the numbers from 1 to n and then xoring all the input numbers, the result will be the missing number because all the other numbers will cancel out each other
void method2(){
    long long n;
    cin >> n;
    int totalXor = 0; //find xor of numbers from 1 -> n
    for(int i = 1; i <= n; i++){
        totalXor ^= i;
    }
    int missingXor = 0;
    for(int i = 0; i < n - 1; i++){
        int input = 0; 
        cin >> input;
        missingXor ^= input;
    }
    //if the number was not missing then the xor of totalXor and missingXor will be 0 because they will have same numbers,
    // but since one number is missing the xor will give us that number because it will not be cancelled out by the same number in totalXor

    long long missing = missingXor ^ totalXor;
    cout << missing << endl; 
}

int main(){
    fastc;

    method2();
    

    return 0;
}