/*Leetcode ps-1903. Largest Odd Number in String
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.*/


/* Approach - Right-to-Left Sweep / Greedy (Time: O(N), Space: O(1))
 * Basically, we scan the string from right to left to find the very first odd digit, which instantly guarantees the largest possible odd integer when taking the entire prefix!
 * * Observation: 
 * - A number is completely defined as odd or even solely by its absolute last digit.
 * - Because we want the LARGEST possible odd number, we want the longest possible valid prefix. Therefore, the very first odd digit we find while scanning backwards mathematically gives us the optimal stopping point!
 * - By using `num.substr(0, i+1)`, we cleanly scoop up everything from the start of the string up to our newly found odd ending.
 * - (Bug Alert: You have a tiny typo in your character subtraction! `num[i] - '0 '` includes an accidental space inside the char literal, which will cause an invalid ASCII math evaluation. It should strictly be `num[i] - '0'`.)
 * * How it runs:
 * First, we grab the total length of the string 'n' and trigger a backwards loop from the very last index 'n - 1' down to 0.
 * Then, we evaluate the current character. We convert the character to its actual integer value by subtracting the ASCII value of '0' and instantly check its parity using modulo 2.
 * Next, the exact moment we hit an odd digit, we break execution and directly return the substring starting from index 0 all the way to our current index 'i' (which requires a length of 'i + 1').
 * Finally, if we completely exhaust the loop and never find a single odd digit, it means the string is entirely made of even numbers, so we safely return an empty string!
 */


class Solution {
public:
    string largestOddNumber(string num) {
        int n =num.size();
        for(int i = n-1;i >= 0;i--){
            if((num[i] - '0 ') % 2  != 0) return num.substr(0,i+1);
        }
        return  "";
    }
};
