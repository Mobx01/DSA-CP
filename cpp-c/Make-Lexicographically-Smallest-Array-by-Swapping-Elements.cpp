/*Leetcode ps- 2948. Make Lexicographically Smallest Array by Swapping Elements
You are given a 0-indexed array of positive integers nums and a positive integer limit.
In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.*/


/* Approach - Transitive Equivalence Classes / Greedy Lexicographical Recombination (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate the infinite complexity of multi-step swapping by aggressively exploiting the transitive property, violently collapsing the sorted timeline into isolated equivalence groups to mathematically forge the absolute minimum array!
 * * Observation: 
 * - The absolute core of this architecture is the Transitive Masterstroke! If element A can swap with B, and B can swap with C, then A can mathematically swap with C! By aggressively sorting the array first, you perfectly flattened this complex graph into strictly contiguous blocks! Any two adjacent elements in the sorted copy that sit within the `limit` gap belong to the exact same freely-swappable universe!
 * - (The Heap Fragmentation Bomb): Look incredibly closely at `unordered_map<int, list<int>>`! You deployed a `std::list`! This is a catastrophic memory trap! Every single `push_back()` violently allocates a brand new isolated node on the heap, completely shattering your memory layout and ruthlessly thrashing the CPU cache! You MUST instantly upgrade this to `std::queue<int>` (which chunks memory using a `deque`), or for absolute peak hardware supremacy, use a `std::vector<int>` paired with a manual read-index array to perfectly lock everything into contiguous memory!
 * - (The Hashing Overhead Trap): You aggressively burn massive CPU cycles running the hash function in `unordered_map<int, int>` for every single element. While mathematically correct, you can completely bypass all hashing! If you originally sorted an array of pairs `{nums[i], original_index}`, you could strictly sweep through the contiguous blocks and instantly map the sorted values directly back into their original positions, dropping the heavy `unordered_map` engine entirely!
 * - (The Iterator Overhead): `*grouptolist[group].begin()`. Because you used a `list`, you are aggressively calling the iterator just to read the front element. If you switch to `queue`, this becomes a blazing fast `queue.front()` and `queue.pop()`!
 * * How it runs:
 * First, we safely intercept the original timeline and violently clone it into our `copy` register.
 * We instantly ignite the O(N log N) sorting engine, structurally forcing the elements into a strict ascending sequence to flawlessly expose their transitive boundaries!
 * We trigger a high-speed linear sweep! For every single element, we violently measure the gap to its predecessor. The exact millisecond the gap mathematically shatters the `limit`, we ruthlessly sever the connection, increment `groupnum`, and spawn a completely isolated timeline!
 * We aggressively map every single number to its designated group and slam the sorted values directly into the group's storage structure.
 * Finally, we ignite the reconstruction sequence! We sweep the original unsorted array, ping our radar to find the element's designated group, and aggressively extract the absolute lowest available integer from that group's pool! We lock it into `result` and flawlessly forge the lexicographically optimal array!
 */


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> copy = nums;
        int n = nums.size();
        sort(begin(copy),end(copy));
        int groupnum = 0;
        unordered_map<int,int> numtogroup;//which number belongs to which group
        numtogroup[copy[0]] = groupnum;

        unordered_map<int,list<int>> grouptolist;//groupno->elements
        grouptolist[groupnum].push_back(copy[0]);

        for(int i =1;i<n;i++){
            if(abs(copy[i] - copy[i-1]) > limit){
                groupnum += 1;
            }

            numtogroup[copy[i]] = groupnum;
            grouptolist[groupnum].push_back(copy[i]);
        }
        // build the answer - merge the groups
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = numtogroup[num];

            //smallest available number in the group
            result[i] = *grouptolist[group].begin();
            grouptolist[group].pop_front();
        }
        return result;
    }
};
