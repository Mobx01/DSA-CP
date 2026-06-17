/*Leetcode ps- 3612. Process String with Special Operations I
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.

*/

/*
### Approach: Direct String Simulation

This solution uses a straightforward, step-by-step approach. We simply read the input string character by character and build our final string exactly as the rules dictate. Think of it like simulating typing on a strange keyboard.

We start with an empty result string called `res` and loop through every character in our input string `s`. Here is how we handle each character we encounter:

* **Backspace (`*`):** If we see a star, we need to delete the last character we typed. We use `pop_back()` for this, but we first make sure the string isn't already empty (`!res.empty()`) so the program doesn't crash.
* **Duplicate (`#`):** We take whatever we have built so far and attach a copy of it to the end (`res += res`).
* **Reverse (`%`):** We use C++'s built-in `reverse()` function to flip our entire string backwards.
* **Normal Letter:** If it's not a special symbol (meaning it's just a regular letter), we just slap it onto the end of our string using `push_back(c)`.

Once the loop finishes processing every character, our string is fully built and we just return it.

(Note: Because the `#` operation doubles the size of the string every time it's used, the string's length can grow exponentially. This simulation approach is perfect as long as the problem constraints are small enough that the final string fits in memory!)
*/

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c : s) {
            if (c == '*' && !res.empty()) {
                res.pop_back();
            } 
            else if (c == '#') {
                res += res; 
            } 
            else if (c == '%') {
                reverse(res.begin(), res.end());
            } 
            else if (c != '*') { 
                res.push_back(c);
            }
        }
        return res;
    }
};
