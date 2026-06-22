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

int main(){
    fastc;

    int n, m;
    cin >> n >> m;

    vector<string>grid;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        grid.push_back(s);
    }
    //greedy approach
    //for each element we have valid switches = {A,B,C,D} - current element - top element - left element



    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            set<char> move = {'A','B','C','D'};
            char top = '-';
            char left = '-';
            if(i > 0){
                top = grid[i-1][j];
            }
            if(j > 0) left = grid[i][j-1];
            move.erase(top);
            move.erase(grid[i][j]);
            move.erase(left);
            char can = *move.begin();
            grid[i][j] = can;
            cout << grid[i][j];
        }
        cout << endl;
    }



    return 0;
}