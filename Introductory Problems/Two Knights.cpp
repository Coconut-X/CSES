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
///https://cses.fi/problemset/task/1072

///find total combinations of placing two knights on kxk grid
//find total attacking pairs
///subtract both to find non attacking pairs
/// total pairs = k^2*(k^2-1)/2 = k*kC2


void method1(){
    long long n;
    cin >> n;


    for(long long k = 1; k <= n; k++){ //got out of bound for using int for k :) use long long for k to avoid overflow k*k
        if(k == 1){
            cout << 0 << endl;
            continue;
        }
        if(k == 2){
            cout << 6 << endl;
            continue;   
        }
        long long total_pairs = k*k*(k*k-1)/2; //total ways to place 2 knights on k by k grid

        long long corner = 4*2; //4 corners each attacking 2 cells

        long long cornerplusminusone = 0;
        if(k == 3) cornerplusminusone = 2*4; //cells adjacent to corners in 3 by 3 grid attack 4 cells each, there are 2 such cells for each corner
        if(k >= 4) cornerplusminusone = 3*8; //cells adjacent to corners in larger grids attack 8 cells each, there are 3 such cells for each corner and 4 corners

        long long innerCorner = 0; //the first cell in diagonal of corners
        if(k > 3) innerCorner = 4*4; //the first cell in diagonal of corners attacks 4 cells, there are 4 such cells in the grid
        
        long long layerOfCellsBetweenInnerCorners = 0;
        if(k >= 5) layerOfCellsBetweenInnerCorners = 4*(k-4)*6;//4 such layers each having k - 4 cells, and each cell attacking 6 cells

        long long middleCellsCount = 0; //the cells in the middle of the grid which are not in the layer of cells between inner corners, these cells attack 8 cells each
        if(k >= 5) middleCellsCount = (k-4)*(k-4)*8; //each middle cell attacks 8 cells

        long long outerEdges = 0;
        if(k >= 5) outerEdges = 4*(k-4)*4;
        
        long long attacking_pairs = corner + cornerplusminusone + innerCorner + layerOfCellsBetweenInnerCorners + middleCellsCount + outerEdges;
        // cout << "---K--- " << k << endl << "Corner: " << corner << ", Corner plus minus one: " << cornerplusminusone << ", Inner corner: " << innerCorner << ", Layer of cells between inner corners: " << layerOfCellsBetweenInnerCorners << ", Middle cells count: " << middleCellsCount << ", Outer edges: " << outerEdges << endl;
        // cout << "Total pairs: " << total_pairs << endl;
        // cout <<"Non attacking pairs: " << total_pairs - attacking_pairs/2 << endl;
        ///cout <<"K : " << k << " Total pairs: " << total_pairs << " Attacking pairs: " << attacking_pairs << " Non attacking pairs: " << total_pairs - attacking_pairs << endl;
        attacking_pairs /= 2; //each pair is counted twice in attacking pairs so divide by 2 to get the correct count
        long long non_attacking_pairs = total_pairs - attacking_pairs;
        cout << non_attacking_pairs << endl;
    }
}

//in 2x3 block there are 2 ways to place two knights such that they attack each other
//in 3x2 block there are also 2 ways to place two knights such that they attack each other
//there are (k-1)*(k-2) such blocks of 2x3 in k by k grid
//there are (k-2)*(k-1) such blocks of 3x2 in k by k grid
/// attacking pairs = 2x[ways to place knights in 2x3 block] x [number of 2x3 blocks] + 2x[ways to place knights in 3x2 block] + 2x[number of 3x2 blocks]
// attacking pairs = 2(k-1)(k-2) + 2(k-2)(k-1) = 4(k-1)(k-2)
void method2Optimal(){
    long long n;
    cin >> n;
    //its like trying to fill rectangle of 2 by 3 with knights, there are 4 ways to do that and there are (k-1)*(k-2) such rectangles in k by k grid, so total attacking pairs are 4*(k-1)*(k-2)
    for(long long k = 1; k <= n; k++){
        long long total_pairs = k*k*(k*k-1)/2; //total ways to place 2 knights on k by k grid
        long long attacking_pairs = 4*(k-1)*(k-2); //each knight can attack 4 positions, and there are (k-1)*(k-2) such positions for the first knight
        long long non_attacking_pairs = total_pairs - attacking_pairs;
        cout << non_attacking_pairs << endl;
    }
}

int main(){
    fastc;

    method2Optimal();


    return 0;
}