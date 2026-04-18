/*2075. Decode the Slanted Ciphertext
A string originalText is encoded using a slanted transposition cipher to a string encodedText with the help of a matrix having a fixed number of rows rows.
originalText is placed first in a top-left to bottom-right manner.
The blue cells are filled first, followed by the red cells, then the yellow cells, and so on, until we reach the end of originalText. The arrow indicates the order in which the cells are filled. All empty cells are filled with ' '. The number of columns is chosen such that the rightmost column will not be empty after filling in originalText.
encodedText is then formed by appending all characters of the matrix in a row-wise fashion.
The characters in the blue cells are appended first to encodedText, then the red cells, and so on, and finally the yellow cells. The arrow indicates the order in which the cells are accessed.
For example, if originalText = "cipher" and rows = 3, then we encode it in the following manner:
The blue arrows depict how originalText is placed in the matrix, and the red arrows denote the order in which encodedText is formed. In the above example, encodedText = "ch ie pr".
Given the encoded string encodedText and number of rows rows, return the original string originalText.
Note: originalText does not have any trailing spaces ' '. The test cases are generated such that there is only one possible originalText.*/

/*
Approach:
1. Compute number of columns = n / rows.
2. Fill a matrix row-wise using the encoded string.
3. Traverse the matrix diagonally:
   - Start from each column of the first row.
   - Move in direction (i+1, j+1) until out of bounds.
4. Append characters during traversal to form original text.
5. Remove trailing spaces from the final string.
*/


class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if(n == 0) return "";
        int col = n/rows;
        string orgtext ;

        vector<vector<char>> mat(rows, vector<char>(col));
        int k =0;
        for(int i= 0 ;i < rows ;i++){
            for(int j = 0; j<col ;j++){
                mat[i][j] = (encodedText[k]);
                k++;
            }
        }

        for(int j =0 ;j < col;j++){
            for(int i = 0;i<rows;i++){
                if(i <= rows -1 && j+i <= col - 1){
                    orgtext.push_back(mat[i][j+i]);
                }
            }
        }
        int m = orgtext.length();
        for(int i = m- 1;i>=0;i--){
            if(orgtext[i]== ' ') orgtext.pop_back();
            else break;
        }
        return orgtext;
    }
};
