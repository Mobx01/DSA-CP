/*leetcode ps - 118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:*/

/* Approach - Row-by-Row Construction (space complexity O(numRows^2))
 * Basically, we build Pascal's triangle from the top down, calculating each new row based on the values computed in the immediately preceding row.
 * We keep 2 main structures to track this:
 * - 'pas' is the main 2D array (vector of vectors) that stores the complete history of all rows we've built so far.
 * - 'temp' is a temporary 1D array we use to construct the current row before saving it into 'pas'.
 *
 * How it runs:
 * First, we start an outer loop 'i' to build exactly 'numRows' rows. We know that the 'i'-th row (0-indexed) will always have exactly 'i + 1' elements.
 * For each row, we initialize our 'temp' array and immediately set the very first (index 0) and very last (index i) elements to 1, because the edges of Pascal's triangle are always 1.
 * Next, we use an inner loop 'j' to fill in the middle elements (from index 1 to i-1). We calculate each element by looking back at the previous row ('pas[i-1]') and adding the two numbers directly above our current position: the one up-and-left ('pas[i-1][j-1]') and the one straight up ('pas[i-1][j]').
 * Finally, once the 'temp' row is completely calculated, we push it into our main 'pas' matrix and move on to the next row!
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas;
        // size formula for ith row = i+1. (assuming i to be 0th indexed)
        for(int i =0 ;i<numRows;i++){
            vector<int> temp(i+1);
            temp[0] = 1;temp[i] = 1;//first and last element of row is always 1
            for(int j =1 ; j<i;j++){
                temp[j] = pas[i-1][j-1] + pas[i-1][j];
            }
            pas.push_back(temp);
        }
        return pas;
    }
};
