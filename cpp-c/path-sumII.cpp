/*leetcode ps-113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.*/




/* Approach - Recursive Depth-First Search Path Collection with Value Accumulation / Path Sum II (Time: O(N * H) or O(N log N), Space: O(H))
 * Basically, we completely annihilate brute-force post-processing by aggressively building and passing path vectors down the recursion stack, collecting all valid root-to-leaf paths that equal the target sum in pristine linear/logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Root-to-Leaf Path Collection Invariant (LeetCode 113 - Path Sum II)! As we traverse the tree, we maintain both the running `sum` and a local `path` vector (passed by value so each branch maintains its independent path history). When a leaf node is reached, if `sum == S`, we push the accumulated `path` vector into our global `res` collection.
 * - (Value Passing Overhead Note): Because `vector<int> path` is passed by value in `solve`, copying the path vector at each recursive call introduces an overhead of $O(H)$ per node, bringing total time complexity to $O(N \cdot H)$ (where $H$ is tree height). Passing `path` by reference and backtracking (`path.pop_back()`) optimizes this to strict $O(N)$ time!
 * - (Optimal Complexity): Auxiliary stack space is bounded by the tree height $O(H)$, and storage for the output paths scales with the number of valid target paths.
 * * How it runs:
 * First, `pathSum` initializes an empty `path` vector and invokes the recursive `solve` function starting at the root.
 * Inside `solve`, we handle null nodes, add the current node value to `sum`, and append it to `path`.
 * When a leaf node is reached, we check if `sum == S`, adding the path to `res` if matched. Otherwise, we recursively explore the left and right subtrees.
 * Finally, we flush the collected path matrix to the output stream with absolute mathematical precision at raw silicon speed!
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
    vector<vector<int>> res;
    void solve(TreeNode* root,int S,int sum,vector<int> path){
        if(!root){
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(sum == S){
                res.push_back(path);
            }else return;
        }
        solve(root->left,S,sum,path);
        solve(root->right,S,sum,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root,targetSum,0,path);
        return res;
    }
};
