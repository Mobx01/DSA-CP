/*Leetcode ps-543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.*/



/* Approach - Recursive Bottom-Up Diameter Calculation / Height-Based Post-Order Traversal (Time: O(N), Space: O(H))
 * Basically, we completely annihilate redundant subtree re-traversals by aggressively computing heights and updating the global diameter in a single post-order traversal pass, solving the tree diameter in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Subtree Height Sum Invariant! The diameter passing through any node is precisely equal to the sum of its left subtree height (`lh`) and right subtree height (`rh`). By tracking a global `maxdepth` variable and updating it during every node return (`maxdepth = max(maxdepth, lh + rh)`), you evaluate every possible path bend without ever needing an $O(N^2)$ brute-force approach.
 * - (Global Variable vs. Reference Passing): Using a member variable (`int maxdepth;`) inside the `Solution` class is clean and concise for competitive programming. However, re-initializing it inside `diameterOfBinaryTree` (`maxdepth = 0;`) is crucial so that multiple test cases or repeated function calls don't bleed stale state across runs!
 * * How it runs:
 * First, we initialize our global `maxdepth` tracker to `0` inside the public driver function.
 * We ignite our recursive helper `maxd(root)`, which dives down to the leaves and bubbles subtree heights back up.
 * At each node, we calculate the left and right heights, update our maximum diameter path (`lh + rh`), and return `1 + max(lh, rh)` to the parent.
 * Finally, we flush the accumulated maximum diameter to the output stream with absolute mathematical precision at raw silicon speed!
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
    int maxdepth;
    int maxd(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int lh = maxd(root->left);
        int rh = maxd(root->right);

        maxdepth = max(maxdepth,lh+rh);

        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth =0 ;
        maxd(root);
        return maxdepth;
    }
};
