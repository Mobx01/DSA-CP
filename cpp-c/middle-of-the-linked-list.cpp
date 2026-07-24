/*Leetcode ps-876. Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.*/


/* Approach - Fast and Slow Pointers / Tortoise & Hare (Time: O(N), Space: O(1))
 * Basically, we use two pointers traveling at different speeds so that when the fast pointer reaches the absolute end of the linked list, the slow pointer lands perfectly in the exact middle!
 * * Observation: 
 * - If we tried to find the middle using a standard approach, we would have to traverse the entire list once just to count the total nodes, and then completely traverse it a second time to reach the halfway point.
 * - By launching a 'rabbit' (fast pointer) that moves exactly twice as fast as a 'tort' (slow pointer), the slow pointer will mathematically always cover exactly half the total distance by the time the fast pointer hits the finish line!
 * - The while loop condition `rabbit != NULL && rabbit->next != NULL` is beautifully designed to safely protect us from null pointer exceptions. It flawlessly handles both odd-length lists (where rabbit lands exactly on the last node) and even-length lists (where rabbit steps completely off the edge), naturally ensuring the slow pointer lands on the second middle node in the even case.
 * * How it runs:
 * First, we handle the extreme base case: if the list only has a single node (`head->next == NULL`), we instantly return the head.
 * Then, we place both our 'tort' and 'rabbit' pointers squarely at the starting line (the `head` of the list).
 * Next, we trigger our while loop to drive the pointers forward. In every single iteration, the 'tort' takes one deliberate step (`tort->next`), while the 'rabbit' aggressively leaps two steps ahead (`rabbit->next->next`).
 * Finally, the exact moment the 'rabbit' can no longer make a full two-step jump without crashing, the loop breaks. Our 'tort' is now parked precisely at the target middle node, and we confidently return it!
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL )return head;
        ListNode* tort = head;
        ListNode* rabbit = head;
        while(rabbit != NULL && rabbit->next != NULL){
            tort = tort->next;
            rabbit = rabbit->next->next;
        }
        return tort;
    }
};
