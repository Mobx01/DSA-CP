/*Leetcode ps- 788. Rotated Digits
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

*/


/*
    Approach:
    The core idea is to figure out how many numbers from 1 to N are "good" numbers.
    A number is good if we can rotate every single digit by 180 degrees and end up 
    with a valid number that is DIFFERENT from the original.

    To do this, we can categorize all single digits into three groups based on 
    how they act when spun upside down:
    
    1. The "Dealbreakers" (3, 4, 7): 
       Rotating any of these results in an invalid character. If a number contains 
       even one of these digits, the whole number becomes invalid. We can just 
       reject it immediately.
       
    2. The "Status Quo" digits (0, 1, 8): 
       Rotating these gives you the exact same digit back. If a number is made up 
       ENTIRELY of these digits (like 181), rotating it gives you 181 again. Since 
       the rotated number must be DIFFERENT to be considered "good", these aren't 
       enough on their own.
       
    3. The "Gamechangers" (2, 5, 6, 9): 
       Rotating these gives a different, valid digit (2 turns into 5, 6 into 9, etc.). 
       For a number to be "good", it MUST contain at least one of these digits to 
       ensure the final rotated number is different from the original.

    How the logic flows:
    - We loop through every number from 1 to N.
    - For each number, we extract its digits one by one from right to left using 
      modulo 10 (`i % 10`).
    - We use a boolean flag `posb` (possible) starting as false. 
    - If we see a "Gamechanger" (2, 5, 6, 9), we flip `posb` to true. This means 
      the number is currently valid and will change upon rotation.
    - If we see a "Dealbreaker" (3, 4, 7), the number is dead to us. We set `posb` 
      to false and break out of the while loop early to save processing time.
    - If the loop finishes and `posb` is true, it means we found at least one digit 
      that changes, and NO digits that invalidate the number. We add it to our tally!
*/


class Solution {
public:
    bool check(int i){
        int dig ;
        bool posb = false;
        while(i>0){
            dig = i%10;
            if(dig == 2 || dig == 5 || dig == 6 || dig == 9){
                posb = true;
            }else if(dig == 3 || dig == 4 || dig == 7){
                posb = false;
                break;
            }
            i /= 10;
        }
        return posb;
    }
    int rotatedDigits(int n) {
        int res =0;
        for(int i = 1 ;i <= n;i++){
            res += check(i) ? 1 : 0;
        }
        return res;
    }
};
