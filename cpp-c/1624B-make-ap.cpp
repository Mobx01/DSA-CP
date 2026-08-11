/*
Codeforces - 1624B. Make AP
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Polycarp has 3 positive integers a, b and c. He can perform the following operation exactly once:
Choose a positive integer m and multiply exactly one of the integers a, b or c by m.

Can Polycarp make it so that after performing the operation, the sequence of three numbers a, b, c (in this order) forms an arithmetic progression? Note that you cannot change the order of a, b and c.

Formally, a sequence x_1, x_2, ..., x_n is called an arithmetic progression (AP) if there exists a number d (called "common difference") such that x_{i+1} = x_i + d for all i from 1 to n-1. In this problem, n=3.

For example, the following sequences are AP: [5, 10, 15], [3, 2, 1], [1, 1, 1], and [13, 10, 7]. The following sequences are not AP: [1, 2, 4], [0, 1, 0] and [1, 3, 2].

You need to answer t independent test cases.

Input
The first line contains the number t (1 <= t <= 10^4) — the number of test cases.
Each of the following t lines contains 3 integers a, b, c (1 <= a, b, c <= 10^8).

Output
For each test case print "YES" (without quotes) if Polycarp can choose a positive integer m and multiply exactly one of the integers a, b or c by m to make [a, b, c] be an arithmetic progression. Print "NO" (without quotes) otherwise.

You can print YES and NO in any (upper or lower) case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer).
*/


/* Approach - Pure Mathematical Isolation / Arithmetic Progression (Time: O(1), Space: O(1))
 * Basically, we mathematically isolate every single possible target variable using the strict laws of an Arithmetic Progression, aggressively checking if we can multiply exactly one element to perfectly bridge the gap!
 * * Observation: 
 * - The absolute golden rule of any 3-element Arithmetic Progression (a, b, c) is mathematically set in stone: 2 * b = a + c!
 * - Because the problem strictly allows us to multiply EXACTLY ONE element by a positive integer 'm', we can aggressively branch the universe into exactly 3 independent timelines: modifying 'a', modifying 'b', or modifying 'c'.
 * - (The Absolute Game-Breaker): For each timeline, we ruthlessly solve the AP equation for the target element. For example, if we modify 'a', the required new value MUST mathematically be (2 * b) - c. 
 * - Once we isolate the exact target value, we deploy a flawless two-step verification: 1. Is the new value strictly positive? (Since the multiplier 'm' must be > 0, the new value must also be positive). 2. Is the new value a perfect multiple of the original element? (new_val % old_val == 0). If both pass, we instantly lock in a win!
 * - (Parity Check Masterstroke): When isolating for 'b', the equation becomes b = (a + c) / 2. Because 'b' MUST be an integer, 'a + c' must be perfectly even! Your condition `(c - a) % 2 == 0` brilliantly and flawlessly handles this exact parity check before allowing the division!
 * * How it runs:
 * First, we safely extract our three targets a, b, and c, and set our boolean `answer` securely to false.
 * Then, we fiercely evaluate Timeline 1 (modifying a): we calculate `new_a = 2*b - c`. If it yields a valid positive multiplier (`new_a / a > 0`) and is flawlessly divisible by 'a', we aggressively flag `answer = true`!
 * Next, we trigger Timeline 2 (modifying b): we calculate `new_b = (a + c) / 2`. We strictly enforce the parity check `(c - a) % 2 == 0`, check positivity, and verify perfect divisibility by 'b'!
 * Finally, we launch Timeline 3 (modifying c): we mathematically compute `new_c = 2*b - a`. We ruthlessly run the exact same positivity and modulo checks!
 * The exact millisecond all three timelines are evaluated, we confidently print "YES" if even a single valid path exists. Otherwise, we effortlessly reject the case with a "NO" in blistering O(1) time without simulating a single loop!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a ,b,c;
    cin >> a >> b >> c;
    bool answer = false;

    long long new_a = 2*b -c;
    if(new_a /a > 0 && new_a % a ==0) answer = true;

    long long new_b = (a+c)/2;
    if(new_b /b > 0 && new_b % b ==0 && (c-a)%2==0) answer = true;

    long long new_c = 2*b -a;
    if(new_c /c > 0 && new_c % c ==0) answer = true;
    if(answer){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();  

    return 0;
}
