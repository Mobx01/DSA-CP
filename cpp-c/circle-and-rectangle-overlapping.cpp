/*Leetcode ps-1401. Circle and Rectangle Overlapping
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.*/



/* Approach - Nearest Point Clamping / Euclidean Boundary Projection (Time: O(1), Space: O(1))
 * Basically, we completely annihilate complex geometric trigonometry by aggressively projecting the circle's center to the nearest point on the axis-aligned rectangle, checking containment via squared distance in pristine constant time!
 * * Observation: 
 * - The absolute core of this architecture is the Clamping Strategy (LeetCode 1401 - Circle and Rectangle Overlapping)! By clamping the circle center `(xCenter, yCenter)` against the rectangle's horizontal bounds `[x1, x2]` and vertical bounds `[y1, y2]`, we instantly locate the absolute closest point on or inside the rectangle. If the center is already inside, the closest point maps right back to the center itself (`dx = 0, dy = 0`), ensuring instant validation.
 * - (Overflow-Safe Arithmetic Protection): Using `long long dx = xi - xCenter;` and casting to `(long long)radius * radius` is a brilliant defensive engineering choice. It completely prevents 32-bit integer overflow during squared distance calculations when coordinate ranges stretch large.
 * - (Zero Trigonometric Overhead): Avoiding square roots (`std::sqrt`) by comparing squared distances (`dx * dx + dy * dy <= r * r`) keeps the evaluation running at peak hardware speed with zero floating-point performance penalties.
 * * How it runs:
 * First, we determine the closest x-coordinate (`xi`) on the rectangle by clamping `xCenter` between `x1` and `x2`.
 * We similarly determine the closest y-coordinate (`yi`) by clamping `yCenter` between `y1` and `y2`.
 * We compute the squared horizontal and vertical deltas (`dx`, `dy`) from the circle's center to this nearest boundary point.
 * Finally, we compare the total squared Euclidean distance against the squared radius and flush the boolean overlap status to the output stream with absolute mathematical precision at raw silicon speed!
 */


class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //closest x and y coordinates on the rectangle to the circle center
        int xi, yi;

        if (x1 > xCenter) xi = x1;
        else if (x2 < xCenter) xi = x2;
        else xi = xCenter; 

        if (y1 > yCenter) yi = y1;
        else if (y2 < yCenter) yi = y2;
        else yi = yCenter; 

        long long dx = xi - xCenter;
        long long dy = yi - yCenter;
        
        return (dx * dx + dy * dy) <= (long long)radius * radius;
    }
};
