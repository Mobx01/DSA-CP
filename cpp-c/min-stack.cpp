/*Leetcode ps-155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

/* Approach - Dual Stack Synchronization / Monotonic State Tracking (Time: O(1), Space: O(N))
 * Basically, we completely annihilate the need to scan the array for minimums by aggressively syncing a parallel shadow stack, violently locking in the absolute minimum state at every single point in the timeline!
 * * Observation: 
 * - The absolute core of this architecture is the secondary `smin` stack. It mathematically functions as a strict, monotonically decreasing state tracker. It ONLY records history when a completely new minimum is forged or matched!
 * - (The Absolute Game-Breaker / Duplicate Safety): Look incredibly closely at the condition `value <= smin.top()` in your push engine! That `=` sign is an absolute mathematical lifesaver! If you push duplicate minimums (e.g., 5, 2, 2) without it, popping the first '2' would catastrophically erase the minimum for the remaining '2'! You brilliantly prevented this timeline collapse by securely logging the duplicate!
 * - (Optimization Alert / The O(1) Space Annihilation): Your dual-stack architecture is logically flawless and perfectly achieves O(1) time complexity, but it aggressively burns O(N) auxiliary space for the `smin` shadow stack! You can completely destroy `smin` and achieve absolute peak O(1) space by deploying the classic mathematical formula `2LL * value - min_val`! By forcefully encoding the previous minimum into a massive 64-bit integer stored directly inside the main stack, you can mathematically decrypt it on the fly during a pop, completely bypassing the need for any secondary memory structures!
 * * How it runs:
 * First, we safely intercept the incoming `value`. We aggressively hit our synchronization radar: if our shadow stack `smin` is completely void, or the new value mathematically dominates (or exactly equals) the current minimum, we violently slam it into `smin`!
 * We then securely push the raw value into the main `stk` engine.
 * When a `pop()` is triggered, we ignite a strict equality check. We forcefully compare the absolute top of `stk` against `smin.top()`. 
 * If they are a perfect match, it proves the current global minimum is being violently ejected from the timeline, so we aggressively pop it from `smin` as well to perfectly resync the state!
 * Finally, we simply execute standard `stk.pop()`, safely restoring the previous historical state and guaranteeing that `getMin()` consistently returns the absolute lowest value in blistering O(1) hardware speed!
 */

class MinStack {
    stack<int> stk, smin;
public:
    MinStack() {
    }
    
    void push(int value) {
        if(smin.empty() || value <= smin.top()) {
            smin.push(value);
        }
        stk.push(value);
    }
    
    void pop() {
        if(smin.top() == stk.top()){
            smin.pop(); 
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
