/*Leetcode ps-2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/



/* Approach - Dummy Node / Math Simulation (Time: O(max(N, M)), Space: O(max(N, M)))
 * Basically, we beautifully simulate elementary school addition digit-by-digit, using a dummy node to effortlessly construct our new linked list while perfectly carrying over any extra values!
 * * Observation: 
 * - Because the digits are mathematically stored in reverse order, the absolute head of the list perfectly aligns with the least significant digit (the ones place), allowing us to instantly start adding from left to right!
 * - Using a dummy node is a brilliant, absolute lifesaver here. It completely eliminates the need for messy edge-case checks when attaching the very first valid node to our newly created result chain.
 * - The loop condition `l1 != nullptr || l2 != nullptr || carry != 0` is flawlessly designed. It naturally handles lists of completely different lengths AND securely catches that critical final carry that might spill over after both lists are completely exhausted!
 * - Memory management is beautifully handled! Explicitly deleting the dynamically allocated `dummy` node at the absolute end completely protects the program from silent memory leaks.
 * * How it runs:
 * First, we securely initialize our `dummy` node to anchor our result list, deploy a `curr` pointer to dynamically build the chain, and set our `carry` tracker exactly to 0.
 * Then, we trigger our sweeping while loop. As long as there is absolutely ANY valid digit left in `l1`, `l2`, or an active `carry`, we aggressively compute the total `sum` for the current column.
 * Next, we cleanly extract the single digit for our newly created node using modulo 10 (`sum % 10`), instantly link it to `curr->next`, and mathematically calculate the leftover carry for the next column using integer division (`sum / 10`).
 * Finally, we step our `curr` pointer forward, safely advancing `l1` and `l2` ONLY if they physically exist. Once the loop is completely exhausted, we securely lock in our true answer starting at `dummy->next`, permanently delete the `dummy` node, and confidently return our flawlessly calculated list!
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to serve as the start of our result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy; 
        int carry = 0; // Renamed 'rem' to 'carry' for clarity

        // Continue if there are nodes left in l1, l2, OR a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            // Add l1's value if it exists, then move l1 forward
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add l2's value if it exists, then move l2 forward
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate the new carry and the digit for the current node
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            
            // Move our result pointer forward
            curr = curr->next;
        }
        
        // The real answer starts at dummy->next
        ListNode* ans = dummy->next;
        
        // Free the dummy node from memory to prevent memory leaks
        delete dummy; 
        
        return ans;
    }
};
