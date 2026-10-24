/*Leetcode ps - 2409. Count Days Spent Together
Alice and Bob are traveling to Rome for separate business meetings.
You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
Return the total number of days that Alice and Bob are in Rome together.
You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
*/





/* Approach - Lexicographical Date Overlap with Prefix-Sum Day-of-Year Conversion (Time: O(1), Space: O(1))
 * Basically, we completely annihilate previous type-casting bugs by aggressively parsing month-day substrings with `stoi` and accumulating calendar prefix sums, calculating exact overlapping days in pristine constant time and space!
 * * Observation: 
 * - The absolute core of this architecture is the Resolved Date-to-Day Invariant (LeetCode 2409 - Count Days Spent Together)! By leveraging string `max` and `min` on zero-padded `"MM-DD"` formats, we securely isolate the overlapping interval boundaries (`cariv` to `cleav`). Converting month and day components into absolute day-of-year integers via prefix sums of `days` transforms calendar math into straightforward arithmetic.
 * - (Robust Integer Conversion & Accumulation): Replacing the flawed string arithmetic with explicit `stoi()` parsing (`amn`, `ad`, `cmn`, `cd`) and summing month lengths up to `month - 1` guarantees precise day-of-year indexing.
 * - (Inclusive Span Calculation): Adding `+1` to `(et - st)` correctly captures the inclusive nature of overlapping days spent together.
 * * How it runs:
 * First, we determine the overlapping start date `cariv` and end date `cleav`, returning `0` immediately if `cariv > cleav`.
 * We extract month and day integers using `stoi` for both the start and end of the overlap window.
 * We compute absolute day-of-year indices `st` and `et` by adding the day count to the sum of preceding month lengths.
 * Finally, we flush the total inclusive overlapping days (`et - st + 1`) to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string cariv = max(arriveAlice, arriveBob);
        string cleav = min(leaveAlice, leaveBob);

        if (cariv > cleav) {
            return 0;
        }

        int amn = stoi(cariv.substr(0, 2));
        int ad = stoi(cariv.substr(3, 2));
        int cmn = stoi(cleav.substr(0, 2));
        int cd = stoi(cleav.substr(3, 2));

        int st = ad;
        for (int i = 0; i < amn - 1; ++i) {
            st += days[i];
        }

        int et = cd;
        for (int i = 0; i < cmn - 1; ++i) {
            et += days[i];
        }

        int ans = (et - st) + 1;
        return ans;
    }
};


