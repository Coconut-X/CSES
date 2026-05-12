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

int glo = 0;
void allStrings(vector<bool> used, int count, string &s, string make, int &n, unordered_map<string, bool>&mep, vector<string>&res){
    if(count == n){
        if(mep[make] == true) return;
        mep[make] = true;
        glo++;
        res.push_back(make);
        return;
    }

    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        make+=s[i];
        used[i] = true;
        allStrings(used, count + 1, s, make, n, mep, res);
        used[i] = false;
        make.pop_back();
    }

}

int main(){
    fastc;

    string s;
    cin >> s;
    int n = s.size();
    vector<bool> used(n, false);
    unordered_map<string, bool> mep; // to avoid duplicates in case of repeated characters in the input string
    vector<string> res;
    allStrings(used, 0, s, "", n, mep, res);

    sort(res.begin(), res.end());
    cout << glo << endl;

    for(string e: res){
        cout << e << endl;
    }

    ////direct formula for number of permutations of a string with repeated characters is n! / (n1! * n2! * ... * nk!) 
    ////where n is the total number of characters and n1, n2, ... nk are the counts of each unique character in the string
    ///for aabac we have 5 characters in total and counts of a, b, c are 3, 1, 1 respectively 
    ///so the number of permutations is 5! / (3! * 1! * 1!) = 20 

    return 0;
}