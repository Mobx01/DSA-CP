/*Codeforces ps-1899A.Game with Integers
Vanya and Vova are playing a game. Players are given an integer n. 
On their turn, the player can add 1 to the current integer or subtract 1. 
The players take turns; Vanya starts. If after Vanya's move the integer is divisible by 3, then he wins. 
If 10 moves have passed and Vanya has not won, then Vova wins.

Write a program that, based on the integer n, determines who will win if both players play optimally.

Input
The first line contains the integer t (1 ≤ t ≤ 100) — the number of test cases.
The single line of each test case contains the integer n (1 ≤ n ≤ 1000).

Output
For each test case, print "First" without quotes if Vanya wins, and "Second" without quotes if Vova wins.
*/

/* Approach - Logic & Observation
 * Basically, this is a game theory problem that completely depends on the starting remainder of the number when divided by 3.
 * Observation:
 * - If the starting number 'x' is not a multiple of 3 (meaning x % 3 is 1 or 2), Vanya can immediately add or subtract 1 to make it perfectly divisible by 3, winning the game instantly on her very first turn.
 * - If 'x' is already a multiple of 3, Vanya is forced to ruin it. No matter whether she adds 1 or subtracts 1, Vova can simply do the exact opposite on his turn to restore the number back to a multiple of 3. Vanya is trapped and can never win, meaning the Second player wins.
 *
 * How it runs:
 * First, we read the integer 'x' for the current test case.
 * Then, we check if adding 1 or subtracting 1 makes the number divisible by 3 (written as `(x+1)%3 == 0` or `(x-1)%3 == 0`).
 * If the condition is true, we immediately print "First" because Vanya wins on step one. If it's false, we print "Second" because Vova can force a win!
 */


#include<iostream>
using namespace std;

int main(){
    int t,x;
    cin >> t;
    while(t--){
        cin >> x; //int of current input

        //if x+1 or x-1 is divisible by 3 vanya wons else vova can just do opposite of vanya's move to trap her in a loop

        if(((x+1)%3 ==0) || ((x-1)%3 == 0)){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }
    return 0;
}
