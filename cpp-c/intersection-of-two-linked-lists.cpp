/*Leetcode ps-160. Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:
The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.*/

/* Approach - Two Stacks / LIFO Backtracking (Time: O(N + M), Space: O(N + M))
 * Basically, we push every single node from both linked lists into two separate stacks, allowing us to effortlessly traverse them completely backwards to pinpoint the exact node where their paths diverge!
 * * Observation: 
 * - If two singly linked lists physically intersect, their chains permanently merge, mathematically guaranteeing they will absolutely share the exact same tail!
 * - Because standard linked lists only allow forward traversal, finding the starting point of the merge is tricky. By leveraging the Last-In-First-Out (LIFO) property of stacks, we can magically read both lists backwards from their shared absolute end!
 * - (Optimization Note: While this stack approach perfectly solves the logic, it burns a heavy O(N + M) auxiliary memory to store all those pointers! You can brilliantly optimize this down to a flawless O(1) space by deploying a two-pointer technique—where each pointer traverses its own list and then dynamically swaps to the opposite head—mathematically guaranteeing they collide exactly at the intersection!)
 * * How it runs:
 * First, we deploy two independent while loops to sweep through `headA` and `headB`, aggressively pushing every single node directly into `stk1` and `stk2` until both lists are completely exhausted.
 * Then, we securely initialize our `last` pointer by peeking at the absolute tops of both stacks. (If these absolute tail nodes do not perfectly match, an intersection is structurally impossible, and it correctly defaults to `nullptr`).
 * Next, we trigger our synchronization loop to continuously pop nodes off both stacks at the exact same time. We fiercely check the top elements: if they mismatch, it means we have successfully backed out of the shared chain, so we instantly return our `last` recorded match!
 * Finally, if they perfectly match, we securely lock that node into `last`, safely pop them both off, and step backwards until we confidently isolate the exact intersection entrance!
 */


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        
        while (headA != NULL) {
            stk1.push(headA);
            headA = headA->next;
        }
        while (headB != NULL) {
            stk2.push(headB);
            headB = headB->next;
        }

        ListNode* last = ((!stk1.empty() && !stk2.empty() && stk1.top() == stk2.top()) ? stk1.top() : nullptr);
        
        while (!stk1.empty() && !stk2.empty()) {
            if (stk1.top() != stk2.top()) {
                return last; 
            }
            
            last = stk1.top();
            stk1.pop();
            stk2.pop();
        }
        
        
        return last;
    }
};
