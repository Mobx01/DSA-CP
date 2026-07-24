/*Leetcode ps-237. Delete Node in a Linked List
There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.*/


/* Approach - Value Copying / Pointer Bypass (Time: O(1), Space: O(1))
 * Basically, since we don't have access to the head of the list to find the previous node, we brilliantly overwrite our current node's value with the next node's value and just completely bypass the next node instead!
 * * Observation: 
 * - A standard linked list deletion requires modifying the `next` pointer of the node strictly *before* the one you want to delete. Without access to the head pointer, we mathematically cannot traverse backwards to find it!
 * - To creatively bypass this limitation, we just steal the identity (the integer value) of the immediate next node. Once our current node perfectly mimics the next one, the actual next node becomes completely redundant.
 * - The problem explicitly guarantees that the node to be deleted is never the absolute tail node, making this look-ahead trick 100% safe from null pointer exceptions.
 * * How it runs:
 * First, we reach into `node->next` and instantly overwrite our current `node->val` with its value.
 * Then, we physically bypass the now-redundant next node by pointing our current `node->next` directly to `node->next->next`. The target node is effectively erased from the chain in pure, guaranteed constant time!
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
    void deleteNode(ListNode* node) {
        // fill current node with value of next node and delete next node
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
