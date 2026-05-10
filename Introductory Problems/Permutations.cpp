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

//https://cses.fi/problemset/task/1070

int main(){
    fastc;

    int n;

    ///print all odd numbers from 1 to n, then all even numbers from 1 to n
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    if(n == 2 or n == 3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    ///print evens first and then odds
    ///if we print odds first we will have to hardcode only one test case of n = 4
    //priting odd first will result in 1 3 2 4 which is not a valid solution because 3 and 2 are adjacent
    //if we print even first we will have 2 4 1 3 which is a valid solution 

    //print even numbers first
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
    //print odd numbers next
    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }

    return 0;
}