/*Leetcode ps-3720. Lexicographically Smallest Permutation Greater Than Target
You are given two strings s and target, both having length n, consisting of lowercase English letters.
Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.
A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.
*/


/* Approach - Backtracking State Machine / Greedy Lexicographical Descent (Time: O(N) practical, Space: O(N))
 * Basically, we completely annihilate the infinite permutation tree by aggressively deploying a boolean timeline split, structurally forcing the string to perfectly shadow the target until the exact millisecond it can violently diverge into the absolute tightest lexicographical victory!
 * * Observation: 
 * - The absolute core of this architecture is the `greater` flag! It acts as a flawless mathematical lock. While `greater == false`, your loop is brutally constrained by `ch < target[i]`, forcing the engine to either match the target exactly or immediately jump higher. The microsecond `greater` flips to `true`, the lock shatters! Because your loop fundamentally runs from `'a'` to `'z'`, it automatically defaults to harvesting the absolute lowest possible characters to mathematically forge the optimal suffix!
 * - (The Fatal Global Variable Trap): Your recursive logic is an absolute masterstroke, but your memory management is a catastrophic LeetCode time bomb! `string result = "";` is declared at the GLOBAL class level! The execution engine violently reuses the same class instance across multiple test cases! The data from Test Case 1 will mathematically bleed directly into Test Case 2, causing a horrific Wrong Answer mutation! You MUST instantly annihilate this threat by aggressively resetting `result = ""` inside the `lexGreaterPermutation` function before igniting the solver!
 * - (Optimization Alert / The Recursion Annihilation): The backtracking engine is beautiful, but it aggressively burns O(N) call stack memory! You can achieve absolute peak theoretical hardware supremacy by completely destroying the recursion! Run a single iterative loop to match the prefix, find the absolute right-most pivot where a strictly greater character can be physically injected, violently place it, and then just linearly dump the remaining frequency map in ascending `'a'` to `'z'` order! A pure O(N) linear sweep with zero stack frames!
 * * How it runs:
 * First, we safely intercept the base string `s` and aggressively compress it into a blazing-fast O(1) frequency array, perfectly mapping our available ammunition.
 * We ignite the recursive engine at index `0`, structurally locked with `greater = false`.
 * At every single index, we trigger a high-speed `'a'` to `'z'` sweep! We aggressively bypass depleted characters. If we are still locked to the target's timeline, we ruthlessly block any character mathematically smaller than `target[i]`.
 * We violently slam a valid character into our `curr` register, instantly decrement the ammo count, and recursively dive deeper into the timeline!
 * The exact millisecond the timeline fully completes (`i == target.length()`), we check our radar! If the sequence successfully diverged (`greater == true`), we permanently lock the state into `result` and violently short-circuit the entire recursive tree by cascading `return true` all the way to the surface!
 * If the path completely collapses, we mathematically reverse time: popping the character, restoring the ammo, and aggressively trying the next branch!
 */



class Solution {
public:
    string result="";

    bool solve(string& curr,vector<int>& count,string& target,int i,bool greater){
        if(i == target.length()){
            if(greater){
                result = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z';ch++){
            if(count[ch-'a'] == 0) continue;

            if(greater == false && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isgreat = greater || ch>target[i];
            if(solve(curr,count,target,i+1,isgreat)){
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26,0);
        for(char c : s){
            count[c-'a']++;
        }

        string curr;
        solve(curr,count,target,0,false);
        return result;
    }
};
