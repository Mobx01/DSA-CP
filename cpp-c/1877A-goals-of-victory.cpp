/*Codeforces PS - 1877A. Goals of Victory
There are n teams in a football tournament. Each pair of teams match up once. After every match, Pak Chanek receives two integers as the result of the match, the number of goals the two teams score during the match. The efficiency of a team is equal to the total number of goals the team scores in each of its matches minus the total number of goals scored by the opponent in each of its matches.
After the tournament ends, Pak Dengklek counts the efficiency of every team. Turns out that he forgot about the efficiency of one of the teams. Given the efficiency of n−1 teams a1, a2, a3, …, an−1. What is the efficiency of the missing team? It can be shown that the efficiency of the missing team can be uniquely determined.

Input
Each test contains multiple test cases. The first line contains an integer t (1 ≤ t ≤ 500) — the number of test cases. The following lines contain the description of each test case.
The first line contains a single integer n (2 ≤ n ≤ 100) — the number of teams.
The second line contains n−1 integers a1, a2, a3, …, an−1 (−100 ≤ ai ≤ 100) — the efficiency of n−1 teams.

Output
For each test case, output a line containing an integer representing the efficiency of the missing team.
*/

/* Approach - Math & Observation
 * Basically, we calculate the missing number needed to make the total sum of the sequence exactly zero by finding the mathematical inverse of the current sum.
 * Observation: 
 * - The core rule of the sequence is that the sum of all 'n' elements must perfectly equal 0. 
 * - We are only given 'n - 1' elements. If we add all these given numbers together to get a total 'sum', the final missing element must perfectly cancel this total out to bring the overall sequence sum back to 0. Therefore, the missing number is simply the negation of our total sum ('-sum').
 *
 * How it runs:
 * First, we read the overall sequence size 'n' and initialize our running 'sum' tracker to 0.
 * Then, we loop exactly 'n - 1' times to read all the provided integers, continuously tallying each one into our 'sum' variable.
 * Finally, we simply return '-1 * sum' (the negated sum) to get the exact value needed to balance the entire array back to zero!
 */

#include<iostream>
using namespace std;

int solve(){
    int n,sum=0,temp;
    cin >> n ;
    for(int i=0;i<n-1;i++){
        cin >> temp;
        sum += temp;
    }
    return -1*sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
       cout << solve() <<endl;
    }

    return 0;
}
