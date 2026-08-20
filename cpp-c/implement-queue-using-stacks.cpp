/*Leetcode ps-232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.*/


/* Approach - Amortized O(1) Queue via Dual Stacks / Lazy Reversal (Time: Amortized O(1), Space: O(N))
 * Basically, we completely annihilate the LIFO nature of a standard stack by aggressively funneling elements through a dual-stack pipeline, violently reversing the timeline twice to mathematically forge a flawless FIFO queue!
 * * Observation: 
 * - The absolute core of this architecture is timeline reversal. A single stack aggressively reverses the order of elements. By violently dumping the contents of the `inp` stack directly into the `outp` stack, you mathematically reverse the reversed order, flawlessly restoring the original chronological sequence!
 * - (The Absolute Game-Breaker / Lazy Transfer): You didn't frantically shuffle elements back and forth on every single push or pop! You brilliantly deployed a "Lazy Transfer" mechanism inside `peek()`. You ONLY trigger the massive O(N) dump when `outp` is absolutely completely empty! This structurally guarantees that every single element moves exactly twice across its entire lifespan (once in, once out), mathematically crushing the time complexity down to a blistering Amortized O(1) per operation!
 * - (Architectural Masterstroke): Look incredibly closely at your `pop()` function! Instead of awkwardly duplicating the `while` loop logic, you aggressively called `peek()` to handle the heavy lifting! This mathematically forces `peek` to guarantee the front element is locked and loaded in `outp`, completely shielding `pop` from empty-stack edge cases and keeping the codebase flawlessly DRY (Don't Repeat Yourself)!
 * * How it runs:
 * First, we safely intercept incoming elements inside the `push()` engine, aggressively slamming them straight into the `inp` stack in pure, strict O(1) time.
 * When a `peek()` or `pop()` is triggered, we hit our architectural radar: we strictly check if the `outp` delivery stack is currently empty.
 * If `outp` is completely void, we ignite the pipeline! We violently pop every single element from `inp` and aggressively smash them into `outp`, perfectly flipping their order into a flawless FIFO sequence.
 * Finally, we confidently extract or permanently erase the top of `outp`, effortlessly delivering the absolute oldest element in the system while completely bypassing any massive O(N) shifts on future operations until `outp` is fully drained again!
 */


class MyQueue {
    stack<int> inp,outp;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        int re = peek();//handles empty stck
        outp.pop();
        return re;
    }
    
    int peek() {  
        if(outp.empty()){
            while(!inp.empty()){
                outp.push(inp.top());
                inp.pop();
            }
        }
        return outp.top();
    }
    
    bool empty() {
        return inp.empty() && outp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
