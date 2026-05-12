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



void moves(int n, int source, int aux, int dest, vector<pair<int,int>>& move){
    if(n == 1){
        move.push_back({source, dest}); //if one disk then move it from source to dest 
        return;
    }
    //to move the biggest disk which is on bottom initially, we need to remove n-1 disk from source using middle one as temporary rod
    moves(n - 1, source, dest, aux, move);
    //after moving all them to middle one, we can safely move the largest disk from source to dest 
    move.push_back({source, dest});
    //now all other disks are on the aux middle rod(and all are in correct order with largest at bottom), it means it is acting as source array
    //now our original source will act as aux
    moves(n - 1, aux, source, dest, move);
}

int main(){
    fastc;

    long long n;
    cin >> n;

    vector<pair<int,int>> move;
    moves(n, 1, 2, 3, move);
    
    cout << move.size() << endl;

    for(auto &e: move){
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}