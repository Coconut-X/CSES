#include <iostream>
#include <string>
#include <vector>
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


int counter = 0;

bool canPlace(unordered_map<int, bool>&row,unordered_map<int, bool>&diag, unordered_map<int,bool>&antiDiag, int i, int j, int n, int m){
    if(row[i] or diag[i+j] or antiDiag[i - j + 7]) return false;
    return true;
}


void brute(vector<vector<char>>&grid, int used, unordered_map<int, bool>&row, unordered_map<int,bool>&col, unordered_map<int,bool>&diag,unordered_map<int,bool>&antiDiag, int index){
    
    if(used == 8){
        counter++;
        return;
    }
    if(index == grid[0].size()) return;

    //place current index in diff rows
    for(int i = 0; i < grid[index].size(); i++){
        if(grid[i][index] != '*' and canPlace(row, diag, antiDiag, i, index, grid.size(), grid[0].size())){
            row[i] = true;
            col[i] = true;
            diag[i+index] = true; //for each diagonal the sum or row+col index is always same and unique for that diagonal
            antiDiag[i - index + 7] = true;

            brute(grid, used + 1, row, col, diag, antiDiag, index + 1);

            row[i] = false;
            col[i] = false;
            diag[i+index] = false;
            antiDiag[i - index + 7] = false; //row - col + n is same and unique for each antidiagonal

        }
    }

}

int main(){
    fastc;

    vector<vector<char>>grid(8,vector<char>(8,'.'));
    // unordered_map<pair<int,int>, bool, pair_hash> reserved;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> grid[i][j];
            // reserved[{i,j}] = grid[i][j] == '*';
        }
    }
    unordered_map<int, bool>row;
    unordered_map<int,bool>col; 
    unordered_map<int,bool>diag;
    unordered_map<int,bool>antiDiag;
    brute(grid, 0, row, col, diag, antiDiag, 0);

    cout << counter << endl;

    return 0;
}