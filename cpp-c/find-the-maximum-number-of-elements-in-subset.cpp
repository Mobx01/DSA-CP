/*Leetcode ps -3020. Find the Maximum Number of Elements in Subset
You are given an array of positive integers nums.
You need to select a subset of nums which satisfies the following condition:
You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.*/


/* Approach - Hash Map and Power Simulation 
 * Basically, we use a frequency map to build valid sequences by simulating the process of repeatedly squaring a base number, ensuring we have pairs of each number until we reach a single peak value.
 * We keep 2 main variables/structures to track this:
 * - 'freq' is a hash map that stores how many times each specific number appears in the array.
 * - 'ans' keeps a running maximum of the longest valid subset pattern we've managed to build.
 *
 * How it runs:
 * First, we tally up the frequencies of every single number in our array into the 'freq' map.
 * Then, we handle the special case for the number '1'. Since 1 squared is always 1, we just take all the 1s we have. If the total is even, we subtract 1 so it forms a valid pattern with a single peak in the middle.
 * Next, we loop through all the unique numbers in our map (skipping 1). For each starting number 'x', as long as we have at least 2 copies of it, we add 2 to our length and square 'x' to look for the next required piece of the pattern.
 * When we finally run out of pairs, we check the peak. If the next squared number exists at least once, we add 1 to our length to cap off the pattern. If it doesn't exist, we must use our previous number as the peak, meaning we only needed 1 of it instead of 2, so we subtract 1 from our length!
 */

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;
        for(int i : nums){
            freq[i]++;
        }
        int ans = 0;

        //handling 1 
        if(freq.count(1)){
            int onecount = freq[1] % 2 ? freq[1] : freq[1]-1; // if 1 occurs odd time then its subset will have length equal to the frequency else take one 1 less to follow the pattern
            ans = max(ans,onecount);
        }
        for(auto en : freq){
            if(en.first == 1)continue;//skip case of 1
            int len = 0 ;
            long long x=en.first;
            while(freq.count(x) && freq[x] >= 2){
                len += 2; // we need 2 of nmbers of x^k(except the largest power)

                if(x > 1e9) break;//stop when goes out of bound
                x = x*x; //check next power of 2 (x^2) 
            }
            if(freq.count(x)) len++; //check if highest powered number is there
            else len--; // assume the last power to be the final so only one of the number will be considered
            ans = max(ans,len);
        }
        return ans;
    }
};
