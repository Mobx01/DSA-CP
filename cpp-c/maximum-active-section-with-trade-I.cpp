/*Leetcode ps - 3499. Maximize Active Section with Trade I
You are given a binary string s of length n, where:
'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. In a trade, you:
Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Return the maximum number of active sections in s after making the optimal trade.
Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.
*/



/* Approach - Two-Pointer / Block Counting (Time: O(N), Space: O(1))
 * Basically, we sweep through the binary string to count the total number of 1s while simultaneously tracking the maximum combined length of two separate blocks of 0s that perfectly sandwich a block of 1s!
 * * Observation: 
 * - The string naturally breaks down into alternating contiguous blocks of 0s and 1s.
 * - Based on your logic, the ultimate goal is to return the absolute total count of every '1' in the string, plus the highest possible combined sum of two 0-blocks that are strictly separated by 1s.
 * - Instead of storing all block lengths in a vector, we only ever need to remember the length of the immediately preceding 0-block (`bl1`) and the current 0-block (`bl2`). Once evaluated, the right block smoothly becomes the new left block, dropping our space complexity to a perfect O(1)!
 * * How it runs:
 * First, we initialize our counters and string pointer 'i'. If we encounter '0's at the very beginning of the string, we simply tally them up in our left block tracker 'bl1'.
 * Then, the exact moment we hit a '1', we trigger our inner block processing! We count all consecutive '1's and permanently add them to our global 'count1' tally. Immediately after, we count the next consecutive block of '0's and store it in 'bl2'.
 * Next, we check if both 'bl1' and 'bl2' actually have values (are non-zero). If they do, they form a valid pair! We instantly update our 'ans' tracker to lock in the absolute maximum sum found so far using `max(ans, bl1 + bl2)`.
 * Finally, we slide our window forward by shifting `bl1 = bl2` (making our current right 0-block the new left 0-block for the next sequence) and completely resetting `bl2 = 0`. Once the main loop finishes reading the string, we return `count1 + ans`!
 */

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0, bl1 = 0, bl2 = 0, count1 = 0, i = 0, n = s.length();
        
        while (i < n) {
            if (s[i] == '0') {
                bl1++;
                i++;
            } else { // 1
                // check count of continuour 1s 
                while (i < n && s[i] == '1') {
                    count1++;
                    i++;
                }
                
                //check count of continous 0safter the ones
                while (i < n && s[i] == '0') {
                    bl2++;
                    i++;
                }
                
                if (bl1 != 0 && bl2 != 0) {
                    ans = max(ans, bl1 + bl2);
                }
                
                bl1 = bl2; // for further the right 0 will act as left 0
                bl2 = 0;
            }
        }
        
        return count1 + ans;        
    }
};

//keep counting contiuous 0 when 1 starts get a count of continus 1 then 0 after that .store count of both 0 then 1 then 0 if its sum value is more than previous ans
