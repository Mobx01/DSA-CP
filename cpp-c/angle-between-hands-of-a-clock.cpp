/*Leetcode ps - 1344. Angle Between Hands of a Clock
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
Answers within 10-5 of the actual value will be accepted as correct.*/

/*  Rough work
   in 1 hr , hr hand moves 30 degree.
   in 60 min , hr hand moves 30 degree.
   in 1 min , hr hand moves .5 degree (30/60).

   in 1 min , min hand moves 6 degree.


   calculate angle (wrt 12 mark on clock) of both hour and min hand and then calulate angle between them

   for min - angle = minute*6
   for hr - angle = hr*30 + min*(.5)
 
 */

/*
 * Approach: Calculate both angles relative to the 12:00 mark.
 *
 * 1. Minute Hand:
 * - The minute hand completes a full 360-degree circle in 60 minutes.
 * - This means it moves exactly 6 degrees every minute.
 * - Formula: min_angle = minutes * 6
 *
 * 2. Hour Hand:
 * - The hour hand completes a 360-degree circle in 12 hours.
 * - This gives us a base of 30 degrees per hour.
 * - Crucially, it doesn't just jump from hour to hour; it creeps forward 
 * as the minutes pass. Since it covers 30 degrees in 60 minutes, it 
 * moves an additional 0.5 degrees per minute.
 * - Formula: hr_angle = (hour * 30) + (minutes * 0.5)
 *
 * 3. Finding the difference:
 * - Subtract the two angles and get the absolute difference.
 * - Because a clock is a circle, the hands actually form two angles 
 * (an inner and an outer angle) that sum to 360 degrees. 
 * - The problem asks for the smaller one, so we just return the 
 * minimum of our calculated difference and (360 - difference).
 *
 * Complexity:
 * - Time: O(1) - Just a few simple math operations.
 * - Space: O(1) - No extra data structures used.
 */


class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minangle = minutes*6;
        double hrangle = hour*30 + minutes*(0.5);

        double angle = abs(minangle-hrangle);
        return min(angle , 360.0-angle);
    }
};
