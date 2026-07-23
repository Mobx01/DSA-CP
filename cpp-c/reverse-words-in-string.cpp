/*Leetcode ps-151. Reverse Words in a String
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/

/* Approach - Stack / Word Extraction (Time: O(N), Space: O(N))
 * Basically, we extract every valid word from the string, push them onto a stack to naturally reverse their order, and pop them off to build the final properly spaced string!
 * * Observation: 
 * - A stack is the perfect data structure for reversing sequences because of its inherent Last-In-First-Out (LIFO) property. The first word we read ends up at the absolute bottom, and the last word sits at the very top!
 * - The original string might contain annoying leading, trailing, or multiple contiguous spaces. The outer `while` loop perfectly handles this by instantly skipping over any space it sees.
 * - Using a nested inner `while` loop allows us to gracefully isolate entire contiguous blocks of characters (words) and scoop them up without relying on complex string splitting functions.
 * - When reconstructing the answer, conditionally appending a space using the ternary operator `(stk.size() == 1 ? "" : " ")` beautifully ensures the words are separated while mathematically guaranteeing there is absolutely no trailing space at the very end!
 * * How it runs:
 * First, we initialize an empty stack `stk` to hold our isolated words, a pointer `i`, and an empty `temp` string.
 * Then, we sweep through the original string 's'. If we encounter a space, we step forward (`i++`) and completely ignore it.
 * Next, the exact moment we hit a valid character, we trigger our inner loop to continuously append characters to `temp` until we hit the next space or the end of the string. We then confidently push this completed word onto our stack!
 * Finally, we completely wipe the original string (`s = ""`) and rebuild it from scratch. We continually pop words off the top of the stack, append them to 's' with the correct spacing, and return the flawlessly reversed sentence!
 */

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        int n = s.size(),i=0;
        string temp ="";
        while(i<n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            else{
                temp ="";
                while(i <n && s[i] != ' '){
                    temp += s[i];
                    i++;
                }
                stk.push(temp); 
            }
        }
        s ="";
        while(!stk.empty()){
            s += stk.top() +(stk.size() == 1 ? "" : " ");
            stk.pop();
        }
        return s;
    }
};
