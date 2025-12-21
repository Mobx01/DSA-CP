/* LeetCode PS :- 960    Delete Columns to Make Sorted II
   You are given an array of n strings strs, all of the same length.
   The strings can be arranged such that there is one on each line, making a grid.
   You may delete any number of columns.
   Return the minimum number of columns to delete so that the rows are in
   lexicographical order.
  
  # Intuition
  
    The idea is to process the strings column by column from left to right.
    If keeping a column breaks the order between any two adjacent strings,
    that column must be deleted.
    If a column confirms the correct order for a pair of strings,
    we can remember that and ignore this pair in future columns.
  
  # Approach
  
    Maintain a boolean array to track which adjacent row pairs
    are already sorted.
    Traverse each column from left to right.
    For the current column:
      - Check all adjacent row pairs that are not yet sorted.
      - If any pair violates the order, delete the column.
    If the column is valid:
      - Mark pairs as sorted where the order is confirmed.
    Continue until all columns are processed.
  
  # Complexity
  
    Time Complexity:  O(rows × columns)
    We check every column and compare adjacent rows.
  
    Space Complexity: O(rows)
    Extra space is used to track sorted row pairs.
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int row = strs.size();
        int column = strs[0].size();
        
        vector<bool> alreadysorted(row - 1, false);

        for (int i = 0; i < column; i++) {
            bool del = false;

            // Check if current column breaks ordering
            for (int j = 0; j < row - 1; j++) {
                if (!alreadysorted[j] && strs[j][i] > strs[j + 1][i]) {
                    count++;
                    del = true;
                    break;
                }
            }

            if (del) continue;

            // Update sorted pairs
            for (int k = 0; k < row - 1; k++) {
                if (strs[k][i] < strs[k + 1][i]) {
                    alreadysorted[k] = true;
                }
            }
        }
        return count;
    }
};
