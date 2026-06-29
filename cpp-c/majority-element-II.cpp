/*Leetcode ps:- 229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/


/* Approach - Hash Map Frequency Counting
 * Basically, we use a hash map to tally up exactly how many times every single number appears in the array, and then we filter out the ones that don't meet our strict > n/3 requirement.
 * We keep 2 main variables/structures to track this:
 * - 'freq' is a hash map that stores the exact count of each unique number we encounter.
 * - 'res' is an array where we gather all the valid numbers that successfully passed our frequency test.
 *
 * How it runs:
 * First, we grab the total size of our array 'n', which we need to calculate our threshold (n / 3).
 * Then, we do a single sweep through the 'nums' array, tallying up the occurrences of every single element in our 'freq' map.
 * After our map is fully built, we loop through all the unique key-value pairs stored inside it.
 * For each pair, we check if the frequency (the value) is strictly greater than 'n / 3'. If it is, we push the actual number (the key) into our 'res' array.
 * Finally, we return the completely populated 'res' array!
 */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int , int> freq;
        for(int i : nums) freq[i]++;
        for(auto it = freq.begin(); it != freq.end() ; it++){
            if(it -> second > n/3) res.push_back(it->first);
        }
        return res;
    }
};


/* Approach - Extended Boyer-Moore Voting Algorithm (space complexity O(1))
 * Basically, we use a clever voting system to find the top two most frequent candidates, because mathematically, an array can have at most two unique elements that appear strictly more than n/3 times.
 * We keep 4 main variables to track our "election":
 * - 'maj1' and 'maj2' hold our two potential majority candidates.
 * - 'count1' and 'count2' track the running "votes" for each respective candidate.
 *
 * How it runs:
 * First, we do an initial pass through the array. If the current number matches one of our candidates, we increase their vote. If it matches neither, but a candidate's vote count is sitting at 0, we draft the current number as the new candidate. If the number is completely different and both candidates already have votes, we decrement BOTH counts (essentially crossing out three distinct numbers at once).
 * Then, because the first pass only tells us who survived the voting process (not if they actually reached the required threshold), we reset our counts to 0 and do a second pass to tally the exact real-world frequency of 'maj1' and 'maj2' in the array.
 * Finally, we check if their actual confirmed counts are strictly greater than n/3. If they are, we push them into our result list!
 */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int maj1    = NULL;
        int count1 = 0;

        int maj2    = NULL;
        int count2 = 0;
        int freq = floor(n/3);
        
        for(int i = 0; i<n; i++) {
            if(nums[i] == maj1)
                count1++;
            else if(nums[i] == maj2)
                count2++;
            else if(count1 == 0) {
                maj1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        vector<int> result; //because atmost two elements can occur more than ⌊ n/3 ⌋ in an array of length n
        count1 = 0;
        count2 = 0;
        for(int num:nums) {
            if(num == maj1)
                count1++;
            else if(num == maj2)
                count2++;
        }
        if(count1 > floor(n/3))
            result.push_back(maj1);
        if(count2 > floor(n/3))
            result.push_back(maj2);
        return result;


    }
};

