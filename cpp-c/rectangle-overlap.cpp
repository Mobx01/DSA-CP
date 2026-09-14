/*Leetcode ps-836. Rectangle Overlap
An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.
Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.
Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.*/



/* Approach - Inverse Non-Overlap Boundary Projection / Axis-Aligned Bounding Box Intersection (Time: O(1), Space: O(1))
 * Basically, we completely annihilate complex geometric intersection edge cases by aggressively inverting the problem, defining the four exclusive spatial separation rules and negating them to confirm an overlap in pristine O(1) constant time!
 * * Observation: 
 * - The absolute core of this architecture is the Inverse Separation Law! Trying to directly compute overlapping areas or handle partial cuts, containment, and corner touches introduces a combinatorial explosion of messy conditional branches. Instead, you brilliantly flip the perspective: two rectangles fail to overlap if and only if one is completely to the left, right, below, or above the other (`isLeft`, `isRight`, `isBelow`, `isAbove`). Negating the union of these four non-overlap states instantly yields the exact intersection condition with absolute mathematical elegance!
 * - (Clean Coordinate Mapping): Your variable naming convention (`x11`, `y11`, `x12`, `y12`) cleanly maps out the bottom-left and top-right boundaries of both rectangles, keeping the spatial logic transparent and completely bug-free.
 * * How it runs:
 * First, we safely intercept and unpack the coordinate points of both rectangles from the input vectors.
 * We evaluate the four exclusive boundary conditions, checking if `rec1` is strictly disjoint from `rec2` along the horizontal or vertical axes.
 * We combine these boolean flags using logical disjunction and invert the result: if none of the separation barriers are met, an intersection is guaranteed.
 * Finally, we flush the boolean overlap status to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11 = rec1[0];
        int y11 = rec1[1];
        int x12 = rec1[2];
        int y12 = rec1[3];
        int x21 = rec2[0];
        int y21 = rec2[1];
        int x22 = rec2[2];
        int y22 = rec2[3];

        // The 4 cases where rectangles CANNOT overlap:
        bool isLeft = x12 <= x21;   // rec1 is completely to the left of rec2
        bool isRight = x11 >= x22;  // rec1 is completely to the right of rec2
        bool isBelow = y12 <= y21;  // rec1 is completely below rec2
        bool isAbove = y11 >= y22;  // rec1 is completely above rec2

        // If it is none of these things, it MUST be overlapping
        return !(isLeft || isRight || isBelow || isAbove);
    }
};
