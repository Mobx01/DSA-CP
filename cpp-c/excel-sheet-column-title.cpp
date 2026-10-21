/*Leetcode ps-168. Excel Sheet Column Title
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

*/




/* Approach - Bijective Base-26 Conversion / Excel Column Title Mapping (Time: O(log_26 N), Space: O(1) auxiliary)
 * Basically, we completely annihilate complex lookup tables by aggressively shifting to 0-based indexing and applying base-26 modulo arithmetic, converting column numbers into valid Excel alphabet titles in pristine logarithmic time and constant auxiliary space!
 * * Observation: 
 * - The absolute core of this architecture is the Bijective Base-26 Invariant (LeetCode 168 - Excel Sheet Column Title)! Unlike standard 0-indexed base conversions, Excel column titles are 1-indexed (A=1, Z=26, AA=27) without a true zero symbol. Decrementing `col` by 1 at the beginning of each iteration (`col--`) neatly maps the 1-based range into a 0-based system (`0` to `25`), ensuring that modulo 26 arithmetic (`col % 26 + 'A'`) maps perfectly to the alphabet without off-by-one errors.
 * - (Logarithmic Time Efficiency): Since `col` is divided by 26 at each step, the loop executes in logarithmic time proportional to the number of digits in base 26 ($O(\log_{26} N)$).
 * - (Minimal Auxiliary Memory): Operating directly with a result string requires zero complex data structures, keeping auxiliary overhead minimal.
 * * How it runs:
 * First, we initialize our result string `res`.
 * We ignite a high-speed while loop running while `col > 0`.
 * At each iteration, we decrement `col` by 1, compute the corresponding character via `col % 26 + 'A'`, prepend it to `res`, and divide `col` by 26 to shift positions.
 * Finally, we flush the fully constructed Excel title string with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    string convertToTitle(int col) {
        string res = "";
        while(col > 0){
            col--;
            res = char(col%26 + 'A') + res;
            col /= 26;
        }
        return res;
    }
};
