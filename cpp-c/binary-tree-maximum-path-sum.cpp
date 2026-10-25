/*Leetcode ps - 124. Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.*/



/* Approach - Post-Order DFS with Local Path Optimization / Binary Tree Maximum Path Sum (Time: O(N), Space: O(H))
 * Basically, we completely annihilate brute-force subtree enumeration by aggressively computing maximum gain paths via bottom-up recursion, tracking global peaks while returning single-branch contributions in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Maximum Path Sum Invariant (LeetCode 124 - Binary Tree Maximum Path Sum)! For any given node, the maximum path passing *through* it as the highest point (the "bending" path) is `root->val + max(0, left_gain) + max(0, right_gain)`, which we use to dynamically update our global maximum (`maxsum`). Meanwhile, the value returned to the parent must be a single straight path branch: `root->val + max(0, max(left_gain, right_gain))`, ensuring that only one branch is propagated upward.
 * - (Negative Node Handling via `max(0, ...)`): Clamping negative child gains to `0` via `max(0, solve(...))` effectively ignores subtrees that reduce the total path sum, preventing unnecessary score degradation.
 * - (Auxiliary Stack Efficiency): The recursion stack depth is proportional to the height of the tree $H$ ($O(\log N)$ for balanced trees, $O(N)$ in the worst-case skewed scenario), keeping space overhead minimal.
 * * How it runs:
 * First, we initialize our global `maxsum` to `INT_MIN`.
 * We invoke the recursive helper `solve(root)`, which computes the maximum single-branch gain from the left and right children.
 * Inside `solve`, we calculate the local curved path sum (`cur = root->val + sc1 + sc2`), update `maxsum`, and return the maximum single-branch path contribution upward.
 * Finally, after traversing the entire tree, we flush `maxsum` to the output stream with absolute mathematical precision at raw silicon speed!
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
    int maxsum = INT_MIN;
    int solve(TreeNode* root){
        if(root == nullptr)return 0;

        int sc1 = max(0,solve(root->left)),sc2 = max(0,solve(root->right));

        int cur = root->val + sc1 + sc2;
        maxsum = max(maxsum,cur);

        return (root->val + max(sc1,sc2));

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};
