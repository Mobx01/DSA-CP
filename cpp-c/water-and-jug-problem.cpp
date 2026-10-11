/*Leetcode ps-365. Water and Jug Problem
You are given two jugs with capacities x liters and y liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach target using the following operations:

Fill either jug completely with water.
Completely empty either jug.
Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.*/


/* Approach - Bézout's Identity GCD Verification / Linear Diophantine Equation Mapping (Time: O(log(min(X, Y))), Space: O(1))
 * Basically, we completely annihilate slow graph BFS/DFS state-space search trees by aggressively applying Bézout's identity, verifying water measurability via greatest common divisors in pristine logarithmic time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is Bézout's Identity Invariant (LeetCode 365 - Water and Jug Problem)! According to number theory, a linear combination of two jug capacities $ax + by$ can measure any target amount if and only if `target` is a multiple of $\text{gcd}(x, y)$, and the target does not exceed the total combined capacity of both jugs ($x + y$). 
 * - (Lightning-Fast Pruning): Guarding the logic with boundary checks (`if (x + y < target) return false;`) and direct equality matches (`x == target || y == target || x + y == target`) handles edge cases instantly before invoking `std::gcd`.
 * - (Elite Space Optimization): Reducing what is traditionally a graph traversal problem down to a pure mathematical formula drops auxiliary space complexity from $O(X + Y)$ states down to an absolute $O(1)$.
 * * How it runs:
 * First, we verify whether the combined capacity of both jugs is strictly less than the `target`. If so, we return `false` instantly.
 * We check if `target` matches either jug capacity or their sum directly.
 * We invoke `std::gcd(x, y)` to find the fundamental step size and check if `target % std::gcd(x, y) == 0`.
 * Finally, we flush the boolean measurability result to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if( x + y < target) return false;

        if(x == target || y == target || (x+y) == target)return true;

        return target%gcd(x,y) == 0;
    }
};
