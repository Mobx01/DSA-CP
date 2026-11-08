/*leetcode ps-112. Path Sum
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.*/




/* Approach - Recursive Depth-First Search Root-to-Leaf Path Accumulation / Path Sum (Time: O(N), Space: O(H))
 * Basically, we completely annihilate brute-force path enumeration by aggressively accumulating node values down the recursion stack and verifying target sums precisely at leaf nodes in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Root-to-Leaf Path Sum Invariant (LeetCode 112 - Path Sum)! As we traverse from the root down to any node, we maintain the running path sum (`currentSum`). When we hit a true leaf node (`root->left == nullptr && root->right == nullptr`), we check if `currentSum == targetSum`.
 * - (Clean Leaf Validation): Checking leaf status specifically ensures that intermediate prefix sums that happen to equal `targetSum` are not falsely counted as valid paths unless they terminate at an actual leaf node.
 * - (Optimal Complexity): Visiting every node in the binary tree takes $O(N)$ time, and auxiliary stack space is bounded by the height of the tree $O(H)$ (which is $O(\log N)$ for balanced trees and $O(N)$ in the worst-case skewed scenario).
 * * How it runs:
 * First, `hasPathSum` delegates the traversal to our helper function `solve` starting with an initial `currentSum` of `0`.
 * Inside `solve`, we handle base cases where `root` is `nullptr` (returning `false`). We add `root->val` to `currentSum`.
 * We check if the current node is a leaf; if so, we return whether `currentSum == targetSum`. Otherwise, we recursively evaluate the left and right subtrees using logical OR (`||`).
 * Finally, we flush the boolean result to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    bool solve(TreeNode* root, int currentSum, int targetSum) {
        if (root == nullptr) return false;
        
        currentSum += root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum == targetSum;
        }
        
        // Check both left and right subtrees
        return solve(root->left, currentSum, targetSum) || solve(root->right, currentSum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};
