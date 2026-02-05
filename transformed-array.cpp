/*Leetcode PS: 3379. Transformed Array
You are given an integer array nums that represents a circular array. Your task is to create a new array result of the same size, following these rules:
For each index i (where 0 <= i < nums.length), perform the following independent actions:
If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. Set result[i] to the value of the index where you land.
If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. Set result[i] to the value of the index where you land.
If nums[i] == 0: Set result[i] to nums[i].
Return the new array result.

Note: Since nums is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.*/
/*
APPROACH:

1. We create a result array of the same size as the given array nums.

2. We iterate through the array index by index.
   For each index i:
   - If nums[i] is positive, we move to the right by nums[i] steps.
   - If nums[i] is negative, we move to the left by abs(nums[i]) steps.
   - If nums[i] is zero, the value remains unchanged.

3. Since the array is circular, moving out of bounds is handled using
   modulo arithmetic.

4. While calculating the new index, we normalize it using:
      ((index % n) + n) % n
   This ensures the index always lies between 0 and n-1 and avoids
   negative indexing and undefined behavior.

5. The value present at the final computed index is stored in the
   result array at the original index.

6. Finally, the result array is returned.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void move(int originalIndex, int steps, char direction,
              vector<int>& result, vector<int>& nums) {

        int n = nums.size();
        int index;

        if (direction == 'R') {
            index = (originalIndex + steps) % n;
        } else {
            index = originalIndex - steps;
            index = ((index % n) + n) % n;   
        }

        result[originalIndex] = nums[index];
    }

    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            }
            else if (nums[i] > 0) {
                move(i, nums[i], 'R', result, nums);
            }
            else {
                move(i, -nums[i], 'L', result, nums);
            }
        }

        return result;
    }
};
