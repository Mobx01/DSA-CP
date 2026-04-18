/*Leetcode ps:- 110. Balanced Binary Tree.
Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
    bool res = true;
    int dfs(TreeNode* node){
        if(node == nullptr) return 0;

        int l = dfs(node->left); // uses recursion to calculate the left length
        int r = dfs(node->right); // same as abovw

        if(abs(l-r) > 1) res = false;

        return ( max(l,r)+1);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
};
