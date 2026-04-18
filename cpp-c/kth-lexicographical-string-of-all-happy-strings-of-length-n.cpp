/*Leetcode ps:-1415. The k-th Lexicographical String of All Happy Strings of Length n
A happy string is a string that:
consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
Return the kth string of this list or return an empty string if there are less than k happy strings of length n.*/

/**
 * Approach: Lexicographical Backtracking with Counter
 * --------------------------------------------------
 * 1. DFS Exploration: Use backtracking to explore strings in alphabetical 
 * order ('a' -> 'b' -> 'c').
 * 2. Happy Constraint: Skip any character that is identical to the previous 
 * one (!curr.empty() && curr.back() == ch).
 * 3. Space Optimization: Instead of storing all generated strings in a list, 
 * use an integer 'count' to track how many happy strings we've passed.
 * 4. Target Capture: When 'count' equals 'k', capture the current string into 
 * 'result' and terminate the search.
 * * Complexity: Time O(2^n) | Space O(n)
 */

class Solution {
public:
    void solve(int n,string curr ,int &count,int& k ,string& result){
        if(curr.length() == n){
            count++;
            if(count == k){
                result = curr;
            }
            return;
        }
        for(char ch = 'a';ch<='c';ch++){
            if(!result.empty()) return; //exit if already found the k-th string
            if(!curr.empty() && curr.back() == ch) continue;

            // general backtracking templete 
            curr.push_back(ch); //do
            solve(n,curr , count,k,result);//explore
            curr.pop_back(); //undo
        }
    }
    string getHappyString(int n, int k) {
    string curr="";
    string result="";
    int count = 0 ;
    solve(n,curr,count ,k,result);
    return result;
        
    }
};
