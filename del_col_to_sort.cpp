/* LeetCode PS :- 944    Delete Columns to Make Sorted
   You are given an array of n strings strs, all of the same length.
   The strings can be arranged such that there is one on each line, making a grid.
     Return the number of columns that you will delete.

  #Intuition
  
    So the idea is simple:
    Check each column independently.
    If any column violates the non-decreasing order, that column must be deleted.
  
  #Approach
    Iterate over each column.
    For the current column, compare adjacent rows.
    If strs[i][j] < strs[i-1][j] for any i, mark the column as invalid.
    Increment the count and move to the next column.
  
  #Complexity
    Time Complexity:  O(n.m) 
    where n is the number of strings and m is the length of each string.
  
    Space Complexity: O(1)
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0 ;
        int row = strs.size();
        int column = strs[0].size();
        for(int i = 0 ; i < column ; i ++){
            for(int j = 1 ; j < row ;j++){
                if(strs[j-1][i] > strs[j][i]) {
                    count++ ;
                    break ;
                }
            }
        }
    return count ;
}

};
