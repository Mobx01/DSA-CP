/*Leetcode ps - 1861. Rotating the Box
You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:
A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. 
Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.
Return an n x m matrix representing the box after the rotation described above.*/


/*
 * APPROACH:
 * Two simple steps: 
 * 1. Let gravity do its job first, then 2. Rotate the box.
 * 
 * Step 1: Apply Gravity (Move stones to the right)
 * Instead of rotating the box first and trying to drop stones downwards (which is tricky), 
 * it's much easier to just slide all the stones to the right side of their current row.
 * - We look at each row individually.
 * - We use a two-pointer technique, starting from the rightmost side (end of the row).
 * - 'emptyPos' keeps track of the best available empty spot on the right.
 * - We scan the row backwards (right to left):
 *     - If we see an obstacle ('*'): Stones can't fall past it, so we reset 'emptyPos' 
 *       to be the space immediately to the left of this obstacle.
 *     - If we see a stone ('#'): We swap it into our 'emptyPos' and then shift our 
 *       'emptyPos' tracker one step to the left so the next stone can stack behind it.
 *     - If we see an empty space ('.'): We do nothing and just keep scanning.
 * 
 * Step 2: Rotate the Box 90 Degrees Clockwise
 * - Now that all stones have "fallen" to the right, we just rotate the whole grid.
 * - An original grid of size [m rows] x [n cols] will become [n rows] x [m cols].
 * - To rotate 90 degrees clockwise, an item at original position [i][j] 
 *   gets placed at position [j][m - 1 - i] in the new rotated grid.
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();    // rows
        int n = boxGrid[0].size(); // columns
        
        // Apply gravity to each row first (stones fall to the right)
        for (int i = 0; i < m; ++i) {
            int emptyPos = n - 1; // Tbottom of the array (when rotated)
            
            // j is pointer moving bottm to top
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    // obstacle - reset the empty space pointer to just above it
                    emptyPos = j - 1;
                } 
                else if (boxGrid[i][j] == '#') {
                    // stone - swap it into the lowest empty space
                    swap(boxGrid[i][j], boxGrid[i][emptyPos]);
                    emptyPos--; // Move the empty pointer up
                }
            }
        }
        
        // Rotate the grid 90 degrees clockwise
        // m x n -> n x m grid.
        // for 90-deg clockwise: rotated[j][m - 1 - i] = original[i][j]
        vector<vector<char>> rotated(n, vector<char>(m));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return rotated;
    }
};
