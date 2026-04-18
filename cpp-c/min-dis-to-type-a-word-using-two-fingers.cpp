/*Leetcode ps - 1320. Minimum Distance to Type a Word Using Two Fingers

You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.
For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

*/
//raw approach -  assume the given 2d array as 1d array like a...f g....l m.. . cur = index at which letter is situated a=0,b=1...
// so x coordinate of any letter is cur%6- because in 2d array each row has 6 char and when we make that 2d array 3d x coordinate comes after multiple of 6.
// and y cord = cur/6 - new row start after 6 char.

/*
Approach: Top-Down Dynamic Programming (Memoization)

1. State: We track 3 variables at any time: 
   - `i`: Current index in the word.
   - `f1`: Position of finger 1 (0-25 for A-Z, 26 means not placed yet).
   - `f2`: Position of finger 2 (0-25 for A-Z, 26 means not placed yet).

2. Distance Math: We map a 1D index back to a 2D grid:
   - X-coordinate = index % 6
   - Y-coordinate = index / 6
   - If a finger is unplaced (value 26), moving it to its first letter is free (distance = 0).

3. The Core Logic (Choices): At every letter, we test two paths:
   - Path 1: Move Finger 1 to the current letter.
   - Path 2: Move Finger 2 to the current letter.
   
4. Optimization: We return the minimum distance between the two paths and store that answer in a 3D array `t[i][f1][f2]`. If we hit that exact state again, we just return the saved answer instead of recalculating.
*/

class Solution {
public:
    int t[301][27][27]; // memo array
    int caldis(int p1 , int p2){
        if(p1 == 26 || p2 == 26) return 0;//if finger not useed initially return 0;
        int x1 = p1%6, x2=p2%6;
        int y1 = p1/6 , y2 =p2/6;

        return abs(x1-x2) + abs(y1-y2);
    }
    int solve(int i , int f1 ,int f2,string &word){
        if(i == word.size())return 0;

        if(t[i][f1][f2] != -1) return t[i][f1][f2];


        int cur = word[i] - 'A'; //in 1d array characters index
        int m1 = caldis(f1,cur) + solve(i+1,cur,f2,word);
        int m2 = caldis(f2,cur) + solve(i+1 ,f1,cur,word);

        return t[i][f1][f2] = min(m1,m2);

    }
    int minimumDistance(string word) {
        for(int i = 0 ; i < 301;i++){
            for(int j = 0;j<27;j++){
                for(int k = 0 ;k<27;k++){
                    t[i][j][k] = -1; // intialzing memo array;
                }
            }
        }
        return solve(0,26,26,word); // 26 because finger is not used initially
    }
};
