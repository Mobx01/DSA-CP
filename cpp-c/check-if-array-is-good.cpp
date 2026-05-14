/*Leetcode ps- 2784. Check if Array is Good
You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].
base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].
Return true if the given array is good, otherwise return false.
Note: A permutation of integers represents an arrangement of these numbers.*/

/*
    APPROACH:
    1. Get the Size: 
       We first find the total number of elements in the array and call it 'n'.
    2. Count the Numbers (Frequency Map): 
       We use a tool called an 'unordered_map' to count how many times each 
       number appears in our array. Think of it like a tally sheet. We loop 
       through the array and add a tally mark for every number we see.
    3. Check the Largest Number Rule: 
       The largest number we should have is 'n-1'. According to the rule of a 
       "good" array, this specific number MUST appear exactly 2 times. 
       If it doesn't, we immediately know the array is not good, so we return false.
    4. Check the Rest of the Numbers: 
       We loop through our array one more time to check the remaining numbers:
       - Skip the largest number: If the current number is 'n-1', we just skip 
         it because we already checked it in Step 3.
       - Check bounds: A valid number must be greater than 0 and cannot be 
         larger than 'n-1'. If we find a 0, a negative number, or a number 
         that is too big, the array is invalid (return false).
       - Check counts: For all numbers other than 'n-1', they must appear 
         exactly 1 time. If a number appears more than once, or not at all, 
         the array is invalid (return false).
    5. Final Verdict: 
       If the code survives all the checks in the loop without returning false, 
       it means all the rules were perfectly followed! The array is good, 
       so we return true.
*/


class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i : nums) freq[i]++;

        if(freq[n-1] != 2) return false;
        for(int i : nums){
            if(i == n-1) continue;
            if(i <= 0 || i > n-1) return false;
            if(freq[i] != 1) return false;
        }
        return true;
    }
};
