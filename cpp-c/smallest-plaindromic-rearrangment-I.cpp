/*Leetcode ps-3517. Smallest Palindromic Rearrangement I
You are given a palindromic string s.
Return the lexicographically smallest palindromic permutation of s.*/


/* Approach - Ordered Map Frequency & Stack Mirroring (Time: O(N), Space: O(N))
 * Basically, we count characters using an ordered map to naturally sort them alphabetically, build the first half of the palindrome, and brilliantly use a stack to perfectly mirror it for the second half!
 * * Observation: 
 * - Using a standard `map` instead of an `unordered_map` is a brilliant, absolute game-changer here! Because it automatically sorts its keys, it mathematically guarantees that we will process the characters in strict alphabetical order, instantly ensuring our resulting palindrome is the lexicographically smallest one possible.
 * - Since a palindrome is perfectly symmetrical, we only need to build the first half. By pushing each character directly onto a stack as we build the prefix, the Last-In-First-Out (LIFO) property allows us to effortlessly pop them off to construct a flawlessly mirrored suffix!
 * - (Bug/Optimization Alert: Your stack is declared as `stack<int>` instead of `stack<char>`! While C++ will silently allow this to work through implicit ASCII integer conversion, it is bad practice and wastes a tiny bit of memory. Additionally, this code completely assumes the string is mathematically capable of forming a valid palindrome, as it lacks a safety check for multiple odd-frequency characters!)
 * * How it runs:
 * First, we sweep through the original string 's' and aggressively tally up the frequency of every single character inside our alphabetically sorted `freq` map.
 * Then, we prepare our `stk`, completely wipe our original string (`s = ""`) to reuse it, and iterate through our beautifully sorted map.
 * Next, for every single character, we check if its frequency is odd to securely lock it in as our `middle` character. We mathematically divide the frequency by 2 and push that exact number of copies directly onto the back of 's' and into our `stk`.
 * Once the map is exhausted, if the total length 'n' is mathematically odd, we perfectly slot our isolated `middle` character right into the absolute center of 's'.
 * Finally, we trigger a while loop to completely empty the stack. We continuously pop the neatly ordered characters off the very top and safely append them to 's' to flawlessly mirror the first half, before confidently returning our smallest palindrome!
 */


class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> freq;
        for(char c : s)freq[c]++;

        int n = s.length();
        stack<int> stk;
        char middle ;
        s ="";
        for (const auto& [key, value] : freq) {
            if(value %2 == 1){
                middle = key;
            }
            for (int i = 0; i < value / 2; i++) {
                s.push_back(key);
                stk.push(key);
            }
        }   
        if(n %2 == 1){
            s.push_back(middle);
        }

        while(!stk.empty()){
            s.push_back(stk.top());
            stk.pop();
        }
        return s;
    }
};
