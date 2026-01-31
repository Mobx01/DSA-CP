/*Leetcode Ps:- 744. Find Smallest Letter Greater Than Target
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
*/


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        int mins = INT_MAX;
        for(int i = 0 ; i < letters.size() ; i++){
            if((letters[i]- target) != 0 && letters[i] - target > 0){
                if((letters[i]- target) < mins){
                    mins = (letters[i] - target);
                    res = letters[i];
                }
            }
        }
        return res ;
    }
};
