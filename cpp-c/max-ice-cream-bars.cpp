/* Leetcode ps - 1833. Maximum Ice Cream Bars
It is a sweltering summer day, and a boy wants to buy some ice cream bars.
At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
Note: The boy can buy the ice cream bars in any order.
Return the maximum number of ice cream bars the boy can buy with coins coins.
You must solve the problem by counting sort. */

/* * Approach: Greedy + Sorting
 * * To maximize the number of ice cream bars, it makes the most sense to 
 * buy the cheapest ones first. 
 * * 1. Sort the 'costs' array in ascending order.
 * 2. Loop through the sorted array.
 * 3. For each ice cream, check if we have enough 'coins' to buy it.
 * 4. If yes, deduct the cost from 'coins', bump the buy count, and move forward.
 * 5. If no (or if coins run out), break the loop. Since the array is sorted, 
 * we know we definitely can't afford any of the remaining bars.
 * 6. Return the total count.
 *
 * Time Complexity: O(N \log N) due to std::sort.
 * Space Complexity: O(\log N) for the sorting stack in C++.
 */




class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i = 0,count=0,n=costs.size();
        while(coins >= 0){
            if(i < n && costs[i] <= coins){
                count++;
                coins -= costs[i];
                i++;
            }else{
                break;
            }
        }
        return count;
    }
};
