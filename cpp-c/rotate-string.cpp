/*Leetcode ps- 796. Rotate String
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.*/

/*
 * APPROACH :
 *
 * The Idea:
 * Think of your string like it's written on a spinning wheel. We are going 
 * to spin the wheel one letter at a time. Every time it clicks into a new 
 * position, we check to see if the word matches our goal.
 *
 * Steps:
 * 1. The Obvious Checks: First, if the words aren't even the same length, 
 *    there is zero chance they are rotations of each other, so return false. 
 *    If they already match perfectly right out of the gate, return true.
 * 
 * 2. Setting the Limit: We only need to spin the wheel 'n' times (the length 
 *    of the word). Spinning it any more just repeats the original word.
 * 
 * 3. The Spin: To spin the word, we chop off the very first letter (using 
 *    s.substr(1) to get the rest of the word) and glue that first letter 
 *    (s[0]) onto the very end.
 * 
 * 4. The Check: Right after we make that shift, we check if our newly 
 *    rotated string matches the goal. If it does, we found it! Return true.
 * 
 * 5. Giving Up: If the loop finishes—meaning we spun the wheel all the way 
 *    around—and we never triggered a match, it's impossible. Return false.
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s == goal) return true;

        int n = s.length();
        
        for (int i = 0; i < n; i++) { // no of rotation
            // index 1 to the end + 1st char at the back. (definatsion of rotation)
            s = s.substr(1) + s[0]; 

            if (s == goal) {//
                return true;
            }
        }
        
        return false;
    }
};
