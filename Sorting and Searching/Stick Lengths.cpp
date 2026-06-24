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
    //cool math problem
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    //median minimizes the sum of absolute deviations from a central point, so we can use median as the point to minimize the sum of absolute differences
    int median = arr[n/2];
    long long count = 0;
    for(int i = 0; i < n; i++){
        count += abs(median - arr[i]);
    }
    cout << count << endl;

    return 0;
}