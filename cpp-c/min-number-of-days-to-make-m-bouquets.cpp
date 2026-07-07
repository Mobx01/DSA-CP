/*Leetcode ps - 1482. Minimum Number of Days to Make m Bouquets
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.*/


/* Approach - Binary Search on Answer (Time: O(N log D), Space: O(N)) where D is max(bloomDay) - min(bloomDay)
 * Basically, we use binary search to guess the minimum number of days required, validating each guess by simulating the garden's bloom state to see if enough continuous bouquets can be formed.
 * * Observation:
 * - The relationship between time and blooming flowers is strictly monotonic. If we have enough flowers on day X, we will definitely have enough on day X + 1. This makes it a textbook scenario for binary search.
 * - A bouquet strictly requires 'k' *adjacent* flowers. Thus, any unbloomed flower instantly breaks the continuous streak of usable flowers.
 * - (Note on Space: Your 'ispossible' function currently takes the 'garden' vector by value, which creates a brand new O(N) copy of the array every single time it is called! Passing it by const reference and counting streaks inline without modifying the array would optimize this to O(1) space.)
 * * How it runs:
 * First, we perform an immediate sanity check: if the total absolute flowers needed ((long long)m * k) is strictly greater than the garden size (n), we return -1 since it is mathematically impossible.
 * Then, we set our binary search boundaries from the absolute minimum to the absolute maximum values found in 'bloomDay' and start our while loop to guess a 'mid' day.
 * Next, we pass our guessed day into 'ispossible'. It sweeps through its copy of the garden, flagging flowers as 1 (bloomed) or 0 (unbloomed). It sweeps a second time, accumulating streaks of adjacent 1s. Every time a streak perfectly hits 'k', it counts a valid bouquet and artificially resets the streak to 0 to prevent reusing flowers!
 * Finally, if the guess successfully yielded enough bouquets, we save 'mid' as our potential answer and pull our upper bound 'r' down to hunt for an even earlier day. If it failed, we push 'l' up to wait for more flowers to bloom.
 */

class Solution {
public:
    bool ispossible(int day, vector<int> garden, int m , int k){
        int n = garden.size(), bouq = 0;
        
        // make value 1 if flower is bloomed else 0
        for(int i = 0; i < n; i++){
            if(day >= garden[i]) garden[i] = 1;
            else garden[i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            if(i > 0 && garden[i-1] != 0 && garden[i] != 0) {
                garden[i] += garden[i-1];
            }

            if(garden[i] >= k){
                garden[i] = 0; // this flower can't be used again
                bouq++;
            }
        }
        return (bouq >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int ans = -1; 
    
        if((long long)m * k > n) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end()); 
        int r = *max_element(bloomDay.begin(), bloomDay.end()); 
        
        //binary search to find minimum number of days 
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(ispossible(mid, bloomDay, m, k)){ // look for less days
                ans = mid;
                r = mid - 1;
            } else { // look for more days
                l = mid + 1;
            }
        }
        return ans;
    }
};
