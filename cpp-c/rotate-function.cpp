/*Leetcode ps- 396. Rotate Function
You are given an integer array nums of length n.
Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:
F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.*/


// Approach(raw) -   F[k] = x then in next in iteration F[k+1] 
                //  every number is increased by 1.because num[i] is in f[k]has  value x*i then in f[k+1] its value will be x*(i+). but the last element f[n-1] will go to 1st so its value will be 0 for f[k+1]. so
              //  f[k] = f[k-1] + sum of nums - n*nums[n-k](last element in previous iteraton). f(0) cal manulally
/*
 * Approach:
 * Doing this naively by shifting the array and recalculating takes O(N^2) time, which will TLE.
 * We need to find a mathematical relationship between F(k) and F(k-1) to do this in O(N).
 *
 * Let's visualize the pattern with an array [a, b, c, d] (n = 4):
 * F(0) = (0 * a) + (1 * b) + (2 * c) + (3 * d)
 * F(1) = (0 * d) + (1 * a) + (2 * b) + (3 * c)
 *
 * Notice what happens when we shift from F(0) to F(1):
 * 1. The multipliers for 'a', 'b', and 'c' all increase by exactly 1.
 * 2. The multiplier for 'd' drops from 3 (which is n-1) to 0.
 *
 * If we just blindly add the total SUM of the array (a + b + c + d) to F(0),
 * we would get: (1*a) + (2*b) + (3*c) + (4*d).
 * But in F(1), 'd' needs to be multiplied by 0, not 4 (which is n).
 * So, to fix the math, we just subtract n * d from our result!
 *
 * The general formula becomes:
 * F(k) = F(k-1) + SUM_OF_ARRAY - (n * element_that_moved_to_front)
 *
 * The element that moves to the front at step i is nums[n-i].
 *
 * So the algorithm is simple:
 * 1. Calculate the total sum of the array and the initial F(0).
 * 2. Loop through the array, calculate the next F(k) using our O(1) formula, and track the max.
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, f = 0, n = nums.size();
        
        // 1. Calculate the array sum and F(0) manually
        for(int i = 0 ; i < n ;i++){
            f += i * nums[i]; 
            sum += nums[i];
        }

        long long largest = f; // Initially max is F(0)
        
        // 2. Derive F(k) from F(k-1)
        for(int i = 1; i < n; i++){
            f = f + sum - (n * nums[n-i]); 
            largest = max(largest, f);
        }
        
        return (int)largest;
    }
};

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

            long long sum = 0,f=0,n=nums.size();
            for(int i = 0 ; i < n ;i++){
                f += i*nums[i];//F[0]
                sum += nums[i];
            }

            long long largest = f;//intitally max = F[0];
            for(int i = 1;i<n;i++){
                f = (f + sum - n*nums[n-i]);//F[k]
                largest = max(largest , f);
            }
            return (int)largest;
    }
};
