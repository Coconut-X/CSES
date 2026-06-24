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

//one of the greatest learns lol
/*
after finding a suitable match in logn time, i used vector and erase to remove the element from the vector, which is O(n) time complexity, so overall time complexity is O(n^2) in worst case scenario.
to save time in erassing we can use a multiset instead of vector, which will give us O(logn) time complexity for erasing an element, so overall time complexity will be O(nlogn) in worst case scenario.
we also dont need to sort it separately
*/


int main(){
    fastc;

    int n, m;

    cin >> n >> m;

    multiset<int>ticket;
    vector<int>maxprice(m);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ticket.insert(x);
    }


    for(int i = 0; i < m; i++){
        int mp ;
        cin >> mp; //get current person's max price
        auto x = ticket.upper_bound(mp);
        if(x == ticket.begin()){
            cout << -1 << endl;
        }
        else{
            x--; ///the element just smaller than or equal to the max price, which is suitable for the person
            cout << *x << endl;
            ticket.erase(x); //erasing in logn
        }
        
    }

    //3 5 5 7 8 
    //4 8 3

    return 0;
}