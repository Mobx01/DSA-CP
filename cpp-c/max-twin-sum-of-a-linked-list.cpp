/*Leetcode ps- 2130. Maximum Twin Sum of a Linked List
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.
Given the head of a linked list with even length, return the maximum twin sum of the linked list.*/


/*
### Approach: Array Conversion (The "Easy Read" Method)
The tricky part about singly-linked lists is that they are a one-way street. You can only move forward, which makes it really hard to pair the first node with the last node, the second with the second-to-last, and so on. 
To make this super easy, we essentially bypass the linked list's restrictions: we copy all of its values into a standard array (a C++ vector) where we can easily read from both ends at the same time.

**1. Dump Everything into a Vector**
We create an empty vector called `thelist`. We walk through the linked list from start to finish, taking every node's value and pushing it into our vector. Once this while-loop finishes, we have all our numbers in a nice, easily accessible format.

**2. The Setup**
* `n`: We grab the total size of our list.
* `maxsum`: We set this to the lowest possible number (`INT_MIN`) to start. This will act as our high score tracker for the biggest sum we find.

**3. Add the "Twins" Together**
Now we can easily grab items from the front and the back simultaneously. 
* We only need to loop exactly halfway through the array (`n / 2`). If we went all the way, we'd just be double-counting the same pairs!
* For every index `i` (starting from the front), its twin on the exact opposite side of the list is at `n - i - 1`. 
* We add `thelist[i]` and `thelist[n - i - 1]` together. If their combined sum is bigger than our current `maxsum`, we update our high score using the `max()` function.

**4. Return the Winner**
Once the loop finishes checking the first half against the back half, `maxsum` holds the largest pair sum, and we simply return it.
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
    int pairSum(ListNode* head) {
        vector<int> thelist;
        while(head != NULL){
            thelist.push_back(head-> val);
            head = head->next;
        }
        int n = thelist.size(),maxsum = INT_MIN;
        for(int i =0;i<n/2;i++){
           maxsum = max(maxsum , thelist[i] + thelist[n-i-1]);
        }
        return maxsum;
    }
};
