/*Leetcode PS :- 1390 Four Divisor
 Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. 
 If there is no such integer in the array, return 0.
*/
// Intuition:
// A number contributes to the final answer only if it has exactly
// four positive divisors. Instead of storing all divisors, we can
// iterate up to sqrt(num) and count divisors in pairs. If the count
// exceeds four, we can stop early since the number is invalid.

// Approach:
// 1. For each number, iterate from 1 to sqrt(num) to find divisors.
// 2. For every divisor `fact`:
//    - If `fact * fact == num`, it contributes one divisor.
//    - Otherwise, `fact` and `num / fact` contribute two divisors.
// 3. Maintain a divisor count and sum of divisors simultaneously.
// 4. If divisor count exceeds 4, return 0 immediately (invalid).
// 5. If the final divisor count is exactly 4, return the sum;
//    otherwise, return 0.
// 6. Accumulate results for all numbers in the array.

// Complexity:
// Time Complexity: O(n * sqrt(m)), where `n` is the size of the array
// and `m` is the maximum value in the array.
// Space Complexity: O(1)


class Solution {
public:
    int findsumdivisor(int num){
        int divcount = 0 ;
        int sum = 0 ;

        for(int fact = 1 ; fact * fact <= num ; fact ++){
            if(num%fact == 0){
                int other  = num /fact ;
                if(other == fact){
                    divcount += 1 ;
                    sum += fact ;
                }
                else{
                    divcount +=2;
                    sum += fact + other ;
                }
            }
            if(divcount > 4){
                return 0 ;
            }
        }
        return divcount == 4 ? sum : 0 ;

    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int &i : nums) {
            result += findsumdivisor(i);
        }

        return result;
    }
};
