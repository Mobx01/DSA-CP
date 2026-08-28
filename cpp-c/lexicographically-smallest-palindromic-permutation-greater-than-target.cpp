/*Leetcode ps-3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
You are given two strings s and target, each of length n, consisting of lowercase English letters.
Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.
*/


/* Approach - Half-State Backtracking / Lexicographical Palindrome Synthesis (Time: O((N/2)!), Space: O(N))
 * Basically, we completely annihilate the impossible O(N!) permutation tree by aggressively halving the state space, violently mutating only the left hemisphere of the timeline and mathematically mirroring it to forge a perfect palindrome!
 * * Observation: 
 * - The absolute core of this architecture is the Palindromic Compression! By dividing the frequency map by 2, you ruthlessly collapsed the permutation tree from the full string down to exactly half! Whatever you build on the left mathematically dictates the right, completely shredding redundant recursive branches!
 * - (The Fatal Global Variable Trap): You did it again! `midchar`, `halflen`, and `result` are declared at the class level! If a competitive programming platform runs multiple test cases on the same object instance, the `midchar = '$'` from Test Case 1 will violently mutate and bleed into Test Case 2! You MUST instantly reset these variables inside the `lexPalindromicPermutation` function before igniting the recursive engine!
 * - (The Catastrophic Memory Burn / Pass-by-Value): Look incredibly closely at your recursive signature: `bool solve(string curr, vector<int>& count, string target, ...)`. You are passing `target` BY VALUE! This means every single time the function calls itself, the CPU violently allocates new heap memory and copies the entire string! In a deep recursive tree, this will completely thrash the hardware! You MUST instantly upgrade it to `const string& target` to pass a blazing-fast memory reference!
 * - (Optimization Alert / The Guaranteed Victory Bypass): Inside your base case, you violently reconstruct the entire string and run `if(candidate > target)`. But wait! If your recursive flag `isgreater` is ALREADY `true`, the left hemisphere is mathematically proven to be strictly larger than the target's prefix! This means the full string is GUARANTEED to be greater regardless of the right side! You can completely bypass the full O(N) string comparison if `greater == true`, saving massive CPU cycles at the absolute deepest layer of the recursion!
 * * How it runs:
 * First, we safely intercept the raw string and aggressively map the character frequencies, instantly checking the parity radar. If more than one character has an odd frequency, the structural integrity of a palindrome is mathematically impossible, and we violently abort returning `""`!
 * We extract the volatile `midchar`, ruthlessly slice the frequency map in half, and lock in our `halflen` boundary.
 * We ignite the high-speed recursive engine! We violently sweep from `'a'` to `'z'`, carefully respecting the available ammo pool and aggressively blocking any character that mathematically drops below the target's timeline (`!greater && ch < target[i]`).
 * We forcefully slam valid characters into the left hemisphere and dive deeper.
 * The exact millisecond the left hemisphere hits maximum capacity, we trigger the mirror protocol! We dynamically reconstruct the right half, inject the `midchar`, and smash the final candidate against the `target`.
 * If it survives the collision (`candidate > target`), we permanently lock it into `result` and cascade the victory flag all the way up, flawlessly crushing the simulation!
 */


class Solution {
public:
    char midchar ='$';
    int halflen =0;
    string result="";

    bool solve(string curr , vector<int>& count,string target,int i,bool greater){
        if(curr.length() == halflen){
            string candidate = curr;//left half
            string righthalf =  curr;
            reverse(begin(righthalf),end(righthalf));
            if(midchar != '$'){
                candidate += midchar;
            }
            candidate += righthalf;
            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
        }
        for(char ch = 'a';ch <= 'z';ch++){
            if(count[ch-'a'] == 0)continue;
            if(!greater && ch<target[i]){
                continue;
            }
            // do
            curr.push_back(ch);
            count[ch-'a']--;
            bool isgreater = greater || ch > target[i];
            //explore
            if(solve(curr,count,target,i+1,isgreater)){
                return true;
            }
            //undo
            curr.pop_back();
            count[ch-'a']++;

        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n  = s.length();
        vector<int> count(26,0);
        for(char &ch : s){
            count[ch-'a']++;
        }
        int oddcount=0;
        for(int c =0;c<26;c++){
            if(count[c]%2 == 1){
                oddcount++;
                midchar = c+'a';
            }
        }
        if(oddcount > 1) return "";//no possible plaindrome
        for(int c=0;c<26;c++){
            count[c] /= 2;
        }
        halflen = n/2;
        string curr; // left half
        solve(curr,count,target,0,false);
        return result;
    }
};
