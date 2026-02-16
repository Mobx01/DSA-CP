/* Leetcode PS:- 190. Reverse Bits
Reverse bits of a given 32 bits signed integer.
Constraints:
0 <= n <= 231 - 2
n is even.
*/
/*
APPROACH:

1. Since the integer is 32-bit, create a vector of size 32 initialized with 0.
   - This vector will store the binary representation of the number.
   - Index 0 represents the Least Significant Bit (LSB).
   - Index 31 represents the Most Significant Bit (MSB).

2. Extract bits from the given number `n`:
   - Repeatedly take n % 2 to get the LSB.
   - Store the bit at the current index of the vector.
   - Divide n by 2 to move to the next bit.
   - Stop once all bits are processed or 32 bits are filled.

3. Reverse the vector:
   - This effectively reverses the order of bits,
     which is the main requirement of the problem.

4. Convert the reversed binary vector back to an integer:
   - Traverse all 32 bits.
   - Left shift each bit to its correct position.
   - Use bitwise OR to accumulate the result.

5. Return the final reversed integer.

TIME COMPLEXITY:
- O(32) → constant time

SPACE COMPLEXITY:
- O(32) → constant extra space
*/


class Solution {
public:
    int reverseBits(int n) {
        vector<int> ornum(32,0);
        int i = 0 ;
        while(n>0 && i<32){
            ornum[i] = n%2;
            n/=2 ;
            i++;
        }
        int rnum = 0;
        reverse(ornum.begin() , ornum.end());
        for (int i = 0; i < 32; i++) {
        rnum |= (ornum[i] << i);
        }
        return rnum;
    }
};
