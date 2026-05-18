/*Leetcode ps- 1345. Jump Game IV
Given an array of integers arr, you are initially positioned at the first index of the array.
In one step you can jump from index i to index:
i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.*/


/* 
    APPROACH: BREADTH-FIRST SEARCH (BFS):

    1. Group Similar Values (The "Teleporters"):
       We can jump between any two indices that have the exact same value. 
       To do this quickly, we use a Hash Map (unordered_map). 
       Key = the number in the array. 
       Value = a list (vector) of all indices where this number appears.

    2. Keep Track of Where We've Been:
       We use a `visited` array to remember the indices we have already checked. 
       This prevents us from jumping back and forth infinitely between the same spots.

    3. Set Up the BFS (The Queue):
       We use a queue to keep track of our current positions. 
       We start by pushing index 0 into the queue and marking it as visited.
       We also keep a `step` counter starting at 0.

    4. Explore Level by Level:
       We check how many elements are currently in the queue (`size`). 
       This size represents all the positions we can reach at our current `step`.
       We loop through all these positions before incrementing our `step` counter.

    5. Make the Jumps (The 3 Rules):
       For the current index (`cur`), we try to jump to:
       a) The previous index: `cur - 1` (if it exists and isn't visited).
       b) The next index: `cur + 1` (if it exists and isn't visited).
       c) Any "teleport" index: All other indices that share the same value `arr[cur]`.

    6. THE CRUCIAL OPTIMIZATION (Preventing Time Limit Exceeded):
       `mp.erase(arr[cur]);`
       Once we have explored all the "teleport" links for a specific number (e.g., all 
       the 7s in the array), we do NOT need to check them ever again. Erasing the 
       list of indices for this number from our map ensures we don't waste time looping 
       through them later.

    7. Reaching the Goal:
       The moment our current index (`cur`) is equal to `n - 1` (the last index), 
       we immediately return our `step` count. Because we are using BFS, this is 
       guaranteed to be the minimum number of steps.
*/


class Solution {
public:a
    int minJumps(vector<int>& arr) {
        int n = arr.size(); // goal index = n-1

        unordered_map<int , vector<int>> mp;//store all index of a value
        vector<bool> visited(n,false);//ensures every element is visited once

        for(int i =0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        //apply bfs
        queue<int> qu;
        qu.push(0);//start bfs from index 0
        visited[0]=true;//first index visisted(starting point)
        int step =0 ;
        while(!qu.empty()){
            int size = qu.size();

            while(size--){
                int cur = qu.front();
                qu.pop();

                int left = cur-1;
                int right = cur+1;

                if(cur == n-1)return step;//if reached end return no of steps
                if(left >= 0 && !visited[left]){//explore i-1
                    qu.push(left);
                    visited[left] = true;//mark as visited
                }
                if(right < n && !visited[right]){//explore i+1
                    qu.push(right);
                    visited[right] = true;//mark as visited
                }


                for(int &idx : mp[arr[cur]] ){//explore all indexes where current element is present
                    if(!visited[idx]){
                        qu.push(idx);
                        visited[idx] = true;//mark as visitwed
                    }
                }
                mp.erase(arr[cur]);
            }
            step++;
        }
        return -1;
    }
};
