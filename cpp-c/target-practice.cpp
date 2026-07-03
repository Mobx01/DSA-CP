/*Codeforces PS - 1873C. Target Practice

A 10×10 target is made out of five "rings" as shown. Each ring has a different point value: the outermost ring — 1 point, the next ring — 2 points, ..., the center ring — 5 points.

Vlad fired several arrows at the target. Help him determine how many points he got.

Input
The input consists of multiple test cases. The first line of the input contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case consists of 10 lines, each containing 10 characters. Each character in the grid is either X (representing an arrow) or . (representing no arrow).

Output
For each test case, output a single integer — the total number of points of the arrows.
*/


/* Approach - Matrix Traversal & Ring Scoring
 * Basically, we read a fixed 10x10 grid and assign a score to every 'X' based on which concentric ring of the target it lands in.
 * Observation: 
 * - The score of an 'X' purely depends on how close it is to the outer edge of the grid. 
 * - The outermost layer (row or column 0 or 9) is worth exactly 1 point. If we peel that away, the next inner layer (row or column 1 or 8) is worth 2 points. This concentric pattern continues perfectly up to the 5-point center!
 * - By checking the coordinates layer by layer from the outside in, we can easily map any position to its correct ring score using simple bounds checking.
 *
 * How it runs:
 * First, we initialize a 10x10 2D array and read all the characters into it.
 * Then, we use a nested loop to check every single cell (i, j) in the grid.
 * When we find a cell containing an 'X', we use a cascading if-else structure to evaluate its position. We check if it touches the outermost edge (i == 0 or 9, j == 0 or 9) and add 1 to our sum if it does. If it doesn't, it must be further inside, so we check the next inner boundary for 2 points, and so on.
 * Finally, if the 'X' didn't trigger any of the outer 4 boundary checks, it must be in the direct center 2x2 square, so we simply add 5 to our sum. After the loops finish, we return the total score!
 */

#include<iostream>
#include<vector>
using namespace std;

int solve(){
    int sum=0,temp,n=10;
    vector<vector<char>> nums(n,vector<char>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> nums[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(nums[i][j] == 'X'){
                if((i == 0) || (i == n-1) || (j == 0) || (j == n-1) ) 
                  sum += 1;
                else if((i == 1 ) || (i ==  n-2) || ( j == 1) || (j == n-2))
                  sum += 2;
                else if((i == 2 ) || (i ==  n-3) || ( j == 2) || (j == n-3))
                  sum += 3;
                else if((i == 3 ) || (i ==  n-4) || ( j == 3) || (j == n-4))
                  sum += 4;
                else sum += 5;
            }
        }
    }
    return sum;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
       cout << solve() <<endl;
    }

    return 0;
}
