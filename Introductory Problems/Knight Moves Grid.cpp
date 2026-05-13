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

    long long n;
    cin >> n;

    vector<vector<int>>dp(n, vector<int>(n,INT_MAX));

    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;

    int dx[] = {-2,-2,2,2,-1,-1,1,1};
    int dy[] = {-1,1,-1,1,2,-2,2,-2};

    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();

        for(int k=0; k<8; k++){
            int ni = curr.first + dx[k], nj = curr.second + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < n && dp[ni][nj] == INT_MAX){
                dp[ni][nj] = dp[curr.first][curr.second] + 1;
                q.push({ni, nj});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}