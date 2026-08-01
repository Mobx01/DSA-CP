/*Leetcode ps-486. Predict the Winner
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

*/

/* Approach - Minimax Algorithm / Top-Down Dynamic Programming (Time: O(N^3) [Should be O(N^2)], Space: O(N^2))
 * Basically, we mathematically simulate a flawless game where both players play perfectly. We calculate the absolute maximum score Player 1 can secure by fiercely assuming Player 2 will maliciously force us into the worst possible remaining scenarios!
 * * Observation: 
 * - This is classic Minimax game theory! When we pick an end (either `i` or `j`), we confidently add its value to our score. However, because our opponent plays perfectly to maximize their own score, they will always leave us with the mathematically smallest possible outcome from the remaining pieces. Thus, our future score is strictly bounded by the `min()` of the next two possible game states!
 * - We brilliantly bypass the need to track whose turn it is. We simply calculate Player 1's absolute maximum score (`sc1`), find Player 2's score by subtracting `sc1` from the `total` sum, and check if Player 1 ties or wins!
 * - (Bug Alert: You are passing `vector<int> nums` completely **by value** in your recursive `solve` function instead of by reference (`const vector<int>& nums`)! This catastrophically forces C++ to physically clone the entire array into memory on every single recursive call, massively degrading your time complexity to O(N^3) and needlessly burning through call stack memory!)
 * * How it runs:
 * First, we quickly sweep through `nums` to sum up the `total` available points on the board, and completely wipe our `t` memoization table with `-1`s using `memset` to prep for caching.
 * Then, we trigger our recursive `solve` function with our full boundaries `i = 0` and `j = nums.size() - 1`. If our pointers ever cross (`i > j`), the board is empty, so we return 0. If there is only one piece left (`i == j`), we instantly grab it.
 * Next, we check our cache! If `t[i][j]` is not `-1`, we instantly return the previously calculated absolute best score for this exact board state, saving millions of operations.
 * If uncached, we evaluate both choices. If we take the left end (`take_i`), we add `nums[i]` and look two turns ahead to grab the *minimum* of what the opponent will leave us. We mathematically mirror this logic for the right end (`take_j`).
 * Finally, we aggressively cache the absolute maximum of those two branching paths directly into `t[i][j]` and return it. Back in `predictTheWinner`, we lock in Player 1's best score, calculate Player 2's, and confidently return true if `sc1 >= sc2`!
 */


class Solution {
public:
    int t[21][21];
    int solve( int i,int j,vector<int> nums){
        if(i >j)return 0;
        if(i == j)return nums[i];
        if(t[i][j] != -1) return t[i][j];
        int take_i = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j = nums[j] + min(solve(i+1,j-1,nums),solve(i,j-2,nums));

        return t[i][j] = max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) { 
        int total = 0;
        for(int i : nums) total += i;
        memset(t,-1,sizeof(t));

        int sc1 = solve(0,nums.size() - 1,nums);
        int sc2 = total - sc1;

        return (sc1 >= sc2);
    }
};
