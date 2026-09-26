/*Leetcode ps-1807. Evaluate the Bracket Pairs of a String
You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.
For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei.
You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:
Replace keyi and the bracket pair with the key's corresponding valuei.
If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
Each key will appear at most once in your knowledge. There will not be any nested brackets in s.
Return the resulting string after evaluating all of the bracket pairs.*/



/* Approach - Hash Map Token Expansion / String Key Substitution (Time: O(N + K), Space: O(N + K))
 * Basically, we completely annihilate slow string lookup bottlenecks by aggressively hashing knowledge pairs into an unordered map, substituting parenthesized bracket keys with their mapped values in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the O(1) Hash Map Substitution (LeetCode 1807 - Evaluate the Bracket Pairs of a String)! We first pre-load all key-value replacement strings from the `knowledge` 2D vector into an `unordered_map<string, string> know`. As we scan the input string `s`, whenever we encounter an opening parenthesis `'('`, we extract the inner key token until the closing parenthesis `')'`, query the hash map instantly, and append either the mapped value or `"?"` to our result string.
 * - (Clean Modular Helper Pattern): Encapsulating the map lookup inside `findinknow` keeps the main parsing loop exceptionally clean and handles missing keys gracefully by returning the fallback sentinel `"?"`.
 * - (String Concatenation Efficiency): While repeated string additions (`ans += k`) can sometimes incur reallocation overhead if strings get massive, standard modern C++ small-string optimization (SSO) and typical bracket constraints handle this efficiently. For absolute peak performance, reserving string capacity (`ans.reserve(...)`) can further optimize memory allocation.
 * * How it runs:
 * First, we safely intercept string `s` and populate our hash map `know` using all entries from the `knowledge` dataset.
 * We initialize our result string `ans` and sweep through `s` character by character.
 * When an opening parenthesis `'('` is detected, we advance our pointer to extract the inner variable name token `t`.
 * We query our hash map for `t`, appending the resolved replacement string (or `"?"`) to `ans`.
 * Finally, we flush the fully evaluated string to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    string findinknow(unordered_map<string,string>& know,string t){
        if(know.find(t) != know.end()){
            return know[t];
        }else{
            return "?";
        }
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        string ans = "";
        string t = "";
        unordered_map<string,string> know;
        for(auto k : knowledge){
            know[k[0]] = k[1]; 
        }
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                t= "";
                i++;
                while(s[i] != ')'){
                    t.push_back(s[i]);
                    i++;
                }
                string k = findinknow(know , t);
                ans += k;
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};
