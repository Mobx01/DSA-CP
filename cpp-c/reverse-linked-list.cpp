/*Leetcode ps-206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.*/


/* Approach - Stack-Based Reversal / LIFO Pointer Tracking (Time: O(N), Space: O(N))
 * Basically, we use the Last-In-First-Out (LIFO) property of a stack to naturally reverse the order of the linked list by pushing all the nodes in sequence and popping them out backwards!
 * * Observation: 
 * - A stack is physically designed for reversing sequences. By pushing every single node pointer into the stack as we traverse the list, the absolute tail of the original list ends up perfectly at the very top!
 * - While this flawlessly re-links the nodes, it comes at the heavy cost of O(N) auxiliary space to store all the pointers. (Optimization Note: The most optimal way to reverse a list is iteratively using just three pointers—prev, curr, next—which brilliantly drops the space complexity down to a strict O(1)!)
 * - Explicitly terminating the list by setting `curr->next = nullptr` at the very end is an absolutely crucial, non-negotiable step. Without it, the original head node would still point to its original next node, creating a catastrophic infinite cycle!
 * * How it runs:
 * First, we safely handle our extreme base cases: if the list is completely empty or only has a single node, it is already theoretically reversed, so we instantly return the `head`.
 * Then, we sweep through the original linked list, pushing every single node pointer directly onto our `stk` until we reach the absolute end (`head == nullptr`).
 * Next, we grab the very top element of the stack, pop it off, and securely lock it in as our official `newHead`. We also deploy a `curr` pointer here to dynamically rebuild the rest of the chain.
 * Finally, we trigger a while loop to continuously link `curr->next` to the next element on top of the stack, stepping our `curr` pointer forward and popping until the stack is completely empty. We forcefully cap the tail with `curr->next = nullptr` and confidently return our `newHead`!
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        stack<ListNode*> stk;
        while(head != nullptr){
            stk.push(head);
            head = head->next;
        }
        
      
        ListNode* newHead = stk.top();
        stk.pop();
        

        ListNode* curr = newHead; 
        
        while(!stk.empty()){
            curr->next = stk.top(); 
            curr = curr->next;      
            stk.pop(); 
        }
        
     
        curr->next = nullptr; 
        
        return newHead;
    }
};
