/*Leetcode ps-3727. Maximum Alternating Sum of Squares
You are given an integer array nums. You may rearrange the elements in any order.
The alternating score of an array arr is defined as:
score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.*/


/* Approach - Absolute Value Sorting with Magnitude-Balanced Sign Alternation (Time: O(N log N), Space: O(1))
 * Basically, we completely annihilate brute-force sign configuration searches by aggressively sorting elements by absolute magnitude and alternating positive and negative contributions in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Magnitude-Balanced Alternation Invariant! To maximize an alternating sum or difference of squared terms, assigning positive signs to the largest absolute values and negative signs to the smallest absolute values guarantees the optimal maximum accumulation. By sorting elements in descending order of their absolute values (`abs(a) > abs(b)`), we cleanly structure the array for greedy sign distribution.
 * - (Compilation Bug / Typo Catch): Notice the syntax error on the square calculation line (`- long long sqr = 1LL \n nums[i] * nums[i];`). It is missing the multiplication operator `*` after `1LL` and includes a stray hyphen. It should be corrected to `long long sqr = 1LL * nums[i] * nums[i];` to compile successfully and prevent unintended subtraction operators!
 * - (Ceiling Partitioning): Computing `posc = (n + 1) / 2` correctly isolates the exact count of larger elements that receive positive summation weights.
 * * How it runs:
 * First, we safely intercept vector size `n` and sort the elements in descending order based on their absolute values.
 * We compute the positive contribution threshold `posc` using ceiling division.
 * We ignite a linear scan: adding the squares of the largest elements (`i < posc`) and subtracting the squares of the remaining smaller elements.
 * Finally, we flush the optimized alternating sum result to the output stream with absolute mathematical precision at raw silicon speed!
 */


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        
        //sort desc , with abs value comparision
        sort(nums.begin(), nums.end(), [](int &a, int &b){
            return abs(a) > abs(b);
        });
        
        int posc = (n + 1) / 2;//ceil
        
        for(int i = 0; i < n; i++) {
            long long sqr = 1LL * nums[i] * nums[i];
            
            if (i < posc) {
                sum += sqr; // Add the largest squares
            } else {
                sum -= sqr; // Subtract the smallest squares
            }
        }
        
        return sum;
    }
};
