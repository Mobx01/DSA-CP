/*Leetcode ps:- Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> par;
        for(char c : s){
            if(c == '(' || c =='[' ||c=='{') par.push_back(c);
            else{
                if(par.empty()) return false;
                if(c ==')' && par.back()!='(' ) return false;
                if(c ==']' && par.back()!='[' ) return false;
                if(c =='}' && par.back()!='{' ) return false;
                par.pop_back();
            }
        }
        if(par.empty())return true;
        return false;
    }
};
