/*Codeforces PS - 1857A. Array Coloring
You are given an array consisting of n integers. Your task is to determine whether it is possible to color all its elements in two colors in such a way that the sums of the elements of both colors have the same parity and each color has at least one element colored.
For example, if the array is [1, 2, 4, 3, 2, 3, 5, 4], we can color it as follows: [1, 2, 4, 3, 2, 3, 5, 4], where the sum of the blue elements is 6 and the sum of the red elements is 18.

Input
The first line contains an integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case begins with a line containing an integer n (2 ≤ n ≤ 50) — the length of the array a.
The next line contains n integers a1, a2, …, an (1 ≤ ai ≤ 50) — the elements of the array a.

Output
For each test case, output "YES" (without quotes) if it is possible to color the array in two colors in such a way that the sums of the elements of both colors have the same parity and each color has at least one element colored, and "NO" otherwise.
You can output "Yes" and "No" in any case (for example, the strings "yES", "yes", and "Yes" will be recognized as correct answers).
*/

/* Approach - Math & Parity Check (Time: O(N), Space: O(1))
 * Basically, we determine if the total sum of the array is even (or if the elements can be perfectly paired) by exclusively counting the number of odd integers.
 * * Observation: 
 * - Even numbers have absolutely zero effect on the final parity (even/odd status) of a sum. 
 * - Odd numbers, however, flip the parity every single time they are added. Therefore, to end up with an even sum (or to pair them up perfectly without leftovers), you mathematically *must* have an even quantity of odd numbers. Two odds make an even!
 * * How it runs:
 * First, we read the total number of elements 'n' and initialize our 'oddcount' tally to 0.
 * Then, instead of wasting memory storing the entire array, we loop 'n' times reading each integer into a 'temp' variable. We instantly check if 'temp' is odd (temp % 2 != 0). If it is, we increment our 'oddcount'.
 * Finally, after checking all the numbers, we evaluate our final 'oddcount'. If it is completely divisible by 2 (oddcount % 2 == 0), we satisfy the condition and print "YES"! If it's an odd count, we print "NO"!
 */


#include<iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int oddcount = 0,temp;
    for(int i =0;i<n;i++){
        cin >> temp;
        if(temp %2 != 0) oddcount++;
    }

    if(oddcount %2 == 0)cout<< "YES\n";
    else cout<< "NO\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
       solve();   
    }

    return 0;
}
