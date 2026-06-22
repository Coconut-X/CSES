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

bool v[7][7];

//NOTE: in any problem if size of board is fixed, always use static arrays instead of dynamic ones, as they are faster and dont require heap memory allocation.
//theres a reason why they fix the grid size, theres always a catch!

int brute(string &s, int i, int j,int index){
    if(i < 0 or j < 0 or i > 6 or j > 6 or v[i][j]) return 0;
    if(i == 6 && j == 0) return index == 48;
    if(index == 48) return 0; //took 48 steps but didnt reach goal  
    
    // ------------------- OPTIMIZATION 1: WALL/PATH SPLITTING -------------------
    // Case A: Hit top/bottom wall or a vertical path, but left & right are empty
    if ((i == 0 || i == 6 || (v[i-1][j] && v[i+1][j])) && j > 0 && j < 6 && !v[i][j-1] && !v[i][j+1]) 
    return 0;
    
    // Case B: Hit left/right wall or a horizontal path, but up & down are empty
    if ((j == 0 || j == 6 || (v[i][j-1] && v[i][j+1])) && i > 0 && i < 6 && !v[i-1][j] && !v[i+1][j]) 
    return 0;
    // ---------------------------------------------------------------------------
    v[i][j] = true;

    int res = 0;
    
    if(s[index] == '?'){
        res =  brute(s,i, j+1, index + 1) + brute(s,i+1, j, index + 1) + brute(s,i, j-1, index + 1) + brute(s, i - 1, j, index + 1);
    }
    else if(s[index] == 'L'){
        res = brute(s,i,j-1,index+1);
    }
    else if(s[index] == 'R'){
        res = brute(s,i,j+1,index+1);
    }
    else if(s[index] == 'U'){
        res = brute(s,i-1,j,index+1);
    }
    else if(s[index] == 'D'){
        res = brute(s,i+1,j,index+1);
    }
    
    v[i][j] = false;

    return res;
}

int main(){
    fastc;
    
    string s;
    cin >> s;
    memset(v, false, sizeof(v));
    cout<<brute(s,0,0,0);

    return 0;
}