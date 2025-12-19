/* Leetcode PS - 415 ADD STRING */
/* Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
   You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
   You must also not convert the inputs to integers directly.
   // Approach:
       Add digits from right to left like manual addition.
       Keep track of carry while adding digits.
       Append each digit to result and reverse at the end.

          // Time Complexity: O(max(n, m))
          // Space Complexity: O(max(n, m))

   
   */


class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() -1 ;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";

        while(i >= 0 || j >= 0 || carry){
            int dig1 = i >= 0 ? num1[i] - '0' : 0;
            int dig2 = j >=0 ? num2[j] -'0' :0;
            int total = dig1+dig2+carry ;
            result.push_back((total%10) + '0');
            carry = total/10;
             i-- ;
             j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
