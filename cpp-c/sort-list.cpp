/*Leetcode ps-148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.*/


/* Approach - Array Extraction & Value Overwriting (Time: O(N log N), Space: O(N))
 * Basically, we completely bypass the absolute nightmare of physically rearranging delicate linked list pointers by aggressively ripping all the values out into a dynamic array, blasting them with C++'s blazing-fast built-in sort, and flawlessly overwriting the original nodes!
 * * Observation: 
 * - Sorting a linked list directly by manipulating `next` pointers (like using Merge Sort) is notoriously tedious and highly prone to catastrophic segmentation faults.
 * - By completely ignoring the structural integrity of the nodes and strictly isolating the *values*, we beautifully reduce a complex linked list problem directly into a standard, beginner-friendly array sorting problem!
 * - (Optimization/Constraint Alert): While this approach safely achieves the required O(N log N) time complexity, it aggressively burns O(N) auxiliary space to store the entire `vector<int>`! The classic advanced follow-up for this exact problem demands a strict O(1) space limit. To mathematically achieve that, you would be forced to abandon the vector entirely and brilliantly implement a pure Bottom-Up Merge Sort directly on the raw pointers!
 * * How it runs:
 * First, we safely deploy a `temp` pointer anchored strictly to the `head`, and trigger a high-speed traversal to relentlessly extract and push every single node's value directly into our `thelist` vector.
 * Then, we securely hand our fully populated vector over to C++'s highly optimized `sort()` algorithm, instantly arranging the entire sequence in perfect ascending order.
 * Next, we fiercely reset our `temp` pointer all the way back to the `head` of the list, and securely initialize an index tracker `i` perfectly at 0.
 * Finally, we aggressively sweep through the physical linked list one last time. At every single node, we ruthlessly overwrite its old, unsorted `val` with the flawlessly sorted integer from `thelist[i]`. We increment our index, step forward, and confidently return the perfectly updated `head`!
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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> thelist;
        while(temp != nullptr){
            thelist.push_back(temp->val);
            temp = temp->next;
        }
        sort(thelist.begin(),thelist.end()); 
        temp = head;
        int i =0;
        while(temp != nullptr){
            temp->val = thelist[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};


/* Approach - Top-Down Merge Sort / Tortoise and Hare (Time: O(N log N), Space: O(log N) Call Stack)
 * Basically, we mathematically shatter the entire linked list down to isolated single nodes using recursive pointer splitting, and flawlessly weave them back together into a strictly ascending chain using an incredibly safe dummy node!
 * * Observation: 
 * - This is the absolute optimal, mathematically perfect follow-up to the previous array-extraction method! By physically manipulating the exact pointers, we completely eliminate the massive O(N) auxiliary vector, brutally crushing our memory footprint!
 * - Because linked lists strictly lack random access (no `arr[i]`), we cannot just jump to `n/2` to split the list. We brilliantly solve this by deploying the Fast and Slow pointer technique—where one pointer violently sprints twice as fast as the other, flawlessly guaranteeing the slower one lands exactly on the midpoint!
 * - (The Absolute Masterstroke): Inside the merge function, you declared `ListNode dummyNode(-1)` directly on the local stack instead of using `new ListNode(-1)` on the heap! This completely bypasses all complex edge cases for initializing the head, and mathematically guarantees zero memory leaks because the system automatically destroys it the exact millisecond the function finishes!
 * * How it runs:
 * First, our `sortList` function triggers the absolute base case: if the list is empty or strictly a single node, it is mathematically already sorted, so we instantly return it!
 * Then, we aggressively deploy `findMiddle`. We launch a `fast` pointer (starting exactly one step ahead to perfectly balance even-length lists) and a `slow` pointer. Once the fast pointer physically crashes into the absolute end, the slow pointer is securely anchored precisely on the middle node.
 * Next, we violently sever the chain by storing `middle->next` into `right` and instantly forcing `middle->next = nullptr`. We recursively plunge down both isolated halves until the entire structure is completely shattered into single, detached nodes.
 * Finally, as the recursive stack organically collapses back upwards, `mergeTwoSortedLinkedLists` triggers! We firmly anchor our stack-based `dummyNode`, fiercely compare the raw values of both sublists, perfectly stitch the smaller node onto our running `temp` tail, exhaust the remaining chains, and confidently return the flawlessly merged true head via `dummyNode.next`!
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
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node on the stack to prevent memory leaks
        ListNode dummyNode(-1);
        
        // Temp pointer to build merged list
        ListNode* temp = &dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node (using 'val' instead of 'data')
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode.next;
    }

    // Function to find middle of linked list
    ListNode* findMiddle(ListNode* head) {
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move fast twice as fast as slow
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
    }

    ListNode* sortList(ListNode* head) {
       // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        ListNode* middle = findMiddle(head);

        // Split into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedLists(left, right);
    }
};
