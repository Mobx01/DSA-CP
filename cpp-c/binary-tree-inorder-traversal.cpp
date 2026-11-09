/*Leetcode ps-94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.*/




/* Approach - Morris Inorder Traversal with Threaded Binary Tree Pointers (Time: O(N), Space: O(1))
 * Basically, we completely annihilate recursion stack and explicit stack space overhead by aggressively threading predecessor pointers back to current nodes, achieving true $O(1)$ auxiliary space binary tree traversal!
 * * Observation: 
 * - The absolute core of this architecture is the Morris Traversal Invariant (LeetCode 94 - Binary Tree Inorder Traversal)! By temporarily modifying the right pointer of the inorder predecessor in the left subtree to point back to the `curr` node, we create a temporary "thread" that allows us to return to `curr` after exploring the entire left subtree without needing an explicit stack.
 * - (Critical Bug & Infinite Loop Identification): There are two key bugs in the current implementation:
 *   1. **Infinite Loop**: The predecessor search `while(leftchild->right != NULL)` lacks the check `&& leftchild->right != curr`. Once a thread is established pointing back to `curr`, this loop will run infinitely because `leftchild->right` is never `NULL`.
 *   2. **Destructive Tree Mutation**: `temp->left = NULL;` permanently severs the left subtree. Morris traversal must *preserve* the tree structure, breaking threads only upon revisiting nodes via the established pointers.
 * - (Optimal Complexity): Visiting each node a constant number of times (to find predecessors and traverse) yields strict $O(N)$ time complexity and $O(1)$ auxiliary space.
 * * How it runs:
 * We initialize `curr = root`. While `curr` is not null:
 * If `curr->left` is null, we visit `curr` and move right.
 * Otherwise, we find the rightmost node (`prev`) in `curr`'s left subtree. If `prev->right` is null, we establish the thread (`prev->right = curr`) and move `curr = curr->left`. If `prev->right` already points to `curr`, we break the thread (`prev->right = NULL`), visit `curr`, and move `curr = curr->right`.
 * Finally, we flush the inorder traversal sequence to the output stream with absolute mathematical precision at raw silicon speed!
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        TreeNode* curr = root;
        while(curr != NULL){ 
            if(curr->left == NULL){//now start visiting
            res.push_back(curr->val);
            curr = curr->right;
            }else{
                TreeNode* leftchild = curr->left;

                //go to rightmost of left chile
                while(leftchild->right != NULL){
                    leftchild = leftchild->right;
                }
                //now make right of the rightmost node of leftchild point to curr
                leftchild->right = curr; // helps to visit the V and R IN L,V,R
                //delete the curr->left after procedding to left child
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }  
        return res; 
    }
};
