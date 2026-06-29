/*Codeforces PS - 1900A. Cover in Water

Filip has a row of cells, some of which are blocked, and some are empty. He wants all empty cells to have water in them. He has two actions at his disposal:
1 — place water in an empty cell.
2 — remove water from a cell and place it in any other empty cell.

If at some moment cell i (2 ≤ i ≤ n−1) is empty and both cells i−1 and i+1 contains water, then it becomes filled with water. Find the minimum number of times he needs to perform action 1 in order to fill all empty cells with water. Note that you don't need to minimize the use of action 2. Note that blocked cells neither contain water nor can Filip place water in them.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 100). The description of the test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the number of cells.
The next line contains a string s of length n. The i-th character of s is '.' if the cell i is empty and '#' if cell i is blocked.

Output
For each test case, output a single number — the minimal amount of actions 1 needed to fill all empty cells with water.
*/

/* Approach - Logic & Observation
 * Basically, the entire solution relies on a core observation about how we can exploit consecutive empty spaces to generate an infinite water source.
 * Observation: 
 * - If we have at least 3 consecutive empty cells ("..."), we can place water in the two outer cells. This creates a permanent water source in the middle that we can continuously scoop from to fill every other empty cell in the entire array! Therefore, the minimum cost is always exactly 2.
 * - If there are never 3 consecutive empty cells anywhere, we can't create this infinite source. We are forced to manually place water into every single empty cell one by one, meaning the cost is just the total count of empty cells.
 *
 * How it runs:
 * First, we loop through our array of characters.
 * During the loop, we keep a running 'count' of every empty cell ('.') we see. Simultaneously, we check if the current cell and the next two cells form our magic "..." pattern.
 * If we spot that 3-cell pattern, we immediately set a flag ('consec3') to 1 and break out of the loop early, because we already know the optimal answer!
 * Finally, we check our flag: if we found the pattern, we return 2. Otherwise, we return the total 'count' of empty cells we tallied up.
 */

#include<iostream>
#include<vector>

using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<char> nums(n);
    for(int i =0;i<n;i++){
        cin >> nums[i];
    }

    // if there are 3 consecutive blanks we can fill 2 of the side ones to get unlimited water in middle one 
    // thats way we can fill all using only 2. else we need to fill all blanks using extra water

    int consec3 =0,count =0;
    for(int i =0;i<n;i++){
        if(nums[i] == '.' && nums[i+1] == '.' && nums[i+2] == '.'){
            consec3 = 1;
            break;
        }
        if(nums[i] == '.') count++;
    }

    return (consec3 == 1) ? 2 : count; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
       cout << solve() << endl;
    }
    return 0;
}
