/*Leetcode ps:- 868. Binary Gap
Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.
Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.
*/
/*Approach
  we extract the bit by n%2 and do this untill n>0 . 
  if bit is 1 then we check if already 1 has occured using found_first variable if it is true we update the result by using maximum function to check maximum among current distance and result .
  and we update the current distance and found_first to 1 and true everytime a 1 is spotted . if bit is 0 and a 1 is already spotted we increase current distance by 1 .   
*/

class Solution {
public:
    int binaryGap(int n) {
        int res = 0 , curdis = 0 ;
        bool found_first = false ;
        while(n>0){
            int bit = n%2;
            if(bit==1){
                if(found_first){
                    res = max(curdis , res);
                }
                curdis = 1;
                found_first = true; 
            }
            else{
                if(found_first) curdis++;
            }
            n /= 2;
        }
        return res;

    }
};
