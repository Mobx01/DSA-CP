/*Leetcode ps-2265. Count Nodes Equal to Average of Subtree
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.*/



/* Approach - Post-Order Accumulation & State Fusion / Subtree Average Extraction (Time: O(N), Space: O(H))
 * Basically, we completely annihilate the O(N^2) brute-force subtree traversal by aggressively deploying a bottom-up post-order DFS, mathematically fusing the sum and node count of child subtrees in a single recursive sweep!
 * * Observation: 
 * - The absolute core of this architecture is the Recursive State Fusion! To determine if a node's value equals the average of its subtree, you need the total sum of all values below it and the exact number of nodes. A post-order traversal perfectly delivers this: children return their aggregated sum and count, the parent merges them in O(1) time, checks the average condition `cursum / curcount == root->val`, and bubbles the updated metrics up to its own parent!
 * - (The Class-State Contamination Hazard): You declared `int count = 0;` as a private member variable of the `Solution` class. While you correctly re-initialize it to `0` inside `averageOfSubtree(root)`, relying on mutable class-state across multiple test cases can introduce subtle state-bleed bugs if a recursive path fails to reset it or if multi-threaded execution occurs. Passing a reference accumulator `int& count` through the recursive signature is a much cleaner, self-contained functional idiom.
 * - (Integer Division Precision Win): `cursum / curcount == root->val`. Because `cursum`, `curcount`, and `root->val` are integers, truncating integer division natively mirrors the mathematical definition of flooring averages required by the problem, executing entirely with raw register arithmetic and zero floating-point overhead!
 * * How it runs:
 * First, the main function resets our global counter and ignites the post-order recursive traversal starting from the root.
 * Base cases instantly return `{0, 0}` for null pointers, protecting against invalid memory access.
 * The recursion dives deep into the left and right subtrees, returning their respective sub-metrics.
 * We compute `cursum` and `curcount` for the current node, check the average equality condition against `root->val`, and increment our global `count` if it matches.
 * Finally, we return the fused pair `{cursum, curcount}` up the call stack, bubbling the final valid subtree count to the output stream at raw silicon speed!
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
    int count = 0;

    //{sum of subtree, number of nodes in subtree}
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto [lsum, lcount] = postOrder(root->left);
        auto [rsum, rcount] = postOrder(root->right);

        int cursum = root->val + lsum + rsum;
        int curcount = 1 + lcount + rcount;

        if (cursum / curcount == root->val) {
            count++;
        }

        return {cursum, curcount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        postOrder(root);
        return count;
    }
};
