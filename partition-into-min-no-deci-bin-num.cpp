/*Leetcode ps:- 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.
*/
/*approach
  we can find the number of 1's required ot create each digit of the number . but the minimum number of deci-binary number required is maximum digit present in the given number .
  so we find the maximum value present in the given num using greedy approach - res max(res, (digit - '0')) . digit - '0'- this gives tehe value of digit in num .
*/
class Solution {
public:
    int minPartitions(string n) {
        int res = 0 ;
        for(char i : n){
            res = max(res , (i-'0'));
        }
        return res ;
    }
};
