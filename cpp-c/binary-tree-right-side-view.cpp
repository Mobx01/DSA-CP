/*Leetcode ps-199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.*/




/* Approach - Level Order BFS with Rightmost Node Extraction / Binary Tree Right Side View (Time: O(N), Space: O(W))
 * Basically, we completely annihilate brute-force depth-tracking recursion by aggressively leveraging level-order queue iteration to capture the final node at every depth level in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Level-Width Terminal Invariant (LeetCode 199 - Binary Tree Right Side View)! By processing the queue level by level (where `siz = q.size()`), the last node processed in each level (`i == siz - 1`) is guaranteed to be the rightmost visible node from that vertical perspective. Pushing children (`left` then `right`) ensures the queue correctly sequences the next level from left to right.
 * - (Optimal Queue Utilization): Using a standard `std::queue` with explicit level size batching keeps memory and traversal overhead exceptionally lean.
 * - (Space Complexity Footprint): The auxiliary space is bounded by the maximum tree width $W$ (up to $O(N)$ in the worst-case balanced binary tree layout), while time complexity remains optimal at $O(N)$.
 * * How it runs:
 * First, we validate that the root is non-null and initialize our `res` vector along with our BFS `queue`.
 * We ignite a high-speed `while(!q.empty())` loop tracking the current level's size `siz`.
 * We iterate through all nodes in the current level, capturing the value of the final node (`i == siz - 1`) into `res`, and pushing non-null child nodes into the queue.
 * Finally, we flush the resulting right-side view vector to the output stream with absolute mathematical precision at raw silicon speed!
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int siz = q.size();
            
            for(int i=0;i<siz;i++){
                TreeNode* node = q.front();
                q.pop();

                if(i == siz-1)res.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
