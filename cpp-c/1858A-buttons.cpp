/*Codeforces PS - 1858A. Buttons
Anna and Katie ended up in a secret laboratory. There are a+b+c buttons in the laboratory. It turned out that a buttons can only be pressed by Anna, b buttons can only be pressed by Katie, and c buttons can be pressed by either of them. Anna and Katie decided to play a game, taking turns pressing these buttons. Anna makes the first turn. Each button can be pressed at most once, so at some point, one of the girls will not be able to make her turn.
The girl who cannot press a button loses. Determine who will win if both girls play optimally.

Input
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
Each test case consists of three integers a, b, and c (1 ≤ a, b, c ≤ 10^9) — the number of buttons that can only be pressed by Anna, the number of buttons that can only be pressed by Katie, and the number of buttons that can be pressed by either of them, respectively.

Output
For each test case, output First if Anna wins, or Second if Katie wins.
*/


/* Approach - Game Theory & Math (Time: O(1), Space: O(1))
 * Basically, we determine the winner of a turn-based pile game by comparing the players' exclusive resources and checking who gets the mathematical advantage from the shared resource.
 * * Observation: 
 * - Both players will optimally try to exhaust the shared pile 'c' first to deprive the other. However, from a macro perspective, 'c' simply acts as a turn-parity tiebreaker.
 * - If one player starts with strictly more exclusive items ('a' or 'b'), they have enough guaranteed moves to outlast the opponent regardless of how the shared pile is distributed.
 * - If their exclusive piles are exactly equal ('a == b'), the entire game comes down to the shared pile 'c'. Since 'First' takes the first turn, an odd 'c' means 'First' claims the extra shared item and secures the win. An even 'c' means the shared pile is split perfectly evenly, allowing 'Second' to have the final decisive move!
 * * How it runs:
 * First, we read the counts for piles 'a' (First's exclusive), 'b' (Second's exclusive), and 'c' (Shared).
 * Then, we evaluate the absolute differences in exclusive piles. If 'a > b', we immediately print "First". If 'b > a', we immediately print "Second".
 * Finally, if they are dead tied ('a == b'), we use the modulo operator on 'c' (c % 2). If it's odd, we print "First", and if it's even, we print "Second"!
 */

#include<iostream>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    // First has strictly more, it always win.
    if(a > b){
        cout << "First\n";
    }
    // Second has strictly more, it always win.
    else if(b > a){
        cout << "Second\n";
    }
    // they have the  same amount, it comes down to the shared pile (c).
    else {
        if(c % 2 == 0) cout << "Second\n"; // Split evenly, First runs out first
        else cout << "First\n";            // First gets the extra turn from c
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
       solve();   
    }

    return 0;
}
