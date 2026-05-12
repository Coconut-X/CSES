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

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    if((a == 0 and b!=0) or (b == 0 and a!=0)){
        cout << "NO" << endl;
        return;
    }
    if(a == n or b == n){
        cout <<"NO" << endl;
        return;
    }
    if(a+b > n){
        cout << "NO" << endl;
        return;
    }


    cout << "YES" << endl;
    if(a == 0 and b == 0){
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return;
    }
  
    int total = a + b;
    int same = n - total; //score remains zero, both play same card
    int diff = a - b;
    int absdiff = abs(diff);
    

    if(diff < 0){
        for(int i = 1; i <= n; i++) cout << i << " "; // print all numbers for 'a'
        cout << endl;

        for(int i = 1; i <= same; i++)  cout << i << " "; //print the same elements for b, these are points where score remains zero
        for(int i = n-b+1; i <= n; i++) cout << i << " "; ///print last b
        for(int i = same + 1; i <= n - b; i++) cout << i << " "; ////print the skipped from same+1 to n-b
        cout << endl;
    }
    else{
        //just do opposite but use n-a+1 etc
        for(int i = 1; i <= same; i++)  cout << i << " "; 
        for(int i = n-a+1; i <= n; i++) cout << i << " ";
        for(int i = same + 1; i <= n - a; i++) cout << i << " ";
        cout << endl;

        for(int i = 1; i <= n; i++) cout << i << " ";//print all for b 
        cout << endl;
    }
}

int main(){
    fastc;

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}