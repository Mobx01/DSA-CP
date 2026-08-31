/*leetcode ps-2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
A critical point in a linked list is defined as either a local maxima or a local minima.
A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].*/



/* Approach - Tri-Node Kinematic Radar / Spatial Memory Annihilation (Time: O(N), Space: O(1) target)
 * Basically, we completely annihilate the need for auxiliary heap memory by violently collapsing the critical point history into a rolling state machine, computing the absolute minimum and maximum distances on the fly during a single blistering linear sweep!
 * * Observation: 
 * - The absolute core of this architecture is the Tri-Node Radar! You aggressively track exactly three contiguous points in space (`pprev`, `prev`, `cur`). The mathematical logic `(prev > cur && prev > pprev) || (prev < cur && prev < pprev)` flawlessly identifies both local maxima and minima using a single unified kinetic equation! 
 * - (The Fatal Heap Allocation Trap): Your radar logic is pristine, but your memory architecture is a ticking time bomb! You aggressively allocate `vector<int> criticals` and push every single critical index onto the heap! If the linked list contains 10^5 alternating nodes, you violently allocate 50,000 integers of dynamic memory, fragmenting the heap and burning a completely redundant O(M) second pass to find the minimum! 
 * - (Optimization Alert 1 / The Zero-Allocation Nuke): You NEVER need to remember the entire timeline of critical points! To mathematically solve this, you only need exactly two O(1) registers: `first_crit` (to calculate the max distance at the very end) and `prev_crit` (to dynamically calculate `current - prev_crit` for the min distance). The exact millisecond your radar pings a new critical point, you violently calculate the gap, smash it into `mindis` using `min()`, update `prev_crit`, and keep moving! This completely shreds your space complexity down to absolute peak O(1)!
 * - (The Ghost Register Trap): Look closely at your initialization: `int prev = 0, curr=0, pprev;`. You forcefully declare `curr` and initialize it, but inside the loop, you declare a brand new scope-shadowed variable `int cur = head->val;`! `curr` is a dead register doing absolutely nothing but wasting L1 cache space! Always aggressively purge unused state variables!
 * - (The 64-Bit Type Mismatch): You anchored `long long i = 2;`, but you return a `vector<int>`. When you push `i` into `criticals`, the compiler violently forces a silent downcast from 64-bit to 32-bit! If you expect indices to breach the 32-bit ceiling, the return type itself must be 64-bit! Otherwise, stick to a blisteringly fast 32-bit `int i = 2;` to perfectly align the hardware registers!
 * * How it runs (The O(1) Optimized Vision):
 * First, we safely intercept the linked list and instantly initialize our `pprev` and `prev` sensors. We lock our `first_crit` and `prev_crit` tracking registers to -1.
 * We ignite a high-speed linear sweep across the node timeline!
 * The exact millisecond our Tri-Node Radar detects a structural fracture (critical point), we check our state:
 * If `first_crit` is empty, this is Patient Zero! We securely lock its coordinate into `first_crit` and copy it to `prev_crit`.
 * If it's NOT the first, we mathematically have a pair! We violently calculate the localized distance (`i - prev_crit`), smash it against our global `mindis` register, and aggressively overwrite `prev_crit` with the new coordinate!
 * We shift the window (`pprev = prev; prev = cur;`) and advance the pointer.
 * The moment the timeline collapses, if `mindis` was never triggered, we confidently return `{-1, -1}`. Otherwise, we calculate the absolute max distance directly via `prev_crit - first_crit` and flawlessly deliver the payload!
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = 0,curr=0,pprev;
        long long i =2;
        if(head->next->next == nullptr) return {-1,-1};
        vector<int> criticals;
        pprev = head->val;
        head = head->next;
        prev= head->val;
        head = head->next;
        while(head != nullptr){
            int cur = head->val;
            if((prev > cur && prev > pprev) || (prev < cur && prev < pprev))criticals.push_back(i);
            i++;
            pprev = prev;
            prev =cur;
            head = head->next;
        } 
        int n = criticals.size();
        if(n < 2) return{-1,-1};
        int mindis = INT_MAX;
        for(int i=1;i<n;i++){
            mindis = min(mindis,criticals[i]-criticals[i-1]);
        }
        return {mindis ,(criticals[n-1]-criticals[0])};
    }
};
