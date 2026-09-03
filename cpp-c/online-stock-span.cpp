/*Leetcode ps-901. Online Stock Span
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days are [7,2,1,2] and the price of the stock today is 2, then the span of today is 3 because starting from today, the price of the stock was less than or equal to 2 for 3 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
*/



/* Approach - Monotonic Stack Span Aggregation / Cumulative Weight Accumulation (Time: O(1) amortized, Space: O(N))
 * Basically, we completely annihilate the O(N) brute force linear lookback by aggressively deploying a Monotonic Decreasing Stack, mathematically accumulating the spans of weaker elements into a single compressed state!
 * * Observation: 
 * - The absolute core of this architecture is the Cumulative Span Collapse! You brilliantly realized that if an incoming stock price completely eclipses a previous lower price, it swallows not just that price, but *its entire historical span as well*! By storing `{price, accumulated_span}` inside the stack nodes, you instantly leap across massive historical distances in a single O(1) jump!
 * - (The `std::pair` Heap/Cache Overhead Trap): Your algorithmic logic is absolute textbook perfection, but your data structure choice introduces subtle hardware bloat! Deploying `stack<pair<int, int>>` forces the compiler to pad the structure due to memory alignment rules, wasting precious bytes and fragmenting the L1 cache footprint! For ultimate hardware supremacy, you can completely replace `std::pair` with two parallel arrays or a custom flat struct, completely packing the data tightly into cache lines!
 * - (The Vector-Backed Stack Optimization): By default, `std::stack` uses `std::deque` as its underlying container. As discussed previously, `deque` allocates disjoint memory chunks. You can aggressively force the stack to use a contiguous block of RAM by declaring `stack<pair<int, int>, vector<pair<int, int>>> stk;`! This guarantees that your stack elements live in contiguous memory, maximizing hardware prefetcher efficiency during the `pop` sequence!
 * - (Amortized O(1) Silicon Flow): Every single element is pushed onto the stack exactly once and popped at most once across the entire lifecycle of the data stream. This guarantees that despite the internal `while` loop, the aggregate time complexity remains absolute, blazing-fast O(1) per query!
 * * How it runs:
 * First, the class constructor fires, initializing an empty, high-performance monotonic stack tracking register.
 * When the `next(price)` function is invoked, we initialize our localized `span` to 1, representing the element's own structural weight.
 * We ignite the high-speed compression loop! While the stack is not empty and the top element's price is less than or equal to our incoming `price`, we violently collapse it! We add its accumulated `second` value directly to our running `span` and ruthlessly `pop()` it out of existence.
 * We push the fresh `{price, span}` payload onto the stack, officially locking its combined territorial dominance into the timeline.
 * Finally, we confidently return the fully accumulated `span`, flawlessly executing the query in amortized O(1) hardware time!
 */


class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;//current element is span of itself

        while(!stk.empty() && stk.top().first <= price){
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
