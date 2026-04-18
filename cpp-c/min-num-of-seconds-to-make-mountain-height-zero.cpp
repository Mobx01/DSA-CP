/*Leetcode ps- 3296. Minimum Number of Seconds to Make Mountain Height Zero
You are given an integer mountainHeight denoting the height of a mountain.
You are also given an integer array workerTimes representing the work time of workers in seconds.
The workers work simultaneously to reduce the height of the mountain. For worker i:
To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.
To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, and so on.
Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.*/

/* ALGORITHM SUMMARY: "Binary Search on the Answer"
           
           1. OBJECTIVE: Find the minimum time 'T' such that all workers combined 
              can reduce the mountain height to 0.
              
           2. OUTER BINARY SEARCH (Time): 
              - We "guess" a total time (midt).
              - If the guess is enough to finish the mountain, we try a smaller time.
              - If not, we must increase the time.

           3. INNER CALCULATION (Capacity per Worker):
              - For each worker, we calculate the max height they can contribute 
                within the current "guessed" time (midt).
              - Since a worker takes baseTime * (h*(h+1)/2) to reduce height 'h',
                we use an inner binary search to find the largest 'h' that 
                fits within 'midt'.

           4. TERMINATION: 
              - Sum up all workers' capacities. If sum >= mountainHeight, the 
                time is valid. The search narrows down to find the smallest valid T.
*/
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // Sorting is optional but helps with the 'break' optimization
        sort(workerTimes.begin(), workerTimes.end());
        
        long long lowt = 0; // 0 is a possible time
        long long hight = 1e16; 
        long long minreqtime = hight;

        while(lowt <= hight){
            long long midt = lowt + (hight - lowt) / 2;
            long long totalhred = 0; // Use long long for total height

            for(int btime : workerTimes){
                long long lowh = 0;
                long long highh = mountainHeight;
                long long maxh_for_this_worker = 0;

                // Inner Binary Search to find max height for THIS worker
                while(lowh <= highh){
                    long long midh = lowh + (highh - lowh) / 2;
                    // Correct formula: (btime * midh * (midh + 1)) / 2
                    long long timereq = (long long)btime * midh * (midh + 1) / 2;
                    
                    if(timereq <= midt){
                        maxh_for_this_worker = midh;
                        lowh = midh + 1;
                    } else {
                        highh = midh - 1;
                    }
                }
                
                // Add the result AFTER the inner loop finishes
                totalhred += maxh_for_this_worker;
                if(totalhred >= mountainHeight) break;
            }

            if(totalhred >= mountainHeight){
                minreqtime = midt;
                hight = midt - 1;
            } else {
                lowt = midt + 1;
            }
        }
        return minreqtime;
    }
};
