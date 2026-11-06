/*Leetcode ps- 165. Compare Version Numbers
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.
To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.
Return the following:
If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.*/


/* Approach - Two-Pointer Dot-Separated Numeric Chunk Comparison / Version Number Ordering (Time: O(max(N, M)), Space: O(1))
 * Basically, we completely annihilate brute-force string splitting by aggressively traversing both version strings simultaneously using two pointers, parsing dot-separated segments into numeric values on the fly in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Segment-by-Segment Version Invariant (LeetCode 165 - Compare Version Numbers)! Version numbers are compared chunk by chunk (separated by `.`); missing revisions default to `0`. By parsing digits between dots into integer values (`num1` and `num2`) and comparing them numerically rather than lexicographically, we correctly handle cases like `1.2` vs `1.10`.
 * - (Pointer Advance Management): Notice how the inner loops stop at the dot delimiter or string end, and `i++` / `j++` correctly consume the `.` character before the next iteration, keeping pointer synchronization clean without needing string stream or vector allocations.
 * - (Optimal Complexity): Traversing each character of both strings at most once takes $O(\max(N, M))$ time with $O(1)$ auxiliary space.
 * * How it runs:
 * First, we initialize pointers `i` and `j` to parse strings `v1` and `v2`.
 * We run a `while` loop parsing numeric segments separated by `.` into `num1` and `num2`.
 * We compare the parsed numbers; if `num1 > num2` or `num1 < num2`, we return `1` or `-1` immediately.
 * If all corresponding revisions are equal after reaching the end of both strings, we return `0` with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        int l1 = v1.size(), l2 = v2.size();

        while (i < l1 || j < l2) {
            long num1 = 0, num2 = 0;
            while (i < l1 && v1[i] != '.') {
                num1 = num1 * 10 + (v1[i] - '0');
                i++;
            }
            while (j < l2 && v2[j] != '.') {
                num2 = num2 * 10 + (v2[j] - '0');
                j++;
            }

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            i++;
            j++;
        }

        return 0;
    }
};
