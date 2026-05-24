/*Leetcode ps -  1340. Jump Game V
Given an array of integers arr and an integer d. In one step you can jump from index i to index:
i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).
You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.
Notice that you can not jump outside of the array at any time.*/


/*
 * APPROACH: Depth-First Search (DFS) with Memoization (Top-Down DP)
 *
 * 1. The Core Idea:
 *    Think of this problem like trying to find the longest path downhill. From any 
 *    building, you want to explore all valid jumps to the left and right, and choose 
 *    the jump that leads to the highest number of subsequent jumps.
 * 
 * 2. Why Memoization?
 *    Imagine we calculate the maximum jumps from building at index 3. Later, if we 
 *    jump to building 3 from building 5, we don't want to recalculate the whole path 
 *    for building 3 again. We store (memoize) the result in an array `t` to save time.
 *    - `t[i] = -1` means we haven't calculated the max jumps for index `i` yet.
 *    - `t[i] != -1` means we already know the answer, so we just return it.
 *
 * 3. Step-by-Step Breakdown:
 *    - In `maxJumps`: We loop through the array to try starting our journey from 
 *      EVERY single building `i`, keeping track of the overall maximum jumps.
 *    - In `solve`: For a given building `i`, we always count it as 1 jump (just 
 *      standing there).
 *    - Look Left: We check up to `d` steps to the left. 
 *      * If we encounter a building taller than or equal to our current one, we 
 *        STOP looking further left. It blocks our path (acts as a barrier).
 *      * If it's strictly smaller, we simulate jumping there and use recursion 
 *        `solve(...)` to see how many jumps we can make from there.
 *    - Look Right: We do the exact same thing, looking up to `d` steps to the right.
 *    - We update `result` with the highest jump count we found, save it in `t[i]`, 
 *      and return it.
 *
 * Time Complexity: O(N * d) - We visit each of the N buildings once. At each building, 
 *                             we check at most `d` steps left and `d` steps right.
 * Space Complexity: O(N) - Used by the memoization array `t` and the recursion stack.
 */


class Solution {
public:
    int n ;
    vector<int> t;//(vector for memoization)
    int solve(vector<int>& arr, int i,int d){
        if(t[i] != -1) return t[i];
        int result = 1;//current index
        //check left -> i-1,i-2,...i-d
        for(int j=i-1;j>= max(0,i-d);j--){
            if(arr[j] >= arr[i]) break; //can go further becuase arr[j] acts as a barrier

            result = max(result,1+solve(arr,j,d));
        } 
        //check right -> i+1,i+2,...i+d
        for(int j=i+1;j <= min(n-1,i+d);j++){
            if(arr[j] >= arr[i]) break; //can go further becuase arr[j] acts as a barrier

            result = max(result,1+solve(arr,j,d));
        }
        return t[i]=result;
    }
    int maxJumps(vector<int>& arr, int d) {
        int result = 1;
        n = arr.size();
        t.resize(n+1,-1);//initilizing with value -1
        for(int i =0;i<n;i++){//try all possible start points
            result=max(result,solve(arr,i,d));
        }
        return result;
    }
};
