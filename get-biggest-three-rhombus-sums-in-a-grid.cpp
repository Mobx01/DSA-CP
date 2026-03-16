/*Leetcode ps- 1878. Get Biggest Three Rhombus Sums in a Grid
You are given an m x n integer matrix grid​​​.
A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. 
Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.*/

/*
Approach:

1. Maintain the top 3 distinct rhombus sums.
   - Use a vector 'res' of size 3 initialized with INT_MIN.
   - Create a helper function 'update(res, val)' that:
        • Ignores duplicate values.
        • Inserts the value in descending order if it belongs in top 3.
        • Shifts elements to keep only the largest three values.

2. Traverse every cell (i, j) of the grid.
   - Each cell can act as the center of a rhombus.

3. Handle rhombus of size 0.
   - A rhombus of size 0 is just the single cell itself.
   - Insert grid[i][j] into the result using update().

4. Expand rhombus size k around the center.
   - Increase k while the rhombus remains inside the grid:
        i-k >= 0
        i+k < n
        j-k >= 0
        j+k < m

5. For each valid k, compute the rhombus border sum.
   - Traverse the four edges:
        • Top → Right
        • Right → Bottom
        • Bottom → Left
        • Left → Top
   - Add all border elements to get the rhombus perimeter sum.

6. Update the top three results.
   - Pass the computed sum to update(res, sum).

7. Finally, remove unused INT_MIN values and return the remaining elements.

Time Complexity:
O(n * m * min(n, m))
*/

class Solution {
public:

    void update(vector<int>& res, int val){
        
        // check duplicate
        for(int x : res)
            if(x == val) return;

        for(int i = 0; i < 3; i++){
            if(val > res[i]){
                for(int j = 2; j > i; j--)
                    res[j] = res[j-1];
                res[i] = val;
                return;
            }
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> res(3, INT_MIN);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                update(res, grid[i][j]);

                for(int k = 1; i-k >= 0 && i+k < n && j-k >= 0 && j+k < m; k++){

                    int sum = 0;

                    // top -> right
                    for(int s=0; s<k; s++)
                        sum += grid[i-k+s][j+s];

                    // right -> bottom
                    for(int s=0; s<k; s++)
                        sum += grid[i+s][j+k-s];

                    // bottom -> left
                    for(int s=0; s<k; s++)
                        sum += grid[i+k-s][j-s];

                    // left -> top
                    for(int s=0; s<k; s++)
                        sum += grid[i-s][j-k+s];

                    update(res, sum);
                }
            }
        }

        vector<int> ans;
        for(int x : res)
            if(x != INT_MIN)
                ans.push_back(x);

        return ans;
    }
};
