/*Letcode ps-877. Stone Game
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.*/


/* Approach - Minimax Dynamic Programming / Mathematical Guarantee (Time: O(N^3) [Should be O(N^2)], Space: O(N^2))
 * Basically, we deploy the exact same flawless Minimax game theory from the previous problem to dynamically calculate Player 1's absolute maximum score, beautifully simulating both players playing perfectly!
 * * Observation: 
 * - The logic here is physically identical to Predict the Winner! We boldly assume Player 1 maximizes their score, while Player 2 maliciously minimizes Player 1's future opportunities.
 * - (The Absolute Game-Breaker): The problem constraints for "Stone Game" explicitly state there is an EVEN number of piles and an ODD total number of stones. Because of this, Player 1 can mathematically pre-calculate whether the sum of all even-indexed piles or odd-indexed piles is larger, and forcefully pick that exact sequence! Player 2 is completely powerless to stop this. This means Player 1 is mathematically GUARANTEED to win every single time, meaning you could literally delete this entire algorithm and just write `return true;` to perfectly solve it in O(1) time and space!
 * - (Bug Alert): Just like the previous code, you are passing `vector<int> nums` completely **by value** in the recursive `solve` function! C++ is violently cloning the entire array in memory on every single recursive branch, crushing your time complexity down to a sluggish O(N^3). Switching it to `const vector<int>& nums` instantly restores it to a lightning-fast O(N^2)!
 * * How it runs:
 * First, we iterate through the `piles` to calculate the `total` stones on the board, and aggressively wipe our `t` memoization table with `-1`s using `memset`.
 * Then, we trigger our recursive `solve` function. We instantly check our extreme base cases and our `t[i][j]` cache to see if we've already solved this exact subproblem.
 * Next, if uncached, we mathematically branch! We calculate the absolute best outcome of grabbing the left stone (`take_i`) versus the right stone (`take_j`), strictly adding the *minimum* of whatever our perfect-playing opponent leaves us from the next two turns.
 * Finally, we aggressively cache the absolute maximum of those two choices. Back in the main function, we subtract Player 1's max score from the `total` to find Player 2's score, and confidently return true (since Player 1 physically cannot lose)!
 */


class Solution {
public:
    int t[501][501];
    int solve( int i,int j,vector<int> nums){
        if(i >j)return 0;
        if(i == j)return nums[i];
        if(t[i][j] != -1) return t[i][j];
        int take_i = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j = nums[j] + min(solve(i+1,j-1,nums),solve(i,j-2,nums));

        return t[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        for(int i : piles) total += i;
        memset(t,-1,sizeof(t));

        int sc1 = solve(0,piles.size() - 1,piles);
        int sc2 = total - sc1;

        return (sc1 >= sc2);
    }
};

/* Approach - Game Theory / Mathematical Guarantee (Time: O(1), Space: O(1))
 * Basically, we completely bypass all complex dynamic programming and memoization by proving mathematically that Alice has an absolute, unstoppable winning strategy right from the very first move!
 * * Observation: 
 * - The absolute key to this solution lies entirely in the problem's strict constraints: there is an EVEN number of piles and an ODD total number of stones.
 * - Because the array has an even number of elements, the piles can be perfectly partitioned into exactly two isolated sets: even-indexed piles (0, 2, 4...) and odd-indexed piles (1, 3, 5...).
 * - Since the total sum of all stones is mathematically odd, it is structurally impossible for the sum of the even-indexed piles to equal the sum of the odd-indexed piles. One set is mathematically GUARANTEED to be strictly larger than the other!
 * - Alice goes first! This is the absolute game-breaker. If the even-indexed set is larger, she simply takes the 0th stone (even). This flawlessly forces Bob to choose between two odd-indexed stones. No matter what Bob picks, he instantly exposes another even-indexed stone for Alice. She can maliciously force Bob onto the losing track for the entire game!
 * * How it runs:
 * First, we completely ignore the input array, recognizing that the strict constraints of the game physically rig the entire board in Player 1's favor.
 * Then, we acknowledge that Alice will brilliantly pre-calculate the sums of both sets before making a single physical move, locking in her unstoppable strategy.
 * Finally, without allocating a single byte of auxiliary memory or running a single loop, we confidently return `true`, executing an absolute O(1) time and O(1) space masterclass!
 */


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};


