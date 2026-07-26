/*Leetcode ps-234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/

/* Approach - Stack / LIFO Traversal (Time: O(N), Space: O(N))
 * Basically, we leverage the Last-In-First-Out (LIFO) property of a stack to effortlessly read the linked list backwards, comparing it perfectly against a standard forward traversal to check for absolute symmetry!
 * * Observation: 
 * - A palindrome mathematically reads the exact same forwards and backwards. Since a singly linked list only has `next` pointers, physically traversing it backwards is impossible without extra help!
 * - A stack is the absolute perfect data structure here: by pushing every single node's value as we traverse forward, the absolute tail of the list naturally ends up right at the very top of the stack.
 * - (Optimization Note: While this stack approach is incredibly clean and intuitive, it heavily relies on O(N) auxiliary space! You can brilliantly optimize this down to a strict O(1) space by using the tortoise and hare trick to find the middle, physically reversing the second half of the list in-place, and comparing the two halves directly!)
 * * How it runs:
 * First, we safely verify our base cases: if the list is completely empty or has just a single isolated node, it is mathematically a perfect palindrome by default, so we instantly return true.
 * Then, we deploy a `temp` pointer to sweep through the entire list, aggressively pushing every single integer value directly onto our `stk` until we completely exhaust the chain.
 * Next, we reset our focus back to the original `head` and trigger a second, perfectly synchronized traversal. For every single step, we instantly compare our current node's forward value to the backwards value sitting at the very top of the stack.
 * If the values ever mismatch even slightly, the structural symmetry is instantly broken, and we confidently return false! If they match, we smoothly advance our `head` pointer and safely pop the stack to keep moving inward.
 * Finally, if the entire second loop flawlessly completes without a single mismatch, we absolutely guarantee the list is a perfect palindrome and proudly return true!
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* temp = head;
        stack<int> stk;

        while(temp != nullptr){
            stk.push(temp->val);
            temp = temp->next; 
        }
        while(head != nullptr){
            if(head->val != stk.top()) return false;
            head = head->next;
            stk.pop();
        }
        return true;
    }
};
