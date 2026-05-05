/*Leetcode ps - 61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.*/
/*
 * APPROACH:
 * 1. Handle Edge Cases: If the list is empty, or we don't need to rotate at all (k=0), 
 *    just return the original head.
 * 
 * 2. Find Length & Last Node: Walk through the list to count how many nodes there are ('n').
 *    At the same time, keep a pointer at the very last node.
 * 
 * 3. Create a Circle: Point the last node's 'next' back to the 'head'. Now the list is 
 *    a continuous loop. This makes rotating super easy because we don't fall off the end.
 * 
 * 4. Find the "Cut" Point: Rotating a list of 5 items by 5 places gives you the same list. 
 *    So, we only care about the remainder of (k % n). 
 *    To figure out where our *new* head will be, we need to walk forward from the old head 
 *    by [n - (k % n)] steps. 
 *    The math `n + (-k % n)` is a clever C++ trick to safely calculate this exact number of steps.
 * 
 * 5. Break the Circle: Walk forward that calculated number of steps. 
 *    The node we land on is our 'new head', and the node just before it is our 'new tail'.
 *    We break the circle by setting the new tail's 'next' to NULL, and finally return the new head.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0) return head; //if no rotation return same list
        if(head == NULL) return NULL;
        int n =1; //size of list
        ListNode* last = head;//pointer for pointing last node
        while(last->next != NULL){
            last = last->next;//traverse to the last node
            n++;
        }
        last->next = head;
        int effshift = n + (-k%n);
        ListNode* res = head;
        ListNode* temp ;
        for(int i = 0 ;i < effshift;i++){
            temp = res;
            res = res->next;
        }
        temp->next = NULL;
        return res;
        
    }
};
