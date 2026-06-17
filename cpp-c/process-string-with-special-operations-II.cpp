/*Leetcode ps - 3614. Process String with Special Operations II
You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.
You are also given an integer k.
Build a new string result by processing s according to the following rules from left to right:
If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.*/

/*
### Approach: The "Virtual String" & Working Backwards

Building the actual string in memory is a trap for this problem. Every time you hit a `#`, the string doubles. If you have a bunch of `#`s in a row, your string will grow to gigabytes in size and immediately crash with a Memory Limit Exceeded (MLE) error. 

To bypass this, we never actually build the string. We just track how long it *would* be, and then work backward to trace exactly where our target index 'k' came from.

Here is the step-by-step logic:

**1. Forward Pass (Calculate Total Length 'L')**
We loop through the input string once just to figure out the final length of the fully processed string:
* Letter: Increases length by 1.
* `*` (Backspace): Decreases length by 1.
* `#` (Duplicate): Doubles the current length.
* `%` (Reverse): Does nothing to the length.

**2. Out of Bounds Check**
If our requested index 'k' is greater than or equal to the final calculated length 'L', the character doesn't exist. We return '.' early.

**3. Backward Pass (Tracing 'k' back to its source)**
This is the main trick. We loop through the input string from right to left (end to beginning). We are basically "undoing" every operation to see where 'k' was before that operation happened.
* **If `*` (Backspace):** Undoing a backspace means the string was actually 1 character longer right before this happened. So, `L++`.
* **If `%` (Reverse):** The string was flipped. That means whatever is currently at index 'k' used to be sitting on the exact opposite side of the string. We flip the index back using `k = L - k - 1`.
* **If `#` (Duplicate):** The string was just doubled, so we cut the length in half (`L = L / 2`). If our target 'k' is sitting in the second half (`k >= L`), it is just a mirror copy of the first half. We shift 'k' over to the first half by subtracting the length (`k = k - L`).
* **If Letter:** We are undoing a normal character being added, so we shrink the length (`L--`). If our target 'k' is perfectly equal to this new 'L', it means 'k' was pointing at this exact letter! We found our answer, so return it.
*/


class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long L = 0;
        for(char c : s) {
            if (c == '*' && L>0) {
                L--;
            } 
            else if (c == '#') {
                L *=2;
            } 
            else if (c == '%') {
                //no change in length(reversal )
            } 
            else if (c != '*') { 
                //a to z so increase length
                L++;
            }
        }

        if(k >= L){
            return '.';//out of bound
        }
        // we will track the character assumning the result word is already consructed
        for(int i = n-1;i>=0;i--){//traversing from back
           if(s[i] == '*'){
               L++; //no change in k and reverse operation on L
           }else if(s[i] == '%'){
               //no change in L(reversal) but k will shift
               k = L-k-1;
           } else if(s[i] == '#'){
               //reverse the concatination
               L = L/2; //length goes half
               k = (k >= L) ? k-L : k;
           } else{// normal character a to z
               L--; //reverse process of construction
           }

           if(k == L) return s[i];
        }

        return '.';
    }
};
