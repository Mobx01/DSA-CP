/*
    APPROACH: Depth First Search
    1. Base Cases (When do we stop?):
       - Out of Bounds: If our jump takes us off the board (idx < 0 or idx >= n), 
         we hit a dead end. Return false.
       - Already Visited: If we land on a tile and its value is negative, it means 
         we've been here before. We return false so we don't get stuck in an infinite loop!
       - Jackpot!: If the tile we land on is exactly 0, we won! Return true.

    2. Leaving Breadcrumbs (Marking Visited):
       - To avoid infinite loops, we need a way to remember where we've been. 
       - Instead of creating a whole new 'visited' array (which takes extra space), 
         we use a clever trick: we multiply the current tile's value by -1. 
       - So, if we are on a 3, we change it to -3. This leaves a "breadcrumb" 
         for our future selves.

    3. The Jumps (Branching out):
       - From our current tile, we try two paths: 
         Path A: Jump forward (current index + value)
         Path B: Jump backward (current index - value)
       - *Note on the math trick:* Because we just made the value negative (e.g., -3), 
         adding it actually moves us backward, and subtracting it moves us forward. 
         The order doesn't matter, we still explore both exact same spots!

    4. The Final Verdict:
       - We just return (Path A || Path B). Meaning, if ANY of the paths eventually 
         finds a 0, the whole function returns true!
*/

class Solution {
public:
    int n ;
    
    bool solve(vector<int>& arr, int idx ){
        if(idx > n -1 || idx < 0 || arr[idx] < 0) return false;
        if(arr[idx] == 0) return true; // if 0 found return true;
        
        arr[idx] *= -1; // marking visited
        
        bool a = solve(arr , idx + arr[idx]); // check one direction
        bool b = solve(arr , idx - arr[idx]); // check the other direction
        
        return a||b; // if any one is true then return true
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return solve(arr , start);
    }
};
