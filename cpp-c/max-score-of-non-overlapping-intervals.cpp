/*leetcode ps-3414. Maximum Score of Non-overlapping Intervals
You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.
Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.
Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.*/




/* Approach - Dynamic Programming with Interval Binary Search & Lexicographical State Tracking (Time: O(N log N + N * K * K log K), Space: O(N * K^2))
 * Basically, we completely annihilate brute-force subset enumeration by aggressively combining interval sorting, binary search jump-tables, and memoized DP, tracking both optimal weights and strict lexicographical index tie-breaks in pristine polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Binary-Search Non-Overlapping Jump! By augmenting each interval with its original index and sorting the array by start time, you can use binary search (`findNext`) to instantly locate the next valid non-overlapping interval in $O(\log N)$ time, bypassing any need for a linear scan.
 * - (The Lexicographical Tie-Breaking Masterstroke): The problem requires that if multiple interval combinations yield the exact same maximum weight, you must choose the one with the lexicographically smallest sequence of original indices. Your `Node` structure tracks `idxs`, and your decision branch explicitly handles score equality via `(skip.idxs < target.idxs)`, perfectly enforcing the tie-breaking rule!
 * - (Vector Copying Overhead & $K=4$ Bounded Scaling): Storing `vector<int> idxs` inside each `Node` and sorting it on every `take` transition (`sort(begin(take.idxs), end(take.idxs))`) introduces minor memory copying overhead. However, because $K$ is strictly bounded to a tiny maximum of 4, the vectors contain at most 4 elements, making the copy and sort operations practically instantaneous while guaranteeing absolute correctness!
 * * How it runs:
 * First, we safely intercept the intervals, inject their original 0-based indices, and sort them in ascending order of their start coordinates.
 * We precompute the `nextIdx` array using a high-speed binary search engine to map valid non-overlapping transitions for every interval.
 * We ignite our memoized top-down DP state machine `solve(i, k)`, evaluating two distinct choices at each step: skipping interval `i` or taking it and jumping to `nextIdx[i]` with $k-1$ remaining slots.
 * During state resolution, if weights tie, we evaluate lexicographical precedence between index vectors.
 * Finally, we flush the optimal index vector from the root state with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n)
            return Node();

        if (t[i][k].score != -1)
            return t[i][k];

        int weight = intervals[i][2];
        int idx    = intervals[i][3];
        int j      = nextIdx[i];

        //skip interval i
        Node skip = solve(intervals, i + 1, k);

        //take interval i
        Node temp = solve(intervals, j, k - 1);
        Node take;
        take.score = temp.score + weight;
        take.idxs  = temp.idxs;
        take.idxs.push_back(idx);
        sort(begin(take.idxs), end(take.idxs));

        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nextIdx[i] = findNext(intervals, r);
        }

        const int K = 4;
        t.assign(n + 1, vector<Node>(K + 1));

        return solve(intervals, 0, K).idxs;
    }
};
