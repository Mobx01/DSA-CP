/*Leetcode ps:- 145. Binary Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.*/
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
    vector<int> res;
    void pot(TreeNode* root){
        if(root != NULL){
            pot(root->left);
            pot(root->right);
            res.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        pot(root);
        return res;
    }
};
