/*Leetcode ps- 2095. Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.*/


/*
### Approach: Fast and Slow Pointers (The "Tortoise and Hare")
Finding the middle of a linked list can be tricky because we don't know the total length upfront. To solve this efficiently in a single pass, we use a clever trick with two pointers traveling at different speeds.
Think of it like a race: if one runner goes exactly twice as fast as another, by the time the fast runner crosses the finish line, the slow runner will be exactly at the halfway mark!

**1. Handle Edge Cases**
If the list is completely empty, or if it only has one single node, deleting the "middle" leaves us with nothing. In this case, we just return `nullptr`.

**2. The Starting Line**
* **`slow` pointer:** Starts at the very beginning (`head`).
* **`fast` pointer:** Starts two steps ahead (`head->next->next`). 
  *(Why the head start? Because we want the `slow` pointer to stop exactly ONE node BEFORE the actual middle node. If it stopped directly on the middle node, we wouldn't be able to change the pointer of the node before it!)*

**3. The Race**
We loop through the list. Every time the `slow` pointer takes 1 step forward, the `fast` pointer takes 2 steps. We keep going until the `fast` pointer reaches the very end of the list (or reaches the last node).

**4. Bypassing the Middle**
Once the loop finishes, our `slow` pointer is sitting directly in front of the middle node. To remove the middle node from the list, we simply rewire the connection. We tell the `slow` pointer to completely skip the next node and point to the one after it (`slow->next = slow->next->next`). 
Now the middle node is disconnected from the chain, and we can safely return the `head` of our modified list.
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Just return nullptr, don't delete head
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;//moves 1 step at a time
        ListNode* fast = head->next->next; //moves 2 step at a time
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Simply bypass the middle node to disconnect it from the list
        slow->next = slow->next->next;
        

        
        return head;
    }
};
