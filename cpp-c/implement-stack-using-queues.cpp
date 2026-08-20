/*Leetcode ps -225. Implement Stack using Queues
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:
You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/


/* Approach - Single-Queue Rotation / Structural Inversion (Time: Push O(N), Pop/Top O(1), Space: O(N))
 * Basically, we completely annihilate the need for a secondary data structure by aggressively rotating a single queue in a perfect circle, violently forcing the newest element straight to the front to perfectly mimic LIFO architecture!
 * * Observation: 
 * - The absolute core of this architecture is the inversion of behavior. A standard queue is naturally FIFO (First-In, First-Out). To mathematically force it into LIFO (Last-In, First-Out), we have to physically invert the internal ordering every single time a new element drops in!
 * - (The Absolute Game-Breaker): You brilliantly bypassed the classic two-queue juggling approach! Instead of shifting data between two separate structures, you aggressively lock in the exact size `s` of the queue *before* the new element enters. Once the new element is shoved into the back, you ruthlessly pop the `s` old elements from the front and instantly smash them back into the rear! This structurally buries the old elements behind the new one, locking the newest element exactly at the absolute front!
 * - (The Complexity Trade-off): This specific design violently shifts the computational burden! `pop()` and `top()` execute in absolute peak O(1) time because the exact target is already perfectly positioned at the front. The sacrifice is `push()`, which takes a mathematically guaranteed O(N) hit because the entire queue structure must be aggressively rotated upon every single insertion!
 * * How it runs:
 * First, we safely intercept the incoming element `x` during a `push` operation. We instantly extract and lock the current queue size into a volatile variable `s`.
 * We aggressively inject `x` straight into the rear of our `qu`!
 * Then, we ignite the high-speed rotation engine! For exactly `s` iterations, we violently rip the front element out (`qu.pop()`) and instantly shove it right back into the rear (`qu.push()`)!
 * The exact millisecond the rotation loop finishes, the newly inserted `x` has mathematically bubbled directly to the front of the line!
 * Finally, whenever `pop()` or `top()` are triggered, we confidently reach straight into the front of the queue, completely bypassing any complex search logic, flawlessly extracting the top of the stack in a blistering O(1) CPU cycle!
 */


class MyStack {
    queue<int> qu;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = qu.size();
        qu.push(x);
        
        
        //Bring the newly added element 'x' to the front!
        for (int i = 0; i < s; i++) {
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop() {
        int topElement = qu.front(); // top is in front
        qu.pop();       
        return topElement;        
    }
    
    int top() {
        return qu.front();           
    }
    
    bool empty() {
        return qu.empty();          
    }
};
