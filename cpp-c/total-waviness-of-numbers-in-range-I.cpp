/*Leetcode ps -3751. Total Waviness of Numbers in Range I
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].*/


/*Approach:

1. The 'count' helper function:
   - We process the number digit by digit from right to left using the modulo operator (% 10).
   - We look at a sliding window of 3 adjacent digits at a time: 
     'cur' (left neighbor), 'prevnum' (the middle digit we are evaluating), and 'prevprev' (right neighbor).
   - We check if the middle digit is a peak (prevnum > cur AND prevnum > prevprev) 
     or a valley (prevnum < cur AND prevnum < prevprev).
   - If it is, we increase our result counter. Then, we shift our variables to the left 
     to evaluate the next set of 3 digits.

2. The 'totalWaviness' main function:
   - This is a straightforward brute-force loop going through every number from num1 to num2.
   - Any number under 100 is skipped because you need at least 3 digits to even have a middle digit.
   - For all valid numbers, we call our 'count' function and add the result to our running total.
*/


class Solution {
public:

    int count(int n ){
        int prevnum , prevprev, cur,res=0 ;
        prevprev = n%10; // last digit
        n/=10;
        prevnum = n%10; // second last num
        n/=10;
        while(n>0){
            int cur = n%10;
            n/=10;
            if((prevnum > cur && prevnum >prevprev) || (prevnum < cur && prevnum < prevprev)) res++;
            prevprev = prevnum;
            prevnum = cur;
        }
        return res;
    }
    int totalWaviness(int num1, int num2) {
        int totalcount = 0;
        for(int i = num1;i<=num2;i++){
            if( i<100) continue;
            totalcount += count(i);
        }
        return totalcount;
    }
};
