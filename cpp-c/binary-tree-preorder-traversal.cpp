/*144. Binary Tree Preorder Traversal
Given the root of a binary tree, return the preorder traversal of its nodes values.
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
    vector<int> res;
    void pot(TreeNode* root){
        if(root != NULL){
            res.push_back(root->val);
            pot(root->left);
            pot(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pot(root);
        return res;
    }
};



/* Approach - Morris Preorder Traversal with Threaded Binary Tree Pointers (Time: O(N), Space: O(1))
 * Basically, we completely annihilate recursion stack and explicit stack space overhead by aggressively threading predecessor pointers back to current nodes, achieving true $O(1)$ auxiliary space binary tree preorder traversal!
 * * Observation: 
 * - The absolute core of this architecture is the Morris Preorder Traversal Invariant (LeetCode 144 - Binary Tree Preorder Traversal)! Unlike inorder traversal where we visit the node when breaking the thread, in preorder traversal, we visit the node `curr` **immediately the first time we encounter it**—specifically when establishing the temporary thread (`leftchild->right == NULL`) before descending into the left subtree.
 * - (Thread Safety & Loop Prevention): Notice the correct inclusion of `leftchild->right != curr` in the predecessor search loop, which cleanly prevents infinite loops, as well as resetting `leftchild->right = NULL` upon revisiting via the thread, preserving original tree topology.
 * - (Optimal Complexity): Visiting each node a constant number of times yields strict $O(N)$ time complexity and $O(1)$ auxiliary space.
 * * How it runs:
 * We initialize `curr = root`. While `curr` is not null:
 * If `curr->left` is null, we visit `curr` (push `val`) and move right.
 * Otherwise, we find the rightmost node (`leftchild`) in `curr`'s left subtree. If `leftchild->right` is null, we visit `curr` *first*, establish the thread (`leftchild->right = curr`), and move `curr = curr->left`. If the thread already exists, we break it (`leftchild->right = NULL`) and move `curr = curr->right`.
 * Finally, we flush the preorder traversal sequence to the output stream with absolute mathematical precision at raw silicon speed!
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNoe(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> res;

        TreeNode* curr = root;
        while(curr != NULL){ 
            if(curr->left == NULL){//now start visiting
            //no left child move right
            res.push_back(curr->val);
            curr = curr->right;
            }else{
                TreeNode* leftchild = curr->left;

                //go to rightmost of left chile
                while(leftchild->right != NULL && leftchild->right != curr){
                    leftchild = leftchild->right;
                }
                if(leftchild->right == NULL){
                    res.push_back(curr->val);
                    //make right of rightmost node of lefchild points to curr
                    leftchild->right = curr;
                    //move left without destroying the tree
                    curr = curr->left;
                }else{
                    //remove the previous connection 
                    leftchild->right = NULL;
                    curr = curr->right;
                }
            }
        }  
        return res;
    }
};
