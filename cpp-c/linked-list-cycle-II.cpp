/*Leetcode ps-142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.*/


/* Approach - Fast & Slow Pointers / Floyd's Cycle Detection (Time: O(N), Space: O(1))
 * Basically, we deploy two pointers moving at different speeds to first mathematically prove a cycle exists, and then use a brilliant distance property to pinpoint exactly where the cycle begins!
 * * Observation: 
 * - The first phase is standard cycle detection: a 'rab' (fast pointer) moving twice as fast as a 'tort' (slow pointer) will inevitably lap the slow pointer and crash into it if a loop exists.
 * - The true magic happens in the second phase! Due to the math of the speeds and distances, the moment the two pointers collide inside the loop, the distance from the absolute `head` of the list to the start of the cycle is perfectly identical to the distance from their collision point to the start of the cycle.
 * - By instantly teleporting the 'tort' back to the start line (`head`) and slowing the 'rab' down so both only take one step at a time, they are absolutely guaranteed to flawlessly meet again exactly at the cycle's entrance!
 * - The `head == nullptr || head->next == nullptr` base case safely handles completely empty lists or single disconnected nodes, preventing any immediate out-of-bounds crashes.
 * * How it runs:
 * First, we safely check our extreme base cases. If the list is empty or too short to loop, a cycle is impossible, so we instantly return `nullptr`.
 * Then, we place both our 'tort' and 'rab' pointers squarely at the starting line (the `head`).
 * Next, we trigger our fast-paced while loop. In every single iteration, 'tort' takes one deliberate step while 'rab' aggressively leaps two steps ahead.
 * If 'rab' ever collides with 'tort' (`rab == tort`), we freeze! We instantly reset 'tort' all the way back to the `head`. Then, we trigger a second loop to march both pointers forward at the exact same speed (one step at a time). The exact node where they collide for the second time is our cycle entrance, and we confidently return it!
 * Finally, if 'rab' completely breaks free and hits a `nullptr` during the initial chase, it means the list is a straight line with absolutely no cycle, so we safely return `nullptr`!
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* tort = head;
        ListNode* rab = head;
        while(rab != nullptr && rab->next != nullptr){
            rab = rab->next->next;
            tort = tort->next;
            if(rab == tort){
                tort = head;
                while(tort != rab){
                    tort = tort->next;
                    rab = rab->next;
                }
                return tort;
            }
        }
        return nullptr;
    }
};
