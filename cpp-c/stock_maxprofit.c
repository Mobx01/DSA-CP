/* LeetCode PS-121 
  You are given an array prices where prices[i] is the price of a given stock on the ith day.
  You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
  Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
/*Intuition
    Greedy approach(according to me🙂)
    Track the minimum price so far (best day to buy).
    Compute profit if you sell today.
    Keep the maximum profit seen.

Approach
  Initialize:
    minPrice = prices[0]
    maxProfit = 0
    Traverse from day 1 to n-1
    At each day:
    If current price is smaller → update minPrice
    calculate profit and update maxProfit

Complexity
  Time complexity:
   O(n)
  Space complexity:
   O(1)

*/
int maxProfit(int* prices, int pricesSize) {
    int maxprofit =  0  , minprice = prices[0];
    for(int i = 0 ; i < pricesSize ; i++){
        if(prices[i] < minprice) minprice = prices[i];
        int profit = prices[i] - minprice ;
        if(profit > maxprofit) maxprofit = profit ;
    }
    return maxprofit ;
}
