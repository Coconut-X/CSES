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
    ////problem: maximum non overlapping intervals
    int n;
    cin >> n;

    //using simple interval scheduling algo, sort by ending times

    vector<pair<int,int>> movie(n);

    for(int i = 0; i < n; i++){
        cin >> movie[i].second >> movie[i].first; ///take ending time first for easy sort
    }

    sort(movie.begin(), movie.end());

    int maxwatched = 0;
    int lastendtime = 0;
    for(int i = 0; i < n; i++){
        if(movie[i].second >= lastendtime){ //new movie start time is after last movie ending time, watch it
            maxwatched++;
            lastendtime = movie[i].first;
        }
    }
    cout << maxwatched << endl;


    return 0;
}