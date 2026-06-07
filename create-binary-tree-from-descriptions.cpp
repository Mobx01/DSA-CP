/*Leetcode ps - 2196. Create Binary Tree From Descriptions
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid*/


// Approach: 
// Step 1: The Setup
// - We need a quick way to find nodes we've already created, so we use a hash map (`tree`).
// - We also need a way to find the "Root". The root is special because it is the only 
//   node in the entire tree that is never a child. To track this, we use a hash set 
//   (`children`) to keep a list of every node that has a parent.

// Step 2: Building the Connections
// We loop through the instructions one by one.
// - If the parent or child node doesn't exist in our map yet, we create it.
// - We connect the child to the parent's left or right side based on the `isLeft` flag.
// - Most importantly: We add the child to our `children` set so we remember it isn't the root.

// Step 3: Finding the Root
// Now that the tree is fully connected, we just do one final loop through the instructions.
// - We look at every parent and check if it exists in our `children` set.
// - The first parent we find that is NOT in the `children` set is the absolute top 
//   of the tree. We return that node.

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
   
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> tree;//stores node of certain value
        unordered_set<int> children;
        for(auto& des : descriptions){
            // parent = des[0] , child = des[1]
            //if node already doesnt exist create them.
            if(!tree.count(des[0])) tree[des[0]] = new TreeNode(des[0]);
            if(!tree.count(des[1])) tree[des[1]] = new TreeNode(des[1]);

            //check if its left child or right
            if(des[2]){
                tree[des[0]]->left=tree[des[1]];
            }else{
                tree[des[0]]->right=tree[des[1]];
            }
            children.insert(des[1]);
        }
        for(auto& des : descriptions){
            if(!children.count(des[0])){
                return tree[des[0]];
            }
        }
        return nullptr;
    }
};

