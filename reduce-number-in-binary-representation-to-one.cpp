/*Leetcode :- 1404. Number of Steps to Reduce a Number in Binary Representation to One
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
If the current number is even, you have to divide it by 2.
If the current number is odd, you have to add 1 to it.
It is guaranteed that you can always reach one for all test cases.*/

// Approach
// In binary representation:
// - If a number ends with '0', it is even.
//   Dividing an even binary number by 2 is the same as a right shift,
//   which means removing the last '0' bit.
//   Therefore, we use pop_back() to divide the number by 2.
//
// - If a number ends with '1', it is odd.
//   According to the problem, for an odd number we need to add 1.
//   Adding 1 in binary can produce a carry (e.g., 111 + 1 = 1000),
//   so we perform binary addition using the binsum function.

class Solution {
public:
    string binsum(string a, string b) {
    string result = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }

    return result;
}
    int numSteps(string s) {
        int count = 0 ;
        while(s != "1"){
            if(s.back() == '1'){
                s = binsum(s,"1");
            }
            else{
                s.pop_back();
            }
            count++ ;
        }
        return count;
    }
};
