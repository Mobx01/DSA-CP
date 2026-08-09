/*Leetcode ps -1140. Stone Game II
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.
Alice and Bob take turns, with Alice starting first.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.*/


/* Approach - DP Memoization / Minimax Game Theory (Time: O(N^3), Space: O(N^2))
 * Basically, we mathematically model the optimal decisions of both players using Game Theory, aggressively optimizing the simulation with a Suffix Sum array and securely caching overlapping states to violently crush the time complexity!
 * * Observation: 
 * - In a zero-sum game where both players play perfectly optimally, calculating the maximum stones Alice can get is mathematically identical to taking the TOTAL remaining stones on the board, and ruthlessly subtracting the maximum stones Bob can get from that exact point! This completely eliminates the nightmare of explicitly tracking whose turn it is!
 * - Because the total remaining stones are queried constantly, recalculating them with a loop every time would burn O(N) operations per state. By precomputing a `suffixSum` array, we brilliantly fetch the exact remaining total in guaranteed O(1) time!
 * - (The Absolute Base Case): If a player's maximum reach (`i + 2 * m`) is completely out of bounds or equal to the remaining array size, they will aggressively grab every single remaining stone to absolutely maximize their score.
 * * How it runs:
 * First, we safely extract the total size `n`, aggressively reset our massive 101x101 memoization table `t` to -1, and trigger a high-speed reverse linear sweep to flawlessly build our `suffixSum` array.
 * Then, we launch our recursive `solve` function starting exactly at index 0 with a base multiplier of `m = 1`.
 * Inside the simulation, if the current state `[i][m]` is already solved, we instantly return the cached answer. If the player can reach the end, they greedily take everything `suffixSum[i]`.
 * Next, we trigger a fierce loop to test every single valid move `x` (from 1 up to `2 * m`). For every choice, we simulate the opponent's optimal future score by recursively calling `solve(i + x, max(m, x))`.
 * We mathematically deduct the opponent's score from the total remaining pool (`suffixSum[i] - bobsturn`) to calculate our exact haul. We relentlessly update `maxStones` to lock in the absolute best possible outcome, seamlessly cache it into `t[i][m]`, and confidently return!
 */


class Solution {
public:
    int t[101][101];//mwmoization array
    int solve(int i, int m, vector<int>& suffixSum) {
        int n = suffixSum.size();
        
        if (i + 2 * m >= n) {
            return suffixSum[i];
        }
        if(t[i][m] != -1) return t[i][m];
        
        int maxStones = 0;
        
        for (int x = 1; x <= 2 * m; x++) {
            int bobsturn = solve(i + x, max(m, x), suffixSum);// if alice chooses x stones then bob will have options from x+1.
            maxStones = max(maxStones, suffixSum[i] - bobsturn);//alice will have stone till ith index - bobs stones;
        }
        
        return t[i][m] = maxStones;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum = piles;

        for(int i =0;i<101;i++){
            for(int j =0;j<101;j++){
                t[i][j] = -1;
            }
        }
        
        // suffixSum[i] stores sum of piles from index i to the end
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] += suffixSum[i + 1];
        }
        
        return solve(0, 1, suffixSum);
    }
};
