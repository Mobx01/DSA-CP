/*
Codeforces - 1362A. Johnny and Ancient Computer
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Johnny has recently found an ancient, broken computer. The machine has only one register, which allows one to put in there one variable. Then in one operation, you can shift its bits left or right by at most three positions. The right shift is forbidden if it cuts off some ones. So, in fact, in one operation, you can multiply or divide your number by 2, 4 or 8, and division is only allowed if the number is divisible by the chosen divisor.

Formally, if the register contains a positive integer x, in one operation it can be replaced by one of the following:
x * 2
x * 4
x * 8
x / 2, if x is divisible by 2
x / 4, if x is divisible by 4
x / 8, if x is divisible by 8

For example, if x = 6, in one operation it can be replaced by 12, 24, 48 or 3. Value 6 isn't divisible by 4 or 8, so there're only four variants of replacement.

Now Johnny wonders how many operations he needs to perform if he puts a in the register and wants to get b at the end.

Input
The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 1000) — the number of test cases. The following t lines contain a description of test cases.
The first and only line in each test case contains integers a and b (1 <= a, b <= 10^{18}) — the initial and target value of the variable, respectively.

Output
Output t lines, each line should contain one integer denoting the minimum number of operations Johnny needs to perform. If Johnny cannot get b at the end, then write -1.
*/




/* Approach - Coordinate Translation Vector Frequency Mapping (Time: O(N^2 * M^2), Space: O(N^2 * M^2))
 * Basically, we completely annihilate the O(N^4 * shift) naive matrix-shifting brute force by aggressively isolating the coordinates of set bits and mapping translation vectors in pristine geometric time!
 * * Observation: 
 * - The absolute core of this architecture is the Coordinate Translation Invariant! Instead of sliding the entire grid around in multiple directions and counting overlapping `1`s, you brilliantly realize that an overlap occurs when a `1` in `img1` at coordinate $(r_1, c_1)$ aligns with a `1` in `img2` at $(r_2, c_2)$. The exact translation vector required to achieve this alignment is simply the coordinate difference $(r_1 - r_2, c_1 - c_2)$. By collecting all `1`s into coordinate lists and counting the frequency of every possible vector difference using a map, the vector with the highest frequency instantly gives the maximum possible overlap!
 * - (The `std::map` Red-Black Tree Bottleneck): Your logic is a geometric masterstroke, but your container choice introduces minor performance overhead! You deployed `map<vector<int>, int> freq;`. Because `std::map` relies on a Red-Black tree and compares `vector<int>` keys via pointer chasing or element-wise checks, lookups and insertions incur an $O(\log \text{Unique Vectors})$ penalty. Replacing it with an `unordered_map` using a custom hash or encoding the 2D offset into a single scalar key (`(dr + n) * 200 + (dc + n)`) completely unlocks true O(1) hash lookups!
 * - (Matrix Dimension Uniformity Win): `int n = img1.size(); int m = img1[0].size();`. Image overlap problems in competitive programming (like LeetCode 835) almost universally guarantee square matrices where $N = M$. Handling both dimensions explicitly ensures structural safety.
 * * How it runs:
 * First, we safely intercept both matrices and extract all active coordinate locations containing `1`s into two distinct vectors, `cor1` and `cor2`.
 * We ignite a nested traversal comparing every coordinate pair between `cor1` and `cor2`, calculating the translation vector `(r1 - r2, c1 - c2)` and incrementing its frequency in our map.
 * We scan the frequency map to find the translation vector that appears with the highest multiplicity.
 * Finally, we flush the maximum overlap count to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a ,b;
    cin >> a>>b;
    if(a == b){
        cout << 0 <<"\n";
        return;
    }
    if(b>a){
        swap(a,b);
    }
    // a is larger one
    if(a%b != 0){
        cout << -1 << "\n";
        return ;
    }

    long long ops = a/b;
    long long cp = ops;
    while(cp %2 == 0){
        cp /= 2;
    }
    if(cp != 1){
        cout << -1 <<"\n";
    }else{
        cout << ceil(log2(ops)/3.0) <<"\n";
    }
}



int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();  
    }

    return 0;
}
