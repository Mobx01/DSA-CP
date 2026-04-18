/*Leetcode ps- 3761. Minimum Absolute Distance Between Mirror Pairs
You are given an integer array nums.
A mirror pair is a pair of indices (i, j) such that:
0 <= i < j < nums.length, and
reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.*/

/*APPROACH- 
Flip the Number: We need a way to flip a number around. For example, if the number is 123, we’ll flip it to 321. We write a simple function to do this flip.

Keep Track of Numbers: We’ll use a map (kind of like a list of lists) to remember where each number is in the array. This helps us quickly check if the flipped version of a number is somewhere in the list. -- (map(int,vector))

Main Steps:

For each number in the list, we flip it and check if we have seen the flipped number before.
If we find the flipped number, we look for the first place where it shows up after the current number. This gives us the "distance" between the two numbers.
We keep track of the smallest distance we find.
If the smallest distance is 1, we stop early and return 1 because that's the smallest distance we can have.
If no flipped numbers are found, we return -1 because there’s no match.
Final Result: At the end, we either return the smallest distance we found or -1 if no match was found.

*/

class Solution {
public:
    int rev(int n){
        int res =0;
        while(n>0){
            res = res*10 + n%10;
            n/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int , vector<int>> index;
        int n = nums.size();
        for(int i =0; i<n;i++){
            index[nums[i]].push_back(i);
        }
        int mindis =INT_MAX;
        for (int i = 0 ; i <n ; i++){
            vector<int> curind = index[rev(nums[i])];
            int m = curind.size();
            if(m == 0) continue;
            int cur=-1;
            for(int j : curind){
                if(j>i){
                    cur = j;
                    break;
                }
            }
            if(cur != -1) mindis=min(mindis,(cur-i));
            if(mindis == 1 ) return 1;
        }
        return mindis == INT_MAX ? -1 : mindis;
    }
};
