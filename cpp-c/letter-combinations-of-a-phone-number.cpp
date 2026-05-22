/*Leetcode ps- 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/


/*
    APPROACH :
    
    Think of this solution like building words piece by piece. Instead of trying 
    to guess the whole word at once, we take it one digit at a time and expand 
    our list of possible answers. This is an "Iterative" approach.
    
    Step 1: The Setup
    - We start our result list (`ress`) with a single empty string `""`. Why? 
      Because we need a blank canvas to attach our very first letters to.
    - If the user gives us an empty string of digits, we just return an empty 
      list right away (edge case handled!).
    - We create a `lettermap` where the index directly matches the phone digit. 
      For example, index 2 holds "abc", just like a real phone keypad.
      
    Step 2: Going through the digits
    - We look at the input `digits` one by one (e.g., if input is "23", we 
      look at '2', then '3').
      
    Step 3: Building the combinations
    - For the current digit, we find out what letters it can type. 
      (If digit is '2', letters = "abc").
    - We create a temporary list `temp` to hold our new combinations.
    - Now the magic happens: We look at *every* combination we've built so far 
      in `ress`, and we attach *every* possible new letter to it.
      
      Example walk-through for "23":
      - Start: ress = {""}
      - Digit '2' ("abc"): 
          We attach 'a', 'b', and 'c' to "". 
          temp becomes {"a", "b", "c"}.
          We update ress = temp.
          
      - Digit '3' ("def"): 
          We take our current ress {"a", "b", "c"} and attach 'd', 'e', and 'f' 
          to EACH of them.
          "a" becomes -> "ad", "ae", "af"
          "b" becomes -> "bd", "be", "bf"
          "c" becomes -> "cd", "ce", "cf"
          We update ress = temp.
          
    Step 4: The Result
    - Once we've looped through all the digits, `ress` holds all the fully 
      built string combinations. We just return it!
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ress = {""};
        if(digits.size() == 0) return {};

        vector<string> lettermap = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(char dig : digits){
            vector<string> temp;
            string letters = lettermap[dig - '0'];

            for(string res : ress){
                for(char c : letters){
                    temp.push_back(res+c);
                }
            }
            ress = temp;
        }
        return ress;
    }
};
