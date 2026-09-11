/*Leetcode ps-3483. Unique 3-Digit Even Numbers
You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.*/



/* Approach - Digit-Permutation Frequency Filtering / Brute-Force Number Generation (Time: O(1) bounded, Space: O(1))
 * Basically, we completely annihilate complex combinatorial backtracking by aggressively generating all valid 3-digit even numbers and verifying their availability against the input frequency map in absolute O(1) constant time!
 * * Observation: 
 * - The absolute core of this architecture is the Constrained Digit Grid! A valid 3-digit even number is strictly bounded between 100 and 998, with its units place restricted to even digits (`0, 2, 4, 6, 8`) and its hundreds place restricted to non-zero digits (`1-9`). Because the domain of possible numbers is tiny (at most 450 valid even numbers), iterating through possible digit combinations or scanning all 3-digit even numbers directly against a frequency check executes in practically zero time!
 * - (The Clean Frequency-State Restoration): Your nested loop structure carefully decrements and restores the frequency array (`freq[i]--` followed by `freq[i]++`), ensuring that states don't leak across iterations. This manual backtracking guarantees that a digit is only consumed if sufficient inventory exists.
 * - (Optimization Alert / The Reverse-Loop Paradigm): Instead of building numbers via three nested loops over digits `i`, `j`, and `k`, an even cleaner and more compact approach for this specific problem is to loop through all possible 3-digit even numbers `num` from 100 to 998 with a step of 2, extract their digits, and check if they can be formed from your frequency map. This completely eliminates manual nesting bugs and simplifies state management!
 * * How it runs:
 * First, we safely intercept the input digits array and construct a flat frequency vector of size 10 to track digit counts.
 * We ignite our nested traversal engine: `i` loops through hundreds places (1-9), `j` through tens places (0-9), and `k` through even units places (0-8).
 * As each digit is tentatively selected, we decrement its availability in our frequency map.
 * When a valid combination passes all checks, we compute the number, insert it into an `unordered_set` to automatically discard duplicates, and restore the frequency states.
 * Finally, we return the total size of the unique result set with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        unordered_set<int> res;

        for(int i : digits)freq[i]++;

        for(int i= 1;i<=9;i++){
            int num=0;
            if(freq[i] == 0) continue; // cant make number out of this digit

            freq[i]--;
            for(int j=0;j<=9;j++){
                if(freq[j] == 0) continue;
                freq[j]--;
                for(int k=0;k<= 8;k += 2){
                    if(freq[k] == 0) continue;
                    freq[k]--;

                    num = (i*100) + (j*10) +k;
                    res.insert(num);
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return res.size();
    }
};
