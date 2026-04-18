/*leetcode PS:- 3637. Trionic Array I
You are given an integer array nums of length n.
An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.*/



// Intuition:
// A trionic array is divided into three consecutive non-empty parts:
// first strictly increasing, then strictly decreasing, and finally
// strictly increasing again. The idea is to scan the array once and
// verify that these three phases appear in order without breaking
// strict monotonicity.

// Approach:
// We traverse the array from left to right.
// First, we find the end of the strictly increasing segment.
// Then, we continue to find a strictly decreasing segment.
// Finally, we check that the remaining elements form a strictly
// increasing segment.
// If any segment is empty or the required order breaks,
// the array is not trionic. If all three segments are valid
// and cover the entire array, we return true.

// Complexity:
// Time complexity: O(n)
// Space complexity: O(1)


class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int p = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                p++;
            } else break;
        }
        if (p == 0 || p == nums.size() - 1) return false;

        int q = p;
        for (int i = p; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                q++;
            } else break;
        }
        if (q == p || q == nums.size() - 1) return false;

        int r = q;
        for (int i = q; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                r++;
            } else return false;
        }

        return r == nums.size() - 1;
    }
};
