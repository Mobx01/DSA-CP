/*
Codeforces PS - 1904A. Forked!

Lunchbox is done with playing chess! His queen and king just got forked again!
In chess, a fork is when a knight attacks two pieces of higher value, commonly the king and the queen. Lunchbox knows that knights can be tricky, and in the version of chess that he is playing, knights are even trickier: instead of moving 1 tile in one direction and 2 tiles in the other, knights in Lunchbox's modified game move a tiles in one direction and b tiles in the other.
Lunchbox is playing chess on an infinite chessboard which contains all cells (x, y) where x and y are (possibly negative) integers. Lunchbox's king and queen are placed on cells (xK, yK) and (xQ, yQ) respectively. Find the number of positions such that if a knight was placed on that cell, it would attack both the king and queen.
Input
Each test contains multiple test cases. The first line contains an integer t (1 ≤ t ≤ 1000) — the number of test cases. The description of the test cases follows.
The first line of each test case contains two integers a and b (1 ≤ a, b ≤ 10^8) — describing the possible moves of the knight.
The second line of each test case contains two integers xK and yK (0 ≤ xK, yK ≤ 10^8) — the position of Lunchbox's king.
The third line in a test case contains xQ and yQ (0 ≤ xQ, yQ ≤ 10^8) — the position of Lunchbox's queen.
It is guaranteed that Lunchbox's queen and king will occupy different cells. That is, (xK, yK) ≠ (xQ, yQ).

Output
For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen.
*/


/* Approach - 8-Directional Geometry Simulation & Set Intersection (Time: O(1), Space: O(1))
 * Basically, we mathematically generate all 8 possible attack coordinates around the King and the Queen using the custom knight jumps, and use sets to find exactly how many of those target spaces perfectly overlap!
 * * Observation: 
 * - A standard chess knight jumps in a 2x1 L-shape, granting it exactly 8 possible landing spots. This custom piece jumps in an 'a' by 'b' shape, but mechanically operates the exact same way!
 * - By generating all 8 valid landing spots directly outwards from the King's coordinate and doing the exact same for the Queen, any perfectly shared coordinate is a valid tile where a single piece could "fork" (attack both simultaneously).
 * - Pushing the coordinates directly into a `set` is a brilliant move! It naturally handles the edge case where `a == b` (which would normally generate identical overlapping moves and cause catastrophic overcounting), flawlessly filtering them down to just the strictly unique positions.
 * - (Optimization Note: While `set<vector<long long>>` technically works, dynamically allocating a full `vector` just to store two coordinates is incredibly heavy and slow! Switching this to a lightweight `set<pair<long long, long long>>` would make it run significantly faster and use far less memory overhead!)
 * * How it runs:
 * First, we extract our custom jump dimensions 'a' and 'b', along with the exact 'xk, yk' coordinates of the King and 'xq, yq' of the Queen.
 * Then, we define a simple `dir` array representing the 4 directional quadrants to effortlessly control our mathematical signs.
 * Next, we iterate through these 4 directions, generating exactly two unique jump combinations per quadrant (swapping 'a' and 'b') for both the King and the Queen, aggressively pushing all results directly into their respective `kings` and `quens` sets.
 * Finally, we initialize an `attack` counter, physically sweep through every single unique coordinate inside the `kings` set, and check if it exists inside the `quens` set. We tally up every perfect overlap and confidently print our final `attack` count!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a  ,b, xk , yk ,xq, yq;
    cin >> a >> b >> xk >> yk >>xq >> yq;

    int dir[4][2] = {{1,1},{-1,1},{1,-1},{-1,-1}};

    set<vector<long long>> kings , quens;
    for(auto& v : dir){
        kings.insert({xk + v[0]*a , yk + v[1]*b});
        kings.insert({xk + v[0]*b , yk + v[1]*a});
        quens.insert({xq + v[0]*a , yq + v[1]*b});
        quens.insert({xq + v[0]*b , yq + v[1]*a});
    }
    //if any position of king and queen overlap then we can get both

    int attack =0;
    for(auto& v : kings){
        if(quens.find(v) != quens.end()) attack++;
    }
    cout << attack << endl;
}


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();  
    }

    return 0;
}
