/*Leetcode ps- 1665. Minimum Initial Energy to Finish Tasks
You are given an array tasks where tasks[i] = [actuali, minimumi]:

actuali is the actual amount of energy you spend to finish the ith task.
minimumi is the minimum amount of energy you require to begin the ith task.
For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.
You can finish the tasks in any order you like.
Return the minimum initial amount of energy you will need to finish all the tasks.*/

/*
 * Approach: Sorting + Binary Search on Answer
 * 
 * The main trick is realizing the optimal order to do the tasks. We want to prioritize
 * tasks that demand a high minimum energy to start, but actually consume very little. 
 * This leaves us with the biggest possible energy "buffer" for the remaining tasks.
 * 
 * 1. Sorting: 
 *    We sort the tasks in descending order based on the difference: (minimum - actual).
 *    Tackling the ones with the largest gap first ensures we clear the biggest hurdles 
 *    early on while our energy pool is at its maximum.
 * 
 * 2. Binary Search: 
 *    Instead of trying to calculate the exact starting energy backwards, it's easier 
 *    to just guess a starting energy and verify if it works. Since the valid answers 
 *    are monotonic (if energy X works, X+1 will also work), we can binary search it.
 *    - Left bound (l): The minimum energy of the first sorted task (we absolutely 
 *      need at least this much to even start).
 *    - Right bound (r): A safe upper limit, which is the sum of all actual costs 
 *      plus the left bound.
 * 
 * 3. Simulation (isPossible):
 *    We use the helper function to simulate going through the tasks with our guessed 
 *    starting energy (`mid`). 
 *    - If we survive all tasks, this amount works. We record it, but check the left 
 *      half to see if we can get away with even less.
 *    - If we run out of energy, our guess was too low. We check the right half.
 */


class Solution {
public:

    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for(auto &task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if(minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();


        int result = INT_MAX;

        auto lambda = [](auto &task1, auto& task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);
        int rval = 0;
        for(int i =0 ;i<n;i++){
            rval += tasks[i][0];
        }
        int l = tasks[0][1];
        int r = rval + l;

        // binary search
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
