/*Leetcode ps-1111. Maximum Nesting Depth of Two Valid Parentheses Strings
A string is a valid parentheses string (denoted VPS) if and only if it consists of "(" and ")" characters only, and:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B are VPS's (and A.length + B.length = seq.length). The subsequences may not necessarily be contiguous.

For example, for the sequence 123456789, one possible split is:

A = {1, 3, 5, 7, 9},

B = {2, 4, 6, 8}.

This corresponds to the output [0, 1, 0, 1, 0, 1, 0, 1, 0]  where 0 indicates membership in A and 1 indicates membership in B.

Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value.

Return an answer array (of length seq.length) that encodes such a choice of A and B:  answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note that even though multiple answers may exist, you may return any of them.*/




/* Approach - Depth Parity Distribution / Parentheses Splitting (Time: O(N), Space: O(N))
 * Basically, we completely annihilate complex tree parsing by aggressively tracking nesting depth parity, splitting valid parentheses into two balanced groups in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Nesting Depth Parity Invariant (LeetCode 1111 - Maximum Nesting Depth of Two Valid Parentheses Strings)! To minimize the maximum nesting depth of two disjoint valid parenthesis strings, we can assign parentheses based on their nesting depth level `d`. By alternating assignments using `d % 2`, we evenly distribute deep nestings between group `0` and group `1`, guaranteeing that the maximum depth of either resulting string is minimized to $\lceil \text{max\_depth} / 2 \rceil$.
 * - (Order of Operations Nuance): Notice how for `'('`, you increment `d` *before* assigning parity (`d++; res[i] = (d % 2 == 0) ? 0 : 1;`), whereas for `')'`, you assign parity *before* decrementing `d` (`res[i] = (d % 2 == 0) ? 0 : 1; d--;`). This precise timing ensures that the matching opening and closing parenthesis for any specific nest level share the exact same group label, keeping both split strings valid and balanced!
 * - (Linear Efficiency & Zero Overhead): A single pass over the string with a vector of size $N$ requires minimal memory and executes in strict $O(N)$ time.
 * * How it runs:
 * First, we initialize our result vector `res` of size `seq.size()` and our depth tracker `d = 0`.
 * We ignite a high-speed linear scan across each character of `seq`.
 * When encountering an opening parenthesis `'('`, we increment depth and assign a group based on parity; when encountering a closing parenthesis `')'`, we assign based on current parity and then decrement depth.
 * Finally, we flush the resulting group assignment vector to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        int d =0;

        for(int i=0;i<seq.size();i++){
            if(seq[i] == '('){
                d++;
                res[i] = (d%2 == 0) ? 0 : 1;
            }
            else{
                res[i] = (d%2 == 0) ? 0 : 1;
                d--;
            }
        }
        return res;
    }
};
