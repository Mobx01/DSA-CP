/*Leetcode ps-455. Assign Cookies
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.*/



/* Approach - Greedy Two-Pointer Matching / Monotonic Sorting Exhaustion (Time: O(N log N + M log M), Space: O(1) auxiliary)
 * Basically, we completely annihilate the combinatorial search space by aggressively sorting both greed factors and cookie sizes, mathematically proving that a greedy two-pointer match maximizes the total number of satisfied recipients!
 * * Observation: 
 * - The absolute core of this architecture is the Sorted Monotonic Match! By sorting both the children's greed factors (`g`) and the cookie sizes (`s`) in ascending order, you can satisfy children sequentially using the smallest possible cookies that meet their threshold. If a cookie is too small for the current child, it is permanently useless for that child and can be discarded, while larger cookies remain available for more demanding children.
 * - (The Redundant Break-Check Trap): Your algorithmic logic is absolute textbook perfection, but your loop termination control is slightly over-engineered! You run a `while(i < n)` loop and manually check `if (j == s.size()) break;`. You can completely streamline this by binding the loop condition directly to both arrays: `while (i < g.size() && j < s.size())`. This eliminates the explicit `break` branch, letting the hardware naturally terminate the loop the exact millisecond either the children or the cookies run out!
 * - (The Silicon Efficiency): Sorting dominates the time complexity at O(N log N + M log M), while the linear two-pointer scan executes in pristine O(N + M) time with zero auxiliary heap allocations (O(1) space), keeping instructions tightly cached.
 * * How it runs:
 * First, we safely intercept the arrays and execute the O(N log N + M log M) sorting engine on both vectors, locking them into strict ascending hierarchies.
 * We initialize our dual pointers (`i = 0`, `j = 0`) and our satisfaction counter.
 * We ignite the high-speed linear traversal engine. For every iteration, we test if the current cookie size `s[j]` is greater than or equal to the child's greed `g[i]`.
 * If it satisfies, we increment our `count`, advance both pointers (`i++`, `j++`) to move to the next child and cookie. If it falls short, we advance only the cookie pointer (`j++`) to find a larger offering.
 * Finally, we flush the total count of satisfied children to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i =0,j=0,count=0,n=g.size();
        while(i<n){
            if(j == s.size()){
                    break;
                }
            if(s[j] >= g[i]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return count;
    }
};
