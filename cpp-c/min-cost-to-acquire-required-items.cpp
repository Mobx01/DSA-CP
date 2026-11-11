/*Leetcode ps-3789. Minimum Cost to Acquire Required Items
You are given five integers cost1, cost2, costBoth, need1, and need2.
There are three types of items available:
An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.
Return an integer representing the minimum possible total cost to achieve these requirements.*/



/* Approach - Greedy Cost Minimization with Dual-Need Optimization / Minimum Cost to Buy Apples (Time: O(1), Space: O(1))
 * Basically, we completely annihilate brute-force searching or complex dynamic programming by aggressively applying greedy choices to balance dual requirements using combined versus individual pricing in strict $O(1)$ constant time!
 * * Observation: 
 * - The absolute core of this architecture is the Dual-Need Greedy Invariant! To satisfy `need1` of item 1 and `need2` of item 2, we first evaluate whether buying both items together using `costBoth` is cheaper than buying them separately (`cost1 + cost2`). 
 * - (Greedy Remainder Handling): After satisfying the overlapping requirement (`cmn = min(need1, need2)`), we are left with a remainder for either item 1 or item 2. For the remaining units, we greedily choose between buying them individually (`cost1` or `cost2`) or via the combined package (`costBoth`), whichever is cheaper (`min(costBoth, cost1)` and `min(costBoth, cost2)`).
 * - (Optimal Complexity): With only basic arithmetic comparisons and multiplications, the time complexity is strictly $O(1)$ and auxiliary space is $O(1)$.
 * * How it runs:
 * First, we determine the optimal cost for satisfying both items simultaneously (`cst`) and find the overlapping minimum requirement (`cmn`).
 * We accumulate the cost for the common portion into `res`.
 * Next, we calculate the remaining needs (`rem1` and `rem2`) and add their optimal individual-or-combined costs to `res`.
 * Finally, we flush the minimum total cost to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res =0;
        //for common
        int cst = min((long long )costBoth,(long long)(cost1+cost2));
        int cmn = min(need1,need2);
        res += (long long)cst*(long long)cmn;
        int rem1 = need1 - cmn,rem2 = need2-cmn;
        res += (long long)rem1*(min(costBoth,cost1)) + (long long)rem2*(min(costBoth,cost2));
        return res;   
    }
};
