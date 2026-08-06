/*Leetcode ps-25. Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.*/



/* Approach - Iterative In-Place Reversal / Block Chunking (Time: O(N), Space: O(1))
 * Basically, we aggressively scan ahead to secure perfect blocks of exactly 'k' nodes, ruthlessly sever their connections, and flawlessly reverse their internal pointers strictly in-place without using a single byte of auxiliary memory!
 * * Observation: 
 * - Reversing a linked list in chunks is notorious for completely losing track of the head and severing the list. Deploying a `dummy` node completely destroys the nightmare edge cases of the true `head` permanently shifting during the very first reversal!
 * - By launching a scout pointer (`getKthNode`) ahead before doing ANY physical work, we mathematically guarantee we NEVER accidentally reverse a leftover chunk smaller than `k`!
 * - (The Absolute Masterstroke): In a standard linked list reversal, you always initialize `prev = nullptr`. But here, you brilliantly initialized `prev = groupNext`! This flawlessly pre-stitches the tail of your newly reversed chunk directly to the remaining unreversed list, completely eliminating a massive headache of manual reconnections!
 * - (Memory Leak Alert): You dynamically allocated `new ListNode(0)` for your dummy node on the heap, but you NEVER called `delete dummy` before returning! In a strict C++ production environment, this causes a permanent memory leak! To instantly fix this and achieve true O(1) space, either allocate it strictly on the stack (`ListNode dummy(0);`) or explicitly capture the return head and `delete dummy`!
 * * How it runs:
 * First, we safely deploy our `dummy` node to anchor the list and securely position `groupPrev` right behind our very first target block.
 * Then, we trigger a high-speed continuous loop, instantly launching `getKthNode` to aggressively scout exactly `k` steps ahead. If it crashes into a `nullptr` early, the remaining nodes are safe, and we instantly break!
 * Next, we securely lock onto `groupNext` (the starting node of the next block), and fiercely initialize our `prev` pointer directly to it. We then trigger a strict `k`-step internal loop, violently flipping every single `next` pointer completely backwards!
 * Finally, we perfectly stitch our `groupPrev` directly to the `kth` node (the brand new head of our reversed chunk), securely snap `groupPrev` completely forward to prepare for the next block, and confidently repeat until the entire list is conquered!
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Creating a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointer to keep track of the previous group's tail
        ListNode* groupPrev = dummy;

        while (true) {
            // Finding the k-th node from the groupPrev
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break;

            // Store the next group's head
            ListNode* groupNext = kth->next;

            // Break the chain to reverse current k-group cleanly
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            // Reversing k nodes
            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connecting previous group to the reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        // Returning the new head
        return dummy->next;
    }

    // Helper function to find the k-th node from the current node
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};

