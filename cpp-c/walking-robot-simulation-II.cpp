/*Leetcode ps - 2069. Walking Robot Simulation II
A width x height grid is on an XY-plane with the bottom-left cell at (0, 0) and the top-right cell at (width - 1, height - 1). The grid is aligned with the four cardinal directions ("North", "East", "South", and "West"). A robot is initially at cell (0, 0) facing direction "East".
The robot can be instructed to move for a specific number of steps. For each step, it does the following.

Attempts to move forward one cell in the direction it is facing.
If the cell the robot is moving to is out of bounds, the robot instead turns 90 degrees counterclockwise and retries the step.
After the robot finishes moving the number of steps required, it stops and awaits the next instruction.

Implement the Robot class:

Robot(int width, int height) Initializes the width x height grid with the robot at (0, 0) facing "East".
void step(int num) Instructs the robot to move forward num steps.
int[] getPos() Returns the current cell the robot is at, as an array of length 2, [x, y].
String getDir() Returns the current direction of the robot, "North", "East", "South", or "West".*/

class Robot {
public:
    int w, h, x, y, curdir;
    bool moved;
    vector<string> dir = {"East","North","West","South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0; // x-coordinate(initially)
        y = 0; // y-coordinate(initially)
        curdir = 0; //initially east
        moved = false;
    }
    
    void step(int num) {
        moved = true;
        int perimeter = 2 * (w - 1) + 2 * (h - 1);
        num %= perimeter;
        
        if (num == 0) {
            if (x == 0 && y == 0) curdir = 3; 
            else if (x == w - 1 && y == 0) curdir = 0;
            else if (x == w - 1 && y == h - 1) curdir = 1;
            else if (x == 0 && y == h - 1) curdir = 2;
            return;
        }

        while (num > 0) {
            // Moving East (+x)
            if (curdir == 0) { 
                int dist = min(num, (w - 1) - x); // Distance to the right bound
                x += dist;
                num -= dist;
                if (num > 0) curdir = 1; // North
            } 
            //  Moving North (+y)
            else if (curdir == 1) { 
                int dist = min(num, (h - 1) - y); // Distance to the top bound
                y += dist;
                num -= dist;
                if (num > 0) curdir = 2; // West
            } 
            // Moving West (-x)
            else if (curdir == 2) { 
                int dist = min(num, x); // Distance to the left edge (x = 0)
                x -= dist;
                num -= dist;
                if (num > 0) curdir = 3; // South
            } 
            // Moving South (-y)
            else if (curdir == 3) { 
                int dist = min(num, y); // Distance to the bottom edge (y = 0)
                y -= dist;
                num -= dist;
                if (num > 0) curdir = 0; //  East
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dir[curdir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
