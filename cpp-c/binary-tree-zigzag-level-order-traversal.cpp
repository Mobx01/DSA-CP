/*Leetcode ps-103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 */




/* Approach - Breadth-First Search with Double-Ended Queue Direction Toggling / Binary Tree Zigzag Level Order Traversal (Time: O(N), Space: O(W))
 * Basically, we completely annihilate brute-force two-pass collection or explicit array reversals by aggressively leveraging a double-ended queue (`std::deque`) to extract and insert nodes in alternating directions per level in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Deque Directional Traversal Invariant (LeetCode 103 - Binary Tree Zigzag Level Order Traversal)! By maintaining a boolean flag `reverse` and alternating between front/back queue operations, we can build the zigzag level order traversal dynamically without needing a separate `std::reverse` pass.
 * - (Queue Management): When moving left-to-right (`!reverse`), we pop from the front and push children to the back (`left` then `right`). When moving right-to-left (`reverse`), we pop from the back and push children to the front (`right` then `left`), ensuring the next level's elements are ordered correctly for the opposite traversal direction.
 * - (Optimal Complexity): Visiting every node exactly once takes $O(N)$ time, and auxiliary space is bounded by the maximum tree width $O(W)$ for the deque storage.
 * * How it runs:
 * First, we handle edge cases with an empty root, initializing our result vector and a `std::deque` containing the root node.
 * We run a level-by-level `while(!dq.empty())` loop, tracking the current level size.
 * Depending on the `reverse` flag, we pop from the appropriate end of the deque, append to the `level` vector, and push child nodes accordingly.
 * Finally, we toggle the `reverse` flag, push the completed level vector to `res`, and flush the final traversal matrix to the output stream with absolute mathematical precision at raw silicon speed!
 */




**
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool reverse = false;

        while(!dq.empty()){
            int size = dq.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                if(!reverse){
                    TreeNode* node = dq.front(); dq.pop_front();
                    level.push_back(node->val);
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }else{
                    TreeNode* node = dq.back();dq.pop_back();
                    level.push_back(node->val);
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
            }
            res.push_back(level);
            reverse = !reverse;
        }
        return res;
    }
};
