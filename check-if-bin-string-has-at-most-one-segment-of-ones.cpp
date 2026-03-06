/* Leetcode ps-1784. Check if Binary String Has at Most One Segment of Ones
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
*/

//Logic: Since s starts with '1', it is valid UNLESS 
//       a '1' appears after a '0' (creating a second segment).
/*Approach
  Return false if "01" exists; otherwise, return true.
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.length() == 1 ) return true;
        for(int i = 1 ; i < s.length();i++){
            if(s[i] == '1' && s[i-1] == '0') return false;
        }
        return true;
    }
};


//using CPP STL :- return s.find("01") == string::npos;
// Returns true if "01" is NOT found.
