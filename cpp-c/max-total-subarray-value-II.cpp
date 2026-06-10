/*Leetcode ps- 3691. Maximum Total Subarray Value II
You are given an integer array nums of length n and an integer k.
You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.
The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).
The total value is the sum of the values of all chosen subarrays.
Return the maximum possible total value you can achieve.*/

/*
 * Approach: Segment Trees + Max-Heap (Greedy)
 *
 *
 * -- Intuition --
 * The subarray value is (Max Element - Min Element). 
 * * The key thing to notice here is that for any fixed starting index 'l', 
 * making the subarray longer (increasing 'r') can only increase or maintain 
 * the max element, and decrease or maintain the min element. 
 * * So, for a fixed 'l', the absolute best value is always when it stretches 
 * to the end (r = n - 1). The next best value for that same start index 
 * will be at r = n - 2, and so on.
 *
 *
 * -- Data Structures --
 * 1. Segment Trees: We need two (minST & maxST) to quickly query the max 
 * and min elements of any subarray [l..r] in O(log n) time.
 * * 2. Max-Heap (Priority Queue): To keep track of the largest subarray 
 * values we've found so far. Stores tuples of {value, l, r}.
 *
 *
 * -- Step-by-Step Algorithm --
 * * Step 1: Build the Trees
 * Build the min and max segment trees from the 'nums' array.
 * * Step 2: Initialize the Heap
 * For every starting index 'l' (from 0 to n-1), the best ending index 
 * is 'n-1'. Calculate the value for nums[l...n-1] using the segment trees 
 * and push {value, l, n-1} into the heap. 
 * Now the heap has the absolute best possible subarray for every starting position.
 * * Step 3: Extract the Top 'k'
 * Loop 'k' times. In each iteration:
 * - Pop the top element {value, l, r} and add 'value' to the total result.
 * - Since we just used nums[l..r], the next best subarray starting at 
 * this exact 'l' is the one ending one element earlier: nums[l..r-1].
 * - If r - 1 >= l, calculate the new value for this shorter subarray 
 * and push {nextBestValue, l, r-1} back into the heap.
 * * Step 4: Return the result.
 *
 *
 * -- Complexity --
 * Time: O((n + k) * log n) 
 * -> O(n) to build trees
 * -> O(n log n) to init heap
 * -> O(k log n) to extract top k
 * * Space: O(n) 
 * -> Segment trees take 4*n space
 * -> Heap takes at most n elements at any time
 */


class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMinTree;

    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();
        this->isMinTree = flag;

        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree) {
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        } else {
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        }
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        //No overlap
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        //Complete Overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if (isMinTree) {
            return min(a, b);
        }

        return max(a, b);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    typedef long long ll;

    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);   //true is for minimum
        SegmentTree maxST(nums, false);  //false is for maximum

        //{val, l, r} max. heap
        priority_queue<tuple<ll, int, int>> pq;

        //Step-1 (Initialize the heap with best value)
        //O(n*logn)
        for (int l = 0; l < n; l++) {  //l to n-1
            ll value = getValue(l, n - 1, minST, maxST, n);  //log(n)
            pq.push({value, l, n - 1});
        }

        //Step-2 Find top k
        ll result = 0;
        //O(k * log(n))
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            ll nextBestValue = getValue(l, r - 1, minST, maxST, n);  //log(n)

            pq.push({nextBestValue, l, r - 1});  //log(n)
        }

        return result;
    }
};
