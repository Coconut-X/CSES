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

    int n,x;
    cin >> n >> x;

    vector<int> w(n);
    for(auto &e: w) cin >> e;

    sort(w.begin(), w.end());

    //sort by weights
    //pair heaviest with lightest

    int count = 0;
    int i = 0, j = n - 1;
    while(i <= j){
        if(i == j){
            count++;
            break;
        }
        if(w[i] + w[j] <= x){
            i++;
            j--;
        }
        else{
            j--; //let heaviest go alone, because all next lightest will exceed the weight
        }
        count++;
    }
    cout << count << endl;

    // 2 3 7 9

    return 0;
}