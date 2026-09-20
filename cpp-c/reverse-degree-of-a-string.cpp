/*Leetcode ps-3498. Reverse Degree of a String
Given a string s, calculate its reverse degree.
The reverse degree is calculated as follows:
For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
Sum these products for all characters in the string.
Return the reverse degree of s.*/



/* Approach - Linear Weighting with Alphabetical Complement Invariant (Time: O(N), Space: O(1))
 * Basically, we completely annihilate complex string mapping loops by aggressively computing the reverse alphabet position weighted by 1-based index positions, accumulating the total score in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Complementary Weighting Mapping! Instead of standard 1-based indexing from `'a' = 1` to `'z' = 26`, this function computes the reverse degree (`26 - ac`), where `'a'` maps to 26, `'b'` maps to 25, and `'z'` maps to 1. Multiplying this complement by the 1-based string position `(i + 1)` scales the score relative to the character's distance from the end of the alphabet and its position in the sequence.
 * - (Single-Pass Arithmetic Simplicity): Accumulating `(26 - ac) * (i + 1)` inside a standard loop requires zero auxiliary data structures, running in absolute $O(1)$ auxiliary space.
 * * How it runs:
 * First, we initialize our running `sum` tracker and intercept the string length `n`.
 * We ignite a high-speed linear sweep from index `0` to `n - 1`.
 * At each position, we calculate the 0-based alphabet offset `ac`, derive its reverse weight `26 - ac`, multiply by its 1-based position `i + 1`, and add it to our running total.
 * Finally, we flush the final computed reverse degree score to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int reverseDegree(string s) {
        int sum =0,n=s.length();
        for(int i= 0;i<n;i++){
            int ac = s[i] - 'a';
            sum += (26-ac)*(i+1);
        }
        return sum;
    }
};
