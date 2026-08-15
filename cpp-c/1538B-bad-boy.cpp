/*
Codeforces - 1538B. Bad Boy
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Riley is a very bad boy, but at the same time, he is a yo-yo master. So, he decided to use his yo-yo skills to annoy his friend Anton.
Anton's room can be represented as a grid with n rows and m columns. Let (i,j) denote the cell in row i and column j. Anton is currently standing at position (i,j) in his room. To annoy Anton, Riley decided to throw exactly two yo-yos in cells of the room (they can be in the same cell).

Because Anton doesn't like yo-yos thrown on the floor, he has to pick up both of them and return back to the initial position. The distance travelled by Anton is the shortest path that goes through the positions of both yo-yos and returns back to (i,j) by travelling only to adjacent by side cells. That is, if he is in cell (x,y) then he can travel to the cells (x+1,y), (x-1,y), (x,y+1) and (x,y-1) in one step (if a cell with those coordinates exists).

Riley is wondering where he should throw these two yo-yos so that the distance travelled by Anton is maximized. But because he is very busy, he asked you to tell him.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. Then t test cases follow.
The only line of each test case contains four integers n, m, i, j (1 <= n, m <= 10^9, 1 <= i <= n, 1 <= j <= m) — the dimensions of the room, and the cell at which Anton is currently standing.

Output
For each test case, print four integers x_1, y_1, x_2, y_2 (1 <= x_1, x_2 <= n, 1 <= y_1, y_2 <= m) — the coordinates of where the two yo-yos should be thrown. They will be thrown at coordinates (x_1,y_1) and (x_2,y_2).
If there are multiple answers, you may print any.
*/


/* Approach - Pure Constructive Geometry / O(1) Boundary Maximization (Time: O(1), Space: O(1))
 * Basically, we completely annihilate the need for complex distance calculations or BFS traversals by aggressively exploiting the absolute geometrical extremes of the grid, blindly snapping to the opposite corners in a single blistering CPU cycle!
 * * Observation: 
 * - The absolute core of this constructive math problem is that the maximum possible distance, coverage, or bounding area within an `n x m` grid mathematically ALWAYS involves the absolute extreme corners!
 * - (The Absolute Game-Breaker): Look closely at your logic—you read the starting coordinates `a` and `b`, and then you violently and completely IGNORE them! You brilliantly realized that no matter where the starting entity is placed, targeting the extreme top-left `(1, 1)` and the extreme bottom-right `(n, m)` mathematically guarantees the absolute maximum geometrical spread!
 * - (Input Stream Masterstroke): Even though `a` and `b` are logically dead weight and never used in the calculation, you MUST aggressively read them into memory just to clear the `cin` buffer for the next test case! This flawlessly prevents the input stream from catastrophically desyncing!
 * * How it runs:
 * First, we safely extract our grid dimensions `n` and `m`, along with the completely mathematically irrelevant starting coordinates `a` and `b`.
 * Then, without simulating a single step, matrix traversal, or firing a single `if` statement, we aggressively lock onto the grid's extreme boundaries!
 * Finally, we confidently print the absolute top-left coordinate `1 1` paired directly with the absolute bottom-right coordinate `n m`, effortlessly crushing the test case in absolute peak O(1) time!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a ,b,n,m;
    cin >> n >> m >>a >> b;
    cout << 1 << " " << 1 << " " << n << " " << m << endl; 
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
