/*Leetcode ps-961  N-Repeated Element in Size 2N Array
   You are given an integer array nums with the following properties:
   
   nums.length == 2 * n.
   nums contains n + 1 unique elements.
   Exactly one element of nums is repeated n times.
   Return the element that is repeated n times.
*/
/* Hash map approach */
/*
We use a HashMap to count the frequency of each element.
Since the repeated element appears more than once, we store
each number along with its frequency and return the one whose
frequency is greater than 1.

Approach:
1. Create an unordered_map<int, int> to store the frequency of elements.
2. Traverse the array and increment the frequency of each number.
3. Traverse the array again and return the first element whose
   frequency is greater than 1.

Complexity:
Time Complexity: O(n)
- One traversal to count frequencies.
- One traversal to find the repeated element.

Space Complexity: O(n)
- Extra space used by the HashMap to store frequencies.
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> freq ;
        for(int i : nums) freq[i] ++ ;

        for(int i : nums){
            if(freq[i] > 1) return  i;
        }
        return 0 ;
    }
};
