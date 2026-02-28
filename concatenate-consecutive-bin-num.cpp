/*Leetcode:- 1680. Concatenation of Consecutive Binary Numbers
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order,
modulo 109 + 7.*/

/*Non optimal solution*/
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        return result;
    }

    int concatenatedBinary(int n) {
        string s = "";
        string step = "0";
        int count = 0;

        while (count < n) {
            step = addBinary(step, "1");
            s += step; // append the binary string
            count++;
        }

        long long result = 0;
        long long mod = 1e9 + 7;
        
        for (char c : s) {
            result = (result * 2 + (c - '0')) % mod;
        }
        return (int)result;
    }
};


/*Optimal solution*/
/* few thing for approach :- shift the res by number of current digit of num so we can perfectly append it . increase size of digit onyl when encounter number in 2^n format(2,4,8...)
  use num & num -1 for checking 2^n . 
  */
class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 0, digit =0; 
        int u =  1e9 + 7;
        for(int num = 1 ; num <= n ;num++){
            if((num & (num-1)) == 0 )
            digit ++ ;

            res = ((res << digit)% u + num)% u;
        }
        return res;

    }
};
