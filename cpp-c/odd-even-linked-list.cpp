/*Leetcode ps-328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.*/

/* Approach - Two Pointers / Leapfrogging (Time: O(N), Space: O(1))
 * Basically, we use two separate pointers to simultaneously extract the odd-indexed and even-indexed nodes into their own isolated chains, and then physically stitch the head of the even chain straight to the absolute tail of the odd chain!
 * * Observation: 
 * - The problem explicitly asks us to group the nodes by their physical *indices* (1st, 2nd, 3rd node), absolutely not by the actual integer values stored inside them!
 * - Because odd and even nodes strictly alternate, an `odd` node's true next odd node is mathematically always sitting at `even->next`. By having our pointers leapfrog over each other, we elegantly decouple the single list into two separate, parallel tracks without needing any extra memory!
 * - Since we are completely severing the original connections as we unzip the list, we absolutely must save the starting point of the even list (`evenHead`) before we start traversing, otherwise it would be permanently lost in memory!
 * * How it runs:
 * First, we safely handle our extreme base cases: if the list is completely empty or has just a single isolated node, there is structurally nothing to rearrange, so we instantly return `head`.
 * Then, we deploy our starting positions: `odd` is anchored to the 1st node, `even` is anchored to the 2nd node, and we securely lock in `evenHead` to perfectly remember where the even chain begins.
 * Next, we trigger our high-speed while loop, fiercely checking `even != NULL && even->next != NULL` to protect us from fatal out-of-bounds crashes on both even and odd-length lists. 
 * Inside the loop, we leapfrog! We physically link the current `odd` node directly to the next available odd node (`even->next`) and step the `odd` pointer forward. We immediately mirror this exact same logic for the `even` node.
 * Finally, the exact moment the entire list is flawlessly unzipped, the loop breaks. We mathematically stitch the two halves back together by linking the absolute last `odd` node's next pointer directly to `evenHead`, and confidently return our original `head`!
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head; // 1st odd node
        ListNode* even = head->next; // 1st even node
        ListNode* evenHead = even; // save head of even list

        while(even != NULL && even->next != NULL) {
            odd->next = even->next; // connect curr odd to next odd node
            odd = odd->next;

            even->next = odd->next; // connect curr even to next even node
            even = even->next;
        }
        odd->next = evenHead; // attach even list after odd list
        return head;
    }
};
