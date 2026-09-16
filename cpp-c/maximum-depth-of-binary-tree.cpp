/*Leetcode ps-104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/



/* Approach - Recursive Depth-First Tree Traversal / Maximum Height Computation (Time: O(N), Space: O(H))
 * Basically, we completely annihilate iterative stack overhead by aggressively deploying a clean, recursive divide-and-conquer strategy, computing the maximum depth of a binary tree in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Optimal Substructure Recursion! The maximum depth of any subtree is simply 1 (for the current root node) plus the maximum of the depths of its left and right subtrees. Your helper function `maxd` cleanly maps this mathematical definition with zero boilerplate.
 * - (Call-Stack Space Footprint): While the time complexity is optimal at O(N) since every node is visited once, the recursive call stack consumes O(H) space, where H is the height of the tree (ranging from O(log N) for balanced trees to O(N) for skewed degradation).
 * * How it runs:
 * First, we safely intercept the root node and check our base case: if the node is `nullptr`, we return a depth of `0`.
 * The recursion dives deep into both the left and right subtrees, computing their respective heights.
 * We take the maximum of the two subtree heights, add `1` for the current root node, and bubble the result back up the call stack.
 * Finally, we flush the maximum tree depth to the output stream with absolute mathematical precision at raw silicon speed!
 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxd(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        return 1 + max(maxd(root->left) ,maxd(root->right));
    }
    int maxDepth(TreeNode* root) {
        return maxd(root);
    }
};
