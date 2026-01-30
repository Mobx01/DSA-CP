/*
Approach:
- Since the array is sorted, all duplicate elements appear consecutively.
- We use the two-pointer technique to remove duplicates in-place.

Steps:
1. Use pointer `i` to track the index of the last unique element.
2. Start pointer `j` from index 1 and iterate through the array.
3. For each element:
   - If nums[j] is different from nums[i], it means we found a new unique element.
   - Increment `i` and copy nums[j] to nums[i].
4. Continue until the end of the array.

Result:
- The first (i + 1) elements of the array will contain all unique values.
- Return (i + 1) as the new length of the array.

Note:
- No extra space is used.
- Elements beyond the returned length are irrelevant.
*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // index of last unique element

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
