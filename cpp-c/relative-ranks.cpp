/*Leetcode ps -506. Relative Ranks
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.*/



/* Approach - Pair-Indexed Descending Sorting / Rank Mapping (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate complex rank lookups by aggressively pairing scores with their original indices, sorting in descending order, and mapping medals or string ranks in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Index-Preserving Ranking Invariant (LeetCode 506 - Relative Ranks)! When sorting scores to determine athlete ranks, the original positions must be preserved so that the output rank strings align correctly with the input `score` order. Pairing each score with its 0-based index `(score[i], i)` before sorting solves this mapping challenge seamlessly.
 * - (Medal Formatting Logic): The top three athletes receive specific string labels (`"Gold Medal"`, `"Silver Medal"`, `"Bronze Medal"`), while all remaining participants are assigned their 1-based rank converted via `to_string(i + 1)`.
 * - (Log-Linear Sorting Efficiency): Leveraging `std::sort` with reverse iterators (`sc.rbegin()`, `sc.rend()`) orders the pairs from highest score to lowest in $O(N \log N)$ time with minimal auxiliary space.
 * * How it runs:
 * First, we initialize a vector of pairs `sc` storing each score alongside its original index, along with our result vector `ans` of size `n`.
 * We sort `sc` in descending order based on the score values.
 * We ignite a linear scan across the sorted pairs: assigning gold, silver, or bronze medals for indices `0`, `1`, and `2`, and stringified rank numbers for the rest, placing each value into `ans` at the original index `sc[i].second`.
 * Finally, we flush the resulting rank vector to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> sc;
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            sc.push_back({score[i],i});
        }
        sort(sc.rbegin(),sc.rend());
        for(int i=0;i<n;i++){
            if(i == 0){
                ans[sc[i].second] = "Gold Medal";
            }else if(i == 1){
                ans[sc[i].second] = "Silver Medal";
            }else if(i == 2){
                ans[sc[i].second] = "Bronze Medal";
            }else{
                ans[sc[i].second] = to_string(i+1);
            }
        }
        return ans;
    }
};
