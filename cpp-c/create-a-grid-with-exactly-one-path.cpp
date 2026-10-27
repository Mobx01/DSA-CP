/*Leetcode ps-3963. Create Grid With Exactly One Path
You are given two integers m and n, representing the number of rows and columns of a grid.
Construct any m x n grid consisting only of the characters '.' and '#', where:
'.' represents a free cell.
'#' represents an obstacle cell.
A valid path is a sequence of free cells that:
Starts at the top-left cell (0, 0).
Ends at the bottom-right cell (m - 1, n - 1).
Moves only:
Right, from (i, j) to (i, j + 1), or
Down, from (i, j) to (i + 1, j).
Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.*/



/* Approach - Deterministic Perimeter Path Construction (Time: O(M * N), Space: O(1) auxiliary)
 * Basically, we completely annihilate complex state searches by aggressively filling the grid with obstacles ('#') and carving out a single L-shaped open path along the top row and rightmost column in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Single-Boundary Routing Invariant! To guarantee *exactly one* valid path from `(0, 0)` to `(m - 1, n - 1)` moving only right and down, we initialize the entire grid with blocks (`'#'`), and open up a unique corridor: the entire first row and the entire last column set to `'.'`. 
 * - (Uniqueness Guarantee): Because all interior cells and alternate routes are blocked by `'#'`, the traversal is forced to move exclusively right across the top row and then down the final column, yielding a foolproof, single valid path regardless of grid dimensions.
 * - (Optimal Time & Space Efficiency): Constructing the grid takes $O(M \times N)$ time with $O(1)$ auxiliary memory beyond the output vector storage.
 * * How it runs:
 * First, we initialize an $M \times N$ grid filled entirely with obstacle characters (`'#'`).
 * We set all elements in the first row to free cells (`'.'`) and all elements in the last column to free cells (`'.'`).
 * Finally, we flush the constructed grid vector to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        for(int i=0;i<m-1;i++){
            string a = ".";
            for(int j=0;j<n-1;j++){
                a += '#';
            }
            ans.push_back(a);
        }
        string a(n,'.');
        ans.push_back(a);
        return ans;
    }
};
