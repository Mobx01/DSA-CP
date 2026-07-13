/*Leetcode ps-1291. Sequential Digits
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.*/

/* Approach - Breadth-First Search (BFS) / Queue (Time: O(1), Space: O(1))
 * Basically, we dynamically generate all possible sequential numbers by using a queue, starting with single digits and continuously appending the next consecutive digit until we exhaust all possibilities!
 * * Observation: 
 * - The smallest possible valid building blocks for a sequential number are the single digits 1 through 8. (We skip 9 because there is no '10' digit to append after it).
 * - If we have a valid sequential number (like 12), the ONLY way to extend it is by taking its last digit (2), adding 1 to get the next digit (3), and mathematically appending it by shifting the base (12 * 10 + 3 = 123).
 * - Using a queue guarantees that numbers are evaluated in perfect ascending order (first all 2-digit numbers, then all 3-digit numbers, etc.), completely eliminating the need to sort the final result array.
 * - Because there are only exactly 36 valid sequential numbers that can possibly exist (from 12 up to 123456789), the time and space complexity are strictly constant O(1)!
 * * How it runs:
 * First, we initialize a queue and push our seed values: the single digits 1 through 8.
 * Then, we enter a while loop that runs until the queue is empty. We pop the front number ('temp') and instantly check if it falls inside our strictly defined [low, high] window. If it does, we push it into our 'result' array.
 * Next, we attempt to grow the number. We extract its 'last_digit' (temp % 10). If this digit is safely less than 9, we generate the next sequential number by multiplying 'temp' by 10 and adding 'last_digit + 1'. We push this newly formed number into the back of the queue to be checked later!
 * Finally, once all sequential numbers have been naturally generated and evaluated, we simply return the populated 'result' array.
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i = 1; i <= 8; i++) {
            que.push(i);
        }
        
        vector<int> result;
        
        while(!que.empty()) {
            int temp = que.front();
            que.pop();
            
            if(temp >= low && temp <= high) {
                result.push_back(temp);
            }
            
            int last_digit = temp%10;
            if(last_digit + 1 <= 9) {
                que.push(temp * 10 +(last_digit + 1));
            }
        }
        
        return result;
    }
};
