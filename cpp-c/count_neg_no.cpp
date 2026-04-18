/* LeetCode PS 1351 :- Count Negative Numbers in a Sorted Matrix
   Given a m x n matrix grid which is sorted in non-increasing order both row-wise
   and column-wise, return the number of negative numbers in grid.

  #Intuition
  
    Each row of the grid is sorted in non-increasing order.
    If we reverse a row, all the negative numbers come first.
    Then we can simply count negatives from the beginning
    until a non-negative number is encountered.

  #Approach
  
    Traverse each row of the grid.
    Reverse the current row so negative numbers move to the front.
    Start from index 0 and count elements while they are negative.
    Stop as soon as a non-negative number appears.
    Repeat this for all rows and accumulate the count.

  #Complexity
  
    Time Complexity: O(m × n)
    (Reversing and scanning each row)

    Space Complexity: O(1)
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            reverse(grid[i].begin(), grid[i].end());

            int j = 0;
            while (j < grid[i].size() && grid[i][j] < 0) {
                count++;
                j++;
            }
        }
        return count;
    }
};
