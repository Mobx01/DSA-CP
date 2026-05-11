/*Leetcod ps -2553. Separate the Digits in an Array
Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.
To separate the digits of an integer is to get all the digits it has in the same order.

For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
*/



/*
        APPROACH (String Method):
        1. Instead of using math (division and remainder) to extract digits backward,
           we can simply convert the entire number into a string (text).
        2. For example, the number 132 becomes the string "132".
        3. Strings naturally store characters from left to right. We can just loop 
           through each character in that string, convert it back into a number, 
           and add it directly to our final answer.
        4. This avoids the need for the `temp` vector and the reverse loop entirely!
*/


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums){
        vector<int> answer;//result vector
        for(int i : nums){
            vector<int> temp;
           while(i>0){//decompose the number into digits from ones position to further positions
                temp.push_back(i%10);
                i /= 10;
            }
            for(int j = temp.size() -1;j>= 0;j--){ // reverse and store in asnswer
                answer.push_back(temp [j]);
            }
        }
        return answer;
    }
};
