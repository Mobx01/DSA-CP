/*Leetcode ps - 2957. Remove Adjacent Almost-Equal Characters
You are given a 0-indexed string word.
In one operation, you can pick any index i of word and change word[i] to any lowercase English letter.
Return the minimum number of operations needed to remove all adjacent almost-equal characters from word.
Two characters a and b are almost-equal if a == b or a and b are adjacent in the alphabet.

*/

// Approach rough - keep checking i with i-1 and if match we mark that index is changed rather than actually changing. and while checking i if i-1 is marked as changed we skip checking.
/* APPROACH: Greedy Skip
1. Comparison: Iterate through the string, comparing word[i] with word[i-1].
2. Conflict Check: If the characters are the same or alphabetically adjacent (distance <= 1).
3. Operation: Increment the count (c++) to "virtually" change word[i].
4. Greedy Skip: Since we changed word[i], it no longer conflicts with word[i+1]. 
   We skip the next index (i++) to avoid unnecessary operations.
*/
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int changed = 0 ;
        int c =0;
        char last = word[0];
        for(int i=1 ;i<word.length() ;i++){
            if(changed == 0 && (word[i] == word[i-1] || word[i] == word[i-1] - 1 || word[i] == word[i-1] +1)){
                c++;
                changed = 1;
            }
            else{
                changed = 0;
            }
        }
        return c;

    }
};
