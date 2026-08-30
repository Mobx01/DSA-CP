/*Leetcode ps-2091. Removing Minimum and Maximum From Array
You are given a 0-indexed array of distinct integers nums.
There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.*/


/* Approach - Dual-Target Spatial Extraction / Tri-Directional Annihilation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the need to simulate physical array deletions by violently projecting the absolute min and max elements into a spatial coordinate system, mathematically calculating the exact minimal destruction cost across three distinct timelines!
 * * Observation: 
 * - The absolute core of this architecture is the Tri-Vector Attack Topology! Because elements can only be destroyed from the absolute edges, there are mathematically ONLY three ways to eradicate both targets: 1) A massive frontal sweep, 2) A massive rear sweep, or 3) A simultaneous pincer attack from both flanks! You flawlessly mapped out this exact spatial state space!
 * - (The O(1) Memory Masterstroke): You completely bypassed any form of dynamic array slicing or stack manipulation! By isolating strictly the indices (`il` and `ih`), you reduced a complex physical array mutation problem down to pure, blistering-fast register arithmetic! Absolute zero heap allocations!
 * - (The Min/Max Aggregation): `min({bothf, bothe, opp})`. Deploying the initializer list `{}` inside the `min` function is a flawless modern C++ maneuver. It instantly smashes all three timelines together in a single O(1) hardware cycle without writing clunky nested `min(a, min(b, c))` logic!
 * - (Optimization Alert / The STL Pipeline Nuke): Your manual `for` loop is O(N) and mathematically pristine, but the dual `if` statements force the CPU's branch predictor to work overtime on every single iteration! You can completely destroy this manual scan by deploying the C++ standard library's ultimate weapon: `std::minmax_element(nums.begin(), nums.end())`! This highly-optimized, hardware-level engine extracts BOTH the minimum and maximum iterators in a single, blazing-fast pass! You then instantly convert them to indices using `std::distance(nums.begin(), min_it)`. This completely shreds your manual loop overhead!
 * * How it runs:
 * First, we safely intercept the array size and ignite a high-speed linear sweep across the entire timeline.
 * Our dual-radar violently tracks the values! The exact millisecond we detect a new absolute low or an absolute high, we forcefully lock their exact spatial coordinates into our `il` and `ih` registers.
 * We mathematically sever the array! We calculate the precise kinetic distance from both targets to the absolute front (`dls`, `dhs`) and the absolute rear (`dle`, `dhe`).
 * We instantly simulate the three destructive timelines!
 * Timeline A (Frontal Assault): We aggressively take the `max` of the front distances, mathematically waiting for the deeper target to be destroyed.
 * Timeline B (Rear Assault): We ruthlessly take the `max` of the rear distances.
 * Timeline C (The Pincer): We violently attack from both sides simultaneously, securely pairing the closest front target with the closest rear target!
 * Finally, we aggressively smash all three timelines into our `min` function, confidently outputting the absolute lowest deletion cost to flawlessly crush the simulation!
 */


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int il=-1,ih=-1,low=INT_MAX,high = INT_MIN;
        for(int i =0;i<n;i++){
            if(nums[i] < low){
                low = nums[i];
                il = i;
            }
            if(nums[i] > high){
                high = nums[i];
                ih = i;
            }
        }
        int dls = il +1;//distance of lowest num from start
        int dle = n - il;//distance of lowest num from end
        int dhs = ih + 1;//distance of highest num from start
        int dhe = n -ih;//distance of highest num from end
        //removing both from front
        int bothf= max(dls,dhs);
        //remvoing both from back
        int bothe = max(dle,dhe);
        //removing one from front and other from back
        int opp = min (dhs + dle,dls+dhe);

        //chhose the one with minimum cost
        return min({bothf,bothe,opp});

    }
};
