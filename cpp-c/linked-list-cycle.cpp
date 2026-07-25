/*Leetcode ps-141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.*/


/* Approach - Fast & Slow Pointers / Floyd's Cycle Detection (Time: O(N), Space: O(1))
 * Basically, we deploy two pointers racing through the linked list at different speeds, mathematically guaranteeing that if a loop exists, the faster one will inevitably lap and crash into the slower one!
 * * Observation: 
 * - A standard linked list strictly ends at a `nullptr`. If there is a cycle, there is absolutely no end, meaning traversals will theoretically run forever.
 * - By having a 'rab' (fast pointer) leap two steps for every single step the 'tort' (slow pointer) takes, the distance between them mathematically shrinks by exactly one node per iteration once they are both trapped inside the loop!
 * - This means they are absolutely guaranteed to perfectly collide if a cycle exists. It completely eliminates the need for a memory-heavy hash set to track visited nodes, dropping our space complexity to a flawless O(1)!
 * - The `head == nullptr || head->next == nullptr` check instantly filters out physical impossibilities like completely empty lists or isolated single nodes.
 * * How it runs:
 * First, we safely verify our extreme base cases. If the list is empty or too short to physically loop back on itself, a cycle is impossible, so we instantly return false.
 * Then, we place both our 'tort' and 'rab' pointers squarely at the starting line (the `head` of the list).
 * Next, we trigger our high-speed while loop. We fiercely check that 'rab' and its immediate next step are entirely valid (`!= nullptr`) to flawlessly prevent any fatal out-of-bounds crashes.
 * Inside the loop, 'rab' aggressively bounds forward two steps while 'tort' takes one deliberate step. The exact moment their memory addresses perfectly align (`rab == tort`), we definitively prove a cycle exists and confidently return true!
 * Finally, if 'rab' successfully breaks out of the loop by hitting a dead-end `nullptr`, we mathematically prove the list is just a straight line and safely return false!
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode* tort = head;
        ListNode* rab = head;

        while(rab != nullptr && rab->next != nullptr){
            rab = rab->next->next;
            tort = tort->next;
            if(rab == tort) return true;
        }
        return false;
    }
};
