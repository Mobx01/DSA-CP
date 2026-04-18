// Leetcode ps: 1339 Maximum Product of Splitted Binary Tree
/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
Note that you need to maximize the answer before taking the mod and not after taking it
*/
// Intuition:
// Removing any one edge in the binary tree splits it into two parts.
// The product depends on the sum of one subtree and the sum of the remaining tree.
// Instead of trying all edges explicitly, we compute subtree sums using DFS.

// Approach:
// 1. First compute the total sum of the tree.
// 2. Use post-order traversal to calculate subtree sums.
// 3. For each subtree:
//    - subTsum = sum of current subtree
//    - remsum = totalSum - subTsum
//    - update the maximum product using subTsum * remsum
// 4. Return subtree sum to parent for further calculations.

// Time Complexity: O(n)
// Each node is visited once.

// Space Complexity: O(h)
// Due to recursion stack, where h is the height of the tree.

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
long Sum = 0;
long maxp = 0;
    int totalsum(TreeNode * root){
        if(root==NULL) return 0;
        int leftssum =totalsum(root->left);
        int rightssum = totalsum(root->right);
        long subTsum = root->val + leftssum + rightssum;

        int remsum = Sum - subTsum;
        maxp = max(maxp , subTsum*remsum);
        return subTsum;
    }
    
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0 ;
        maxp = 0 ;
        Sum = totalsum(root);
        totalsum(root);
        return maxp%1000000007;
    }
};
