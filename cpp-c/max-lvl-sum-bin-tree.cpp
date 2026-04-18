/*Leetcode ps - 1161 Maximum Level Sum of a Binary Tree
  Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
  Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

  approch :-
  do bfs of tree at each lvl cal sum of elements and compare with maximum sum which is updated if sum is greater 
  than maxsum. keep updating the result level on basis of sum and maximum sum(sum is greater 
  than maxsum) . initallize the maxsum= INT_MIN for avoiding any possible conflict.
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
    int maxLevelSum(TreeNode* root) {
        int maxsum = INT_MIN;
        int reslvl = 0 ;
        queue<TreeNode*> que;
        que.push(root);
        int curlvl= 1;
        while(!que.empty()){
            int n = que.size();
            int sum =0 ;
            while(n--){;
                TreeNode* temp = que.front();
                que.pop();
                sum += temp->val;
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }

            }
            if(sum > maxsum){
                maxsum = sum;
                reslvl = curlvl;
            }
            curlvl ++ ;
        }
        return reslvl ; 
    }
};
