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


/*
greedy approach, sort the array and keep track of the sum of all coins seen so far, 
if the next coin is greater than sum + 1, then we cannot make sum + 1 with the coins seen so far as it will create a gap, 
so we return sum + 1 as the answer                            
*/

int main(){
    fastc;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    if(arr[0] > 1){
        cout << 1 << endl;
        return 0;
    }
    long long sum = arr[0];

    for(int i = 1; i < arr.size(); i++){
        if(arr[i] <= sum + 1){
            sum += arr[i];
        } else {
            cout << sum + 1 << endl;
            return 0;
        }
    }

    cout << sum + 1 << endl;


    return 0;
}