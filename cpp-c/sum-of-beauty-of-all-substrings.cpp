/*Leetcode ps-1781. Sum of Beauty of All Substrings
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.*/

/* Approach - Substring Expansion / Dynamic Frequency Counting (Time: O(N^2), Space: O(1))
 * Basically, we generate every single possible substring while continuously updating a frequency map on the fly, instantly calculating and adding the difference between the most and least frequent characters to our total sum!
 * * Observation: 
 * - Generating every substring from scratch and checking it would normally take O(N^3) time. However, by expanding the substring character by character in the inner loop, we can continuously build upon the exact same frequency map, brilliantly dropping the time complexity down to O(N^2)!
 * - Because the string only ever contains lowercase English letters, our frequency array is strictly locked to a size of 26. This means sweeping through it to find the max and min frequencies takes a guaranteed, lightning-fast O(1) constant time and space!
 * - Initializing `min_f` to INT_MAX is a crucial trick, and explicitly skipping elements unless `f > 0` ensures we only ever consider characters that are physically present inside the current substring boundary.
 * * How it runs:
 * First, we initialize our global `sum` tracker and grab the total length 'n' of the string.
 * Then, we trigger our outer loop to anchor the starting index 'i' of our current batch of substrings, immediately resetting a fresh 26-element `freq` array for this new starting point.
 * Next, our inner loop expands the substring one character 'j' at a time. We mathematically map the current character to its correct index (`s[j] - 'a'`), increment its count, and instantly sweep our fixed-size array to lock in the absolute `max_f` and valid `min_f`.
 * Finally, we compute the exact beauty of this specific substring (`max_f - min_f`), continuously add it to our running `sum`, and safely return the completely accumulated total once all possibilities are exhausted!
 */


class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();
        
        //  start of the substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            // end of the substring
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                int max_f = 0;
                int min_f = INT_MAX;
                
                for (int f : freq) {
                    if (f > 0) {
                        max_f = max(max_f, f);
                        min_f = min(min_f, f);
                    }
                }
            
                sum += (max_f - min_f);
            }
        }
        
        return sum;
    }
};
