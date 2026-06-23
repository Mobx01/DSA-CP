/*Leetcode ps:- 169. Majority Element
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/


//Approach -(space complexity is not O(1)
//Store frequency in a unordered map and return the element if its frequency crosses n/2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i:nums){
            freq[i]++;
            if(freq[i] > n/2) return i;
        }
        return nums[0];
    }
};


/* Approach - Sort and Count Streaks (space complexity O(1))
 * Basically just sorting the array to group identical numbers together, then counting which group is the biggest.
 * We keep 4 variables to track the counts: 
 * - 'maxfreq' tracks the longest streak we've found so far.
 * - 'freq' tracks the streak of the current number we're looking at.
 * - 'elem' is the current number we are actively counting.
 * - 'maxelem' tracks the actual number that currently holds the top streak.
 *
 * How it runs:
 * First, we sort the array so matching numbers are sitting right next to each other.
 * Then we loop through each number 'i' in the array:
 * If 'i' matches 'elem' -> bump up 'freq'. If this streak beats 'maxfreq', update 'maxelem' and 'maxfreq'!
 * If 'i' doesn't match 'elem' -> we hit a new number! Change 'elem' to 'i' and drop 'freq' back to 1 to start counting again.
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxfreq=0,freq=0,elem = nums[0],maxelem;
        for(int i: nums){
            if(i==elem){
                freq++;
                if(maxfreq < freq){
                    maxelem = i;
                    maxfreq = freq;
                }
            }else{
                elem = i;
                freq=1;
            }
        }
        return maxelem;
    }
};
