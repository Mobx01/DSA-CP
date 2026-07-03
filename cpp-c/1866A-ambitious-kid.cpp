/*Codeforces PS - 1866A. Ambitious Kid
Chaneka, Pak Chanek's child, is an ambitious kid, so Pak Chanek gives her the following problem to test her ambition.
Given an array of integers [A1, A2, A3, …, AN]. In one operation, Chaneka can choose one element, then increase or decrease the element's value by 1. Chaneka can do that operation multiple times, even for different elements.
What is the minimum number of operations that must be done to make it such that A1 × A2 × A3 × … × AN = 0?

Input
The first line contains a single integer N (1 ≤ N ≤ 10^5).
The second line contains N integers A1, A2, A3, …, AN (−10^5 ≤ Ai ≤ 10^5).

Output
An integer representing the minimum number of operations that must be done to make it such that A1 × A2 × A3 × … × AN = 0.
*/


/* Approach - Logic & Observation
 * Basically, we find the absolute minimum number of steps required to make the entire array's product zero by targeting the single number closest to zero.
 * Observation: 
 * - The only way for the mathematical product of an array to be 0 is if at least one element inside it is exactly 0. 
 * - Since we assume each operation changes a number by 1, the cost to turn any number into 0 is simply its absolute distance from 0 (i.e., its absolute value). Therefore, to minimize our operations, we just need to find the element with the smallest absolute value in the entire array!
 *
 * How it runs:
 * First, we read all our sequence numbers into the 'nums' array.
 * Then, we initialize our 'ans' tracker to the absolute value of the very first element to give us a starting baseline.
 * Next, we loop through every single number in the array. At each step, we use the built-in 'abs()' function to check its true distance from 0, and greedily update 'ans' if this new distance is strictly smaller than our current recorded minimum.
 * Finally, after checking everything, we simply return 'ans' as our optimal number of operations!
 */


#include<iostream>
#include<vector>
using namespace std;
 
int solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin >> nums[i];
    }
    int ans=abs(nums[0]);
    // for making product of array 0 we need to make 1 array 0 , we will find the number whose 
    // absoulte value is nearest to 0
    for(int i : nums){
        ans = min(ans,abs(i));
    }
    
    return ans;
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << solve() <<endl;
 
    return 0;
}
