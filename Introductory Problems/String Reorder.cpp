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
    
    string s;
    cin >> s;

    int n = s.size();

    set<char> unique;
    unordered_map<char,int>freq;
    int m = 0;
    for(int i = 0; i < n; i++){
        unique.insert(s[i]);
        freq[s[i]]++;
        m = max(m,freq[s[i]]);
    }
    if (m > (n + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    string lex = "";
    for(int i = 0; i < n; i++){
        for(auto &e: unique){
            if((i!=0 && lex!="" && e == lex[lex.size() - 1]) || freq[e] == 0) continue;
            int rem = n - i - 1;
            freq[e]--;
            bool found = false;
            for(auto &ee:unique){
                if(freq[ee] > (rem + 1)/ 2){
                    found = true; //find atleast one element which violates the law
                    break;
                }
            }
            if(!found){//all elements are valid after this selection
                cout << e;
                lex+=e;    
                break;
            }  
            else{
                freq[e]++;
            }
        }
    }


    return 0;
}