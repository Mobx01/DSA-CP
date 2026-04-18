/*Leetcode ps - 2751. Robot Collisions
There are n 1-indexed robots, each having a position on a line, health, and movement direction.
You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.
All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.
If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.
Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.
Note: The positions may be unsorted.
*/

/**
 * SIMULATION LOGIC:
 * 1. SORT: Process robots by physical position (left-to-right).
 * 2. STACK: Store robots moving 'R' in a stack as they wait for collisions.
 * 3. COLLIDE: When a robot moves 'L', it duels the stack's top 'R' robot.
 * - If L > R: Pop R, decrement L's health, and keep colliding.
 * - If L < R: Stop L, decrement R's health in the stack.
 * - If L == R: Pop R and stop L.
 * 4. OUTPUT: Return remaining healths in their original input order.
 */

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> opos(n);
        for(int i = 0; i < n; i++) {
            opos[i] = i;
        }

        // Sort indices based on their physical positions
        sort(opos.begin(), opos.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        stack<int> right; //indices of robots moving Right
        
        for(int i = 0; i < n; i++) {
            int curr = opos[i]; // The actual index of the robot 

            if(directions[curr] == 'R') {
                right.push(curr);
            } 
            else { // Robot is moving 'L'
                while(!right.empty() && healths[curr] > 0) {
                    int topIdx = right.top();

                    if(healths[topIdx] > healths[curr]) {
                        // Right robot wins
                        healths[topIdx] -= 1;
                        healths[curr] = 0;
                    } 
                    else if(healths[topIdx] < healths[curr]) {
                        // Left robot wins
                        healths[curr] -= 1;
                        healths[topIdx] = 0;
                        right.pop();
                    } 
                    else {
                        // Tie - both destroyed
                        healths[curr] = 0;
                        healths[topIdx] = 0;
                        right.pop();
                    }
                }
            }
        }

        // Collect healths of robots that didn't reach 0
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) {
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};
