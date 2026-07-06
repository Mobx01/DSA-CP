/*Leetcode ps- 875. Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.*/


/* Approach - Binary Search on Answer (Time: O(N log M), Space: O(1))
 * Basically, we find the absolute minimum eating speed 'k' by guessing the answer using Binary Search, as the relationship between eating speed and total time is perfectly monotonic.
 * * Observation:
 * - Koko can only eat from one pile per hour. Thus, the absolute maximum speed she would ever practically need is the size of the largest pile in the array.
 * - For any given speed 'k', the hours needed for a specific pile is the ceiling division of `pile / k`. If a chosen speed 'mid' allows her to finish within 'h' hours, it is valid, but a strictly slower speed might ALSO work.
 * * How it runs:
 * First, we establish our search boundaries: 'mink' is 1 (slowest possible speed) and 'maxk' is the maximum element found in the 'piles' array.
 * Then, we enter our standard binary search loop, guessing a middle speed ('mid') and passing it to our 'ispossible' helper function.
 * Inside 'ispossible', we loop through every pile, using ternary logic `(piles[i] % k == 0) ? piles[i]/k : piles[i]/k + 1` to achieve precise ceiling division without slow floating-point math, returning false early if she exceeds 'h'.
 * Finally, if 'ispossible' returns true, we record 'mid' as our best answer and pull 'maxk' down to hunt for an even slower valid speed. If false, we push 'mink' up. We return 'k' once the boundaries cross!
 */


class Solution {
public:
    bool ispossible(int k , vector<int>& piles,int h){
        int n = piles.size();
        long long count = 0 ;
        for(int i = 0;i<n;i++){
            count += (piles[i] % k == 0) ? piles[i]/k  : piles[i]/k + 1;
            if(count > h) return false;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // binaaary search on k
        int mink = 1 ,maxk = *max_element(piles.begin(), piles.end()),k=maxk;
        while(mink <= maxk){
            int mid = mink + (maxk-mink)/2;

            if(ispossible(mid,piles,h)){
                k = mid;
                maxk = mid-1;
            }else{
                mink = mid+1;
            }
        }
        return k;
    }
};
