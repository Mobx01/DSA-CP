/*Leetcode ps- 1914. Cyclically Rotating a Grid
You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
Return the matrix after applying k cyclic rotations to it.*/


/*
 * Approach:
 * Trying to shift elements around in a 2D matrix is a headache. Instead, we "peel" 
 * the grid layer by layer, flatten each layer into a 1D array, shift that, and 
 * write it back.
 * 
 * 1. Find the layers: A grid has min(rows, cols) / 2 concentric rings.
 *    For any layer 'i', the boundaries are top=i, left=i, bottom=rows-i-1, right=cols-i-1.
 *
 * 2. Flatten to 1D: Walk the perimeter clockwise (Top -> Right -> Bottom -> Left) 
 *    and push all the values into a simple 1D array. 
 *
 * 3. Modulo the shifts: 'k' can be huge. Rotating a 10-element ring 12 times is 
 *    the exact same as rotating it 2 times. So, actual shifts = k % array_size.
 *
 * 4. Write it back: Because we are rotating counter-clockwise, the element that 
 *    ends up at the very start (top-left) is just 'k' steps forward in our 
 *    clockwise 1D array. 
 *    So, we just walk the 2D grid clockwise again, but fill the cells with values 
 *    from our 1D array starting at index 'k' (wrapping back to 0 when we hit the end).
 */

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        int tlayer = min(n, m) / 2;
        
        for(int i = 0; i < tlayer; i++) {
            vector<int> elem;

            int top = i;
            int left = i;
            int bottom = n - i - 1;
            int right = m - i - 1;

            // extract layer into a linear array(clockwise)
            // Top row
            for(int c = left; c <= right; c++) elem.push_back(grid[top][c]);
            // Right column 
            for(int r = top + 1; r <= bottom; r++) elem.push_back(grid[r][right]);
            // Bottom row 
            for(int c = right - 1; c >= left; c--) elem.push_back(grid[bottom][c]);
            // Left column 
            for(int r = bottom - 1; r >= top + 1; r--) elem.push_back(grid[r][left]);

            int size = elem.size();
            
            int idx = k % size; // effective rotations needed (1 circle of perimeter make effective 0)

            // clockwise traversal
            // Top row
            for(int c = left; c <= right; c++) {
                grid[top][c] = elem[idx];
                idx = (idx + 1) % size;
            }
            // Right column
            for(int r = top + 1; r <= bottom; r++) {
                grid[r][right] = elem[idx];
                idx = (idx + 1) % size;
            }
            // Bottom row
            for(int c = right - 1; c >= left; c--) {
                grid[bottom][c] = elem[idx];
                idx = (idx + 1) % size;
            }
            // Left column
            for(int r = bottom - 1; r >= top + 1; r--) {
                grid[r][left] = elem[idx];
                idx = (idx + 1) % size;
            }
        }
        
        return grid;
    }
};
