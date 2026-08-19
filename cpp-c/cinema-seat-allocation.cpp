/*Leetcode ps - 1386. Cinema Seat Allocation
A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.
You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.
A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:
seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.
Return an integer denoting the maximum number of four-person groups that can be assigned.*/



/* Approach - Sparse Matrix Aggregation / Greedy Block Allocation (Time: O(R), Space: O(R) where R is reserved seats)
 * Basically, we completely annihilate the massive O(N) row simulation by aggressively hyper-focusing ONLY on the rows that actually contain humans, mathematically batch-processing the untouched rows in a single blistering CPU cycle!
 * * Observation: 
 * - The absolute core of this problem is the massive constraint: `n` can be up to 10^9! If you physically ran a `for` loop from 1 to `n` checking every single row, the servers would violently crash into a Time Limit Exceeded (TLE) error!
 * - (The Sparse Matrix Masterstroke): You brilliantly bypassed the void! By strictly logging ONLY the rows with reservations into an `unordered_map`, you instantly extracted the total number of perfectly empty rows using `(n - mp.size())`. You aggressively multiplied this by 2, mathematically locking in massive chunks of your result without simulating a single seat!
 * - (The Overlap Logic): Your geometric grouping (A, B, C) perfectly maps the strict layout rules. You correctly identified that Group B (the middle 4) structurally conflicts with both A and C. Therefore, the absolute maximum a polluted row can yield is either 2 (if both ends A and C survive) or 1 (if ANY of the three blocks survive)!
 * - (Optimization Alert / The Bitwise Nuke): You deployed an `unordered_set<int>` to track the seats inside each row. For a maximum of just 10 seats, a hash set is a catastrophic waste of dynamic memory allocation and pointer overhead! You can completely annihilate it by swapping to `unordered_map<int, int>` and treating the row as a pure 32-bit integer bitmask! 
 * - (The O(1) Bitwise Hardware Upgrade): 
 *   - When reading a seat `s`, aggressively lock it into the row's integer mask using bitwise OR: `mp[row] |= (1 << s)`.
 *   - Group A (seats 2,3,4,5) mathematically equals the binary mask `60`.
 *   - Group B (seats 4,5,6,7) equals the binary mask `240`.
 *   - Group C (seats 6,7,8,9) equals the binary mask `960`.
 *   - Instead of calling `isavail` FOUR separate times per group, you violently smash the entire row mask against the block mask using bitwise AND: `if ((mask & 60) == 0)`! This completely shreds 12 expensive hash map `.find()` lookups down to 3 lightning-fast, hardware-level bitwise operations!
 * * How it runs:
 * First, we safely intercept the `reservedSeats` matrix and aggressively populate our hash map, isolating only the contaminated rows.
 * We instantly lock in our baseline `result` by calculating the completely empty rows and forcefully doubling them.
 * Next, we ignite a high-speed iteration through ONLY the polluted rows. 
 * We trigger our boolean radars (`grpa`, `grpb`, `grpc`), meticulously checking the structural integrity of the 4-seat blocks.
 * If the extreme ends (`grpa` and `grpc`) are both mathematically pristine, we aggressively claim 2 families! If they fail, but ANY block survived the reservations, we ruthlessly salvage 1 family!
 * Finally, we confidently return the absolute maximum `result`, flawlessly crushing the massive 10^9 theater space in absolute peak theoretical time!
 */


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp; // rpw->bookedseats in the row
        for(auto& v : reservedSeats){
            mp[v[0]].insert(v[1]);
        }
        int result = (n - mp.size())*2;//rows fully empty can store 2 groups
        for(auto& [row,seats] : mp ){

            auto isavail = [&](int s){
                return seats.find(s) == seats.end();
            };

            bool grpa = isavail(2) && isavail(3) && isavail(4) && isavail(5);
            bool grpb = isavail(4) && isavail(5) && isavail(6) && isavail(7);
            bool grpc = isavail(6) && isavail(7) && isavail(8) && isavail(9);

            if(grpa && grpc){//can fill 2 groups
                result += 2;
            }else if(grpa || grpb || grpc) result++;
        }
        return result;
    }
};
//ignore seat 1 and 10.
// we can book all 3 group in a row -> maximum we can get 2 group of seats(when all seats are empty)
