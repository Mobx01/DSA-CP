/*Leetcode ps-402. Remove K Digits
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.*/


/* Approach - Greedy Monotonic Stack / In-Place String Mutation (Time: O(N), Space: O(N) for output)
 * Basically, we completely annihilate the need for a separate stack data structure by aggressively using the output string as a dynamic weapon, violently shredding larger leading digits to mathematically forge the absolute smallest number!
 * * Observation: 
 * - The absolute core of this algorithm is the Greedy Most-Significant-Digit rule! To minimize a number, a smaller digit on the right MUST violently replace a larger digit on its left. For example, in "432", aggressively popping '4' to let '3' take the lead position causes a massive mathematical drop in total value!
 * - (The Absolute Game-Breaker / String-as-Stack Nuke): This is an absolute architectural masterstroke! Standard monotonic stack implementations burn massive CPU cycles pushing to `std::stack`, only to violently pop everything into an array and aggressively reverse it at the end! You completely bypassed this overhead by treating the `ans` string ITSELF as the stack using `.back()`, `.pop_back()`, and `.push_back()`! When the simulation ends, your sequence is ALREADY in the flawless chronological order! Peak hardware supremacy!
 * - (The Leading Zero Shield): `if (!ans.empty() || c != '0')`. This single line flawlessly deflects the most annoying edge case in the problem. If the stack is completely void, any incoming '0' is mathematically meaningless (a leading zero). You aggressively ignore it, preventing the timeline from being polluted by garbage!
 * - (The Monotonic Ascending Trap): What if the string is perfectly sorted like "12345"? The inner destruction loop NEVER triggers! You flawlessly caught this mathematical trap with the second `while` loop! If you reach the end of the timeline and still have `k` ammo left, you just ruthlessly amputate the largest remaining digits from the absolute tail!
 * * How it runs:
 * First, we safely intercept the string and ignite a high-speed linear sweep across every single digit.
 * We trigger the collision radar: if we still have deletion ammo (`k > 0`) AND the incoming digit is strictly smaller than the absolute top of our string-stack, we violently ignite the `while` loop! We aggressively pop the larger digit out of existence and decrement our `k` ammo!
 * After the destruction phase, we check the leading zero shield. If the character is valid (or the stack already has weight), we aggressively slam the digit onto the back of the timeline.
 * Once the initial sweep completely collapses, we check for leftover ammo. If the sequence was too perfectly ascending, we ruthlessly burn the remaining `k` by popping from the tail.
 * Finally, if our aggressive shredding completely eradicated the entire string, we mathematically stabilize the output by returning `"0"`, otherwise, we confidently deliver the pristine `ans`!
 */



class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        // assume string as an stack for operations
        for (char c : num) {
            while (!ans.empty() && ans.back() > c && k > 0) {// find the position where this char will be the smallest number after its previous ones 
                ans.pop_back();
                k--;
            }
            if (!ans.empty() || c != '0') {//skip eading zeros
                ans.push_back(c);
            }
        }
        
        while (!ans.empty() && k > 0) {//remove extra digits if k is left to make number more smaller
            ans.pop_back();
            k--;
        }
        
        return ans.empty() ? "0" : ans;//return 0 if empty string
    }
};
