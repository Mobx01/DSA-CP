/* Leetcode Ps - 41 First Missing Positive
   Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
   You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space. 
*/
/*
Intuition:
The smallest missing positive number must lie in the range [1, n+1],
where n is the size of the array. Instead of using extra space, we
reuse the input array itself to mark which numbers are present by
mapping values to indices.

Approach:
1. Check if 1 exists in the array.
   - If 1 is missing, return 1 immediately.
   - Replace all numbers <= 0 or > n with 1 to keep values in range.

2. Mark presence using indices.
   - For each number x, mark index (x - 1) as negative to indicate
     that x exists in the array.
   - Use abs() to handle already marked values safely.

3. Find the first missing positive.
   - Traverse the array.
   - The first index i where nums[i] > 0 means (i + 1) is missing.
   - If all indices are marked, return n + 1.

Complexity:
- Time Complexity: O(n)
- Space Complexity: O(1)
*/

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    bool contain1 = false;

    // Step 1: Check for presence of 1 and sanitize array
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) contain1 = true;
        if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
    }

    if (!contain1) return 1;

    // Step 2: Mark indices as visited
    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        int idx = num - 1;
        if (nums[idx] > 0) nums[idx] *= -1;
    }

    // Step 3: Find first missing positive
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) return i + 1;
    }

    return n + 1;
}
