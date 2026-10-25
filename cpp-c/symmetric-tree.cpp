/*Leetcode ps-101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/



/* Approach - Recursive Mirror Symmetry Validation / Symmetric Tree Traversal (Time: O(N), Space: O(H))
 * Basically, we completely annihilate complex iterative queue management by aggressively delegating symmetry checks to a dual-pointer recursive helper function that mirrors left and right subtrees in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Mirror Symmetry Invariant (LeetCode 101 - Symmetric Tree)! A binary tree is symmetric if and only if the left subtree is a mirror reflection of the right subtree. Two nodes `n1` and `n2` are mirrors of each other if their values match (`n1->val == n2->val`), the left child of `n1` matches the right child of `n2`, and the right child of `n1` matches the left child of `n2`.
 * - (Null-Safety Guards): Explicitly checking for `nullptr` conditions at the top of the `ismirror` helper prevents null dereferences and establishes clear base cases for the recursion tree.
 * - (Recursion Stack Efficiency): The auxiliary space is bounded by the maximum height of the tree $H$ ($O(\log N)$ for balanced trees, $O(N)$ in the worst-case skewed layout), maintaining optimal efficiency.
 * * How it runs:
 * First, we check if the root is `nullptr`, returning `true` immediately since an empty tree is symmetric.
 * We invoke the `ismirror` helper passing `root->left` and `root->right`.
 * Inside `ismirror`, we return `true` if both pointers are null, `false` if only one is null, or evaluate value equality combined with crossed recursive calls (`n1->left` with `n2->right`, and `n1->right` with `n2->left`).
 * Finally, we flush the boolean symmetry result to the output stream with absolute mathematical precision at raw silicon speed!
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
    bool ismirror(TreeNode* n1 , TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr)return true;

        if(n1 == nullptr || n2 == nullptr)return false;

        return ((n1->val == n2->val) && ismirror(n1->left,n2->right) && ismirror(n1->right,n2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return ismirror(root->left,root->right);
    }
};
