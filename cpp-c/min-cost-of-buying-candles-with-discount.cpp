/*Leetcode ps - 2144. Minimum Cost of Buying Candies With Discount
A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.
The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.
For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

*/

/*
 * APPROACH: "Buy 2, Get 1 Free" Strategy
 * 
 * To save the most money, you want your FREE candies to be the most 
 * expensive ones possible. The store rule usually says the free item 
 * must be cheaper or equal to the ones you bought.
 * 
 * 1. Sort the Candies:
 *    First, we use `sort()` to organize the candy prices in ascending 
 *    order (cheapest at the start, most expensive at the end).
 * 
 * 2. Start from the Most Expensive (Loop Backwards):
 *    To get the biggest freebies, we need to buy the most expensive 
 *    candies first. We do this by looping backwards from the end of 
 *    the array (i = n - 1 down to 0).
 * 
 * 3. Use a Tracker to Count to 3:
 *    We use a `tracker` variable to count our group of 3 candies.
 *    - Candy 1 (tracker = 1): We buy it. Add its price to mincost.
 *    - Candy 2 (tracker = 2): We buy it. Add its price to mincost.
 *    - Candy 3 (tracker = 3): This is our FREE candy! Because of our 
 *      loop, this is the 3rd most expensive candy in our current group. 
 *      We skip adding its cost, and reset the tracker back to 1.
 */

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int mincost = 0,n=cost.size(),tracker =1;
        for(int i = n-1 ; i >=0 ;i--){
            if(tracker == 3){
                tracker =1;
                continue;
            }
            tracker++;
            mincost += cost[i];
        }

        return mincost;
    }
};
