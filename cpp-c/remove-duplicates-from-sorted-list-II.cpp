/*Leetcode ps-82. Remove Duplicates from Sorted List II
You are given the head of a sorted linked list.
Delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.*/



/* Approach - Sentinel Dummy Node with Two-Pointer Duplicate Elimination / Remove Duplicates from Sorted List II (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force node tracking by aggressively leveraging a sentinel dummy node and a dual-pointer skip strategy to completely excise all nodes with duplicate values in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Sentinel-Guarded Duplicate Bypass Invariant (LeetCode 82 - Remove Duplicates from Sorted List II)! Because the head itself might be a duplicate and get deleted, introducing a dummy node (`cpy`) before the head standardizes pointer manipulation. When a duplicate sequence is detected (`cur->val == cur->next->val`), an inner loop advances `cur` to the very last duplicate, and `prev->next = cur->next` cleanly severs the entire duplicate chain in $O(1)$ pointer operations.
 * - (Pointer Advance Precision): Notice that `prev` only advances (`prev = prev->next`) when no duplicate is found at the current node, ensuring `prev` always points to the last verified distinct node before any potential duplicate block.
 * - (Optimal Complexity): Traversing the linked list at most twice (once for the outer loop and once for the inner duplicate-skipping hops) yields an optimal time complexity of $O(N)$ with strict $O(1)$ auxiliary space.
 * * How it runs:
 * First, we handle base cases for empty or single-node lists, then initialize a dummy node `cpy` pointing to `head`, along with `prev` and `cur` pointers.
 * We run a `while` loop scanning through the list. When duplicates are encountered, we skip all matching nodes and bypass them by updating `prev->next`. Otherwise, we advance `prev`.
 * Finally, we flush the cleaned list starting from `cpy->next` to the output stream with absolute mathematical precision at raw silicon speed!
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* cpy = new ListNode(-1);
        cpy->next = head;

        ListNode* prev = cpy;
        ListNode* cur = head;

        while(cur && cur->next){
            if(cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val){
                    cur = cur->next; //skip the duplicates
                }
                prev->next = cur->next;
            }else{
                prev = prev->next; 
            }
            cur = cur->next;
        }
        return cpy->next;
    }
};
