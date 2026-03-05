/*1758. Minimum Changes To Make Alternating Binary String
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
Return the minimum number of operations needed to make s alternating.*/

/* APPROACH: Two-Scenario Greedy
1. Scenario 1 (Keep s[0]): Iterate from i=1. If s[i] == last, flip s[i] and increment c1.
2. Reset: Restore s using temp to undo modifications from the first pass.
3. Scenario 2 (Flip s[0]): Start with c2 = 1 (cost of flipping s[0]). 
   Iterate from i=1, flipping s[i] whenever it matches the new 'last'.
4. Result: Return min(c1, c2) as the most efficient alternating pattern.
*/
class Solution {
public:
    int minOperations(string s) {
        string temp = s;
        // assume 1st to be correct
        char last = s[0] ;
        int c1=0;
        for(int i = 1 ;i < s.length();i++){
            if(s[i] == last){
                c1++;
                s[i] = (s[i] == '0') ? '1' : '0';
            }
            last = s[i];
        }
        // invert 1st (assume to be wrong)
        s = temp;
        last = (s[0] == '0' ) ? '1' : '0' ;
        int c2=1;
        for(int i = 1 ;i < s.length();i++){
            if(s[i] == last){
                c2++;
                s[i] = (s[i] == '0') ? '1' : '0';
            }
            last = s[i];
        }
        return min(c1 ,c2); 
    }
};

/*More efficent approach*/
/* APPROACH: Parity-Based Counting
1. Target Pattern: Count flips to match the "0101..." pattern (Even index = '0', Odd = '1').
2. Single Pass: Iterate once through the string; if s[i] doesn't match the parity rule, increment c1.
3. Symmetry: The flips needed for the opposite pattern ("1010...") is simply (Total Length - c1).
4. Result: Return the minimum of the two possible patterns.
*/
class Solution {
public:
    int minOperations(string s) {
        int c1 = 0; 
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') c1++;
            } else {
                if (s[i] != '1') c1++;
            }
        }

        // Pattern 2 cost is  (Total Length - c1)
        return min(c1, n - c1);
    }
};


