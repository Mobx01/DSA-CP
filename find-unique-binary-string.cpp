/*Leetcode ps-1980. Find Unique Binary String
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums.
If there are multiple answers, you may return any of them.*/


/*Approach - sort nums so that all possible strings of that length are from start now we start generating each string 0f that 
            length from 0 to maximum possible value of that length(start from 0 of length n(eg n =2 , compare = "00") , then keep adding "1" to it ) and start comapring them with nums from index i =0 .if at any 
             index there is a missing string we return it. */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        string compare;
        for(int i = 0; i<n;i++){
            compare +="0";
        }
        for(int i = 0; i < n ;i++){
            if(nums[i] != compare) return compare;
            compare = addBinary(compare,"1");
        }
        return compare;
    }
private :
        string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum > 1;
            result = char(sum % 2 + '0') + result;
        }
        return result;
    }
};
