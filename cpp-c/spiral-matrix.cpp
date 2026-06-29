/*Leetcode ps- 54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.*/


/* Approach - Boundary Simulation (space complexity O(1))
 * Basically, we simulate the exact path of a spiral by walking through the matrix and artificially shrinking the traversable boundaries inward every time we finish walking along an outer edge.
 * We keep a few main variables to track our limits and state: 
 * - 'upbound', 'rbound', 'dbound', 'lbound' act as our walls that slowly close in towards the center as we peel off the outer layers of the matrix.
 * - 'dir' acts as a state machine tracking our current direction of travel (0: Right, 1: Down, 2: Left, 3: Up).
 *
 * How it runs:
 * First, we initialize our boundary walls to the literal edges of the matrix and start our traversal at the top-left corner moving Right.
 * Then, we enter a loop that runs until we've collected every single element (when our answer array size reaches m * n).
 * At each step, we push the current number into our answer array. 
 * Next, we check our current 'dir'. If we haven't hit the corresponding wall in our path, we simply take one step forward.
 * If we *do* hit a wall, we rotate our direction 90 degrees clockwise, take one step in that new direction, and permanently shrink the wall we just finished walking against so we never cross into that peeled layer again!
 */


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        int upbound = 0, rbound = n - 1, lbound = 0, dbound = m - 1; 
        int dir = 0; // 0: Right, 1: Down, 2: Left, 3: Up
        
        vector<int> ans;

        while(ans.size() < m * n) {
            ans.push_back(matrix[i][j]);

            if(dir == 0) { // moving RIGHT (i == upbound)
               if(j == rbound) { // hit right wall, turn down
                   dir = 1;
                   i++;
                   upbound++; // update the upperbound
               } else { // keep moving right
                   j++;
               }
            } else if(dir == 1) { // moving DOWN (j == rbound)
                if(i == dbound) { // hit bottom wall, turn left
                   dir = 2;
                   j--;
                   rbound--; // update the right bound
                } else { // keep moving down
                   i++;
                }
            } else if(dir == 2) { // moving LEFT (i == dbound)
                if(j == lbound) { // hit left wall, turn up
                   dir = 3;
                   i--;
                   dbound--; // update the down bound
                } else { // keep moving left
                    j--;
                }
            } else if(dir == 3) { // moving UP (j == lbound)
                if(i == upbound) { // hit top wall, turn right
                    dir = 0;
                    j++;
                    lbound++; // update the left bound
                } else {
                    i--;
                }
            }    
        }
        return ans;
    }
};
