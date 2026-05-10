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

//https://cses.fi/problemset/task/1071

void method1(){
    long long x, y;

    cin >> x >> y;

    if(x % 2 == 0){
        //if row is even then the max number in subgrid x by x is x*x present in grid[x][0]
        long long m = x*x;
        if(y<=x){ ///y is inside the subgrid x by x
            ///now in even row moving to right decreases by one for upto x elements
            ///xy will be max - y + 1
            cout << m - y + 1 << endl;
            return;
        }
        else{ // if y is out of the x by x subgrid 
            //x = 4, y = 5
            // we take the bigger subgrid as our main grid and move x units down 
            //max number in subgrid y by y
            
            if(y%2 == 1){
                m = y*y; 
                cout << m - x + 1 << endl;
            }
            else{
                //find max of (y-1) grid, move one place right (+1) and x place down and (-1) for indexing
                m = (y-1)*(y-1) + x ; // -1  +1 cancel out
            }
            return;
        }
    }
    else{// if row is odd
        ///x = 3, 
        if(y<=x){
            //then element at [x][0] is max element in x-1 by x-1 grid + 1
            long long m = (x-1)*(x-1);
            cout << m + 1 + y - 1;
            return;
        }
        if(y%2==1){
            long long m = y*y;
            cout << m - x + 1 << endl;
        }
        else{
            long long m = (y-1)*(y-1) + x ;
            cout << m << endl;
        }
        return;
    }
}


void method1cleaned(){
    long long x, y;
    cin >> x >> y;

    if(x % 2 == 0){
        long long m = x*x;
        if(y<=x){ 
            cout << m - y + 1 << endl;
        }
        else{ 
            if(y%2 == 1){
                m = y*y; 
                cout << m - x + 1 << endl;
            }
            else{
                m = (y-1)*(y-1) + x ; 
                cout << m << endl;
            }
        }
    }
    else{
        if(y<=x){
            long long m = (x-1)*(x-1);
            cout << m + y << endl;
        }
        else if(y%2==1){
            long long m = y*y;
            cout << m - x + 1 << endl;
        }
        else{
            long long m = (y-1)*(y-1) + x ;
            cout << m << endl;
        }
    }
}

void method1Optimal(){
    long long x, y;
    cin >> x >> y;

    long long z = max(x, y);                 //find the current layer
    long long prev_max = (z - 1) * (z - 1);  //max value of the inner grid
    long long current_max = z * z;           //max value of the current grid
    
    long long ans;
    
    if (z % 2 == 0) {
        if (x == z) ans = current_max - y + 1; //bottom edge of the even ring
        else        ans = prev_max + x;        ///right edge of the even ring
    } else {
        if (x == z) ans = prev_max + y;        //bottom edge of the odd ring
        else        ans = current_max - x + 1; //right edge of the odd ring
    }
    
    cout << ans << endl;
}

int main(){
    fastc;
    
    int t;
    cin >> t;
    while(t--){
        method1Optimal();
    }
    
    return 0;
}