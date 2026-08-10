/*Leetcode ps-1510. Stone Game IV
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
Also, if a player cannot make a move, he/she loses the game.
Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.*/


/* Approach - Minimax Game Theory / DP Memoization (Time: O(N * sqrt(N)), Space: O(N))
 * Basically, we mathematically simulate a brutal zero-sum game of perfect information, aggressively branching through every single valid perfect square move and perfectly caching the outcomes to completely crush the time limit!
 * * Observation: 
 * - This is a classic combinatorial impartial game! Since both players play flawlessly, if Alice can forcefully push the game into a state where Bob is mathematically guaranteed to lose, Alice instantly secures the win!
 * - Because the players are strictly restricted to removing *perfect square* numbers of stones (1, 4, 9, 16...), the maximum number of available moves from any state `n` is aggressively bounded by `sqrt(n)`. This brilliantly keeps our branching factor incredibly small!
 * - (The Absolute Game-Breaker / Optimization Alert): Your code redundantly tracks `player` in the massive `t[n][2]` memoization table! In this specific game, the rules are perfectly symmetric. A board with `n` stones is objectively either a "Winning State" or a "Losing State" regardless of who is currently looking at it! You could violently slash the memory footprint exactly in half by completely dropping the `player` dimension and simply returning `true` if ANY valid move forces the opponent into a `false` (losing) state!
 * * How it runs:
 * First, we safely allocate our massive `t` matrix, instantly filling it with `-1`, and securely launch our recursive `solve` engine starting with exactly `n` stones and Alice (`turn = 0`) at the helm.
 * Inside the engine, we fiercely check our absolute base case: if `n == 0`, the current player has no physical moves left. If it's Alice's turn (`turn % 2 == 0`), she mathematically loses (`false`). If it's Bob's turn, he loses (meaning Alice wins, returning `true`)!
 * Next, we aggressively query our cached `t[n][player]`. If the state is already solved, we instantly return it without wasting a single CPU cycle.
 * Then, we trigger a high-speed `i * i <= n` loop to ruthlessly simulate every single perfect square extraction. If it's Alice's turn, she aggressively hunts for ANY branch that mathematically returns `true` (a forced win). The exact millisecond she finds one, she brutally breaks the loop!
 * Conversely, if it's Bob's turn, he fiercely hunts for ANY branch that returns `false` (forcing Alice to lose), instantly breaking if he finds a winning path for himself.
 * Finally, we flawlessly lock the ultimate outcome into our memoization table `t` and confidently return the result, organically collapsing the massive recursive decision tree down to a guaranteed optimal answer!
 */


class Solution {
public:
    // t[n][0] stores alice turns
    // t[n][1] stores bobs turns
    vector<vector<int>> t; 

    bool solve(int n, int turn){
        if(n == 0){
            if(turn % 2 == 0) return false; // Alice has no moves
            else return true;               // Bob has no moves
        }
        
        int player = turn % 2;
        
        if(t[n][player] != -1) return t[n][player];
        
        if (player == 0) {
            // ALICE'S TURN:find any move that returns TRUE
            bool res = false;
            for(int i = 1; i * i <= n; i++){
                res = solve(n - i * i, turn + 1);
                if(res == true) break; 
            }
            return t[n][player] = res;
        } else {
            // BOB'S TURN:finds any move that returns FALSE
            bool res = true;
            for(int i = 1; i * i <= n; i++){
                res = solve(n - i * i, turn + 1);
                if(res == false) break; 
            }
            return t[n][player] = res;
        }
    }
    
    bool winnerSquareGame(int n) {
        t.resize(n + 1, vector<int>(2, -1)); 
        return solve(n, 0);
    }
};
