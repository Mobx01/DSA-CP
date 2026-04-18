/*Leetcode ps:- 3129. Find All Possible Stable Binary Arrays I
You are given 3 positive integers zero, one, and limit.
A binary array arr is called stable if:
The number of occurrences of 0 in arr is exactly zero.
The number of occurrences of 1 in arr is exactly one.
Each subarray of arr with a size greater than limit must contain both 0 and 1.
Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.

*/

/* APPROACH:
1. Use Recursion + Memoization to count valid arrangements.
2. The 'solve' function builds the array by alternating between groups of 0s and 1s.
3. If the last group placed was '1's, the current step tries placing a group 
   of '0's with length 'len' (where 1 <= len <= limit).
4. This "group-based" placement naturally ensures that we never exceed the 
   'limit' for consecutive identical elements.
5. Result is the sum of starting with a group of 0s and starting with a group of 1s.
*/

class Solution {
public:
    int M= 1e9 + 7;
    int t[201][201][2];
    int solve(int onesleft , int zerosleft , bool lastwasone ,int  limit){
        int result =0;
        if(onesleft == 0 && zerosleft == 0) return 1;
        if(t[onesleft][zerosleft][lastwasone] != -1) return t[onesleft][zerosleft][lastwasone];

        if(lastwasone == true){ // now we explore 0
            for(int len = 1; len<= min(limit,zerosleft);len++){
                result = (result + solve(onesleft , zerosleft-len,false,limit)) % M;
            }
        }
        else{ // now we explore 1
            for(int len =1 ; len<=min(limit,onesleft);len++){
                result = (result + solve(onesleft-len ,zerosleft,true,limit )) % M;
            }
        }
        t[onesleft][zerosleft][lastwasone]= result;
        return result;
        }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        // can't have continous 0 or 1 more than limit times;
        int stwithzero = solve(zero,one,true,limit);
        int stwithone = solve(zero , one,false,limit);
        return (stwithone + stwithzero) %M;
    }
};
