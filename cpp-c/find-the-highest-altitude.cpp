/*Leetcode ps- 1732. Find the Highest Altitude
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.
You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point*/

/*
 * APPROACH: Running Sum
 * 1. Initialize: We start at altitude 0 (height = 0). We also need a variable 
 * to track the highest point we reach (maxheight = 0).
 * 2. Loop through the array:
 * - Add the current gain/loss to our 'height'.
 * - Update 'maxheight' if our new 'height' is the highest we've seen so far.
 * 3. Return: Once the loop finishes, 'maxheight' holds our answer.
 * * Complexity:
 * - Time: O(n) -> We only do a single pass through the array.
 * - Space: O(1) -> We are only using two extra integer variables.
 */


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0,maxheight=0;
        for(int i : gain){
            height += i;
            maxheight = max(height , maxheight);
        }
        return maxheight;
    }
};
