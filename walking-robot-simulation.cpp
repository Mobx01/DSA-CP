/*Leetcode ps- 874. Walking Robot Simulation
A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:
-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.
Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).
Note:
There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.*/
/*
APPROACH:
1.  STARTING POINT: 
    The robot starts at coordinates (0,0) facing 'North'. We use a cyclic array 
    {'N', 'W', 'S', 'E'} to manage directions easily.

2.  HANDLING TURNS:
    - If command is -2 (Left): Move 90 degrees counter-clockwise in our direction array.
    - If command is -1 (Right): Move 90 degrees clockwise.

3.  HANDLING MOVEMENT (The 'move' function):
    - First, we calculate where the robot *wants* to go if there were no obstacles.
    - Then, we look at every single obstacle in the list.
    - If an obstacle lies exactly on our path (same X-axis for N/S, same Y-axis for E/W):
        - We check if the obstacle's coordinate is between our current spot and our target.
        - If it is, we "block" the robot by updating our target to be exactly 1 step 
          before that obstacle.
    - This ensures that if multiple obstacles are in the way, the robot stops at the 
      very first one it hits.

4.  TRACKING DISTANCE:
    - After every move command, we calculate the current Euclidean distance squared (x*x + y*y).
    - We keep track of the maximum value encountered during the entire trip and return it.
*/


class Solution {
public:
    vector<int> move(vector<int>& pos , char curdir ,int dis, vector<vector<int>>& obstacles){
        vector<int> ret = pos;
        int n = obstacles.size();
        //without obstacle
        if(curdir == 'N') ret[1]+=dis; // y+=dis
        else if(curdir == 'S') ret[1] -= dis;// y-=dis
        else if(curdir =='E') ret[0]+=dis;  // x+=dis
        else if(curdir =='W') ret[0]-= dis;// x-=dis

        //update ret with considering obstacle
        for (int i = 0; i < n; i++) {
            int ox = obstacles[i][0];
            int oy = obstacles[i][1];

            if (curdir == 'N') {
                // Must be on same X, and obstacle Y must be between current and target
                if (ox == pos[0] && oy > pos[1] && oy <= ret[1]) {
                    ret[1] = oy - 1; 
                }
            } 
            else if (curdir == 'S') {
                // Same as above but the > and < excahnges because we checking in downward direction
                if (ox == pos[0] && oy < pos[1] && oy >= ret[1]) {
                    ret[1] = oy + 1;
                }
            } 
            else if (curdir == 'E') {
                // same Y, and X must be between current and target
                if (oy == pos[1] && ox > pos[0] && ox <= ret[0]) {
                    ret[0] = ox - 1;
                }
            } 
            else if (curdir == 'W') {
                if (oy == pos[1] && ox < pos[0] && ox >= ret[0]) {
                    ret[0] = ox + 1;
                }
            }
        }
        return ret;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> pos(2,0); //[x,y]
        vector<char> dir(4); //contains all direction;
        dir[0] = 'N'; //assign all possible direction in anticlockwise direction.
        dir[1] = 'W';
        dir[2] = 'S';
        dir[3] = 'E';
        int j =0; // initially facing north
        int maxdis = 0;
        char curdir = dir[j];
        for(int i : commands){
            if(i == -2){
                j = (j+1)%4; // using concept of cyclic array.
                curdir = dir[j];
            }
            else if( i == -1){
                j = (j==0) ? 3 : j-1 ;
                curdir = dir[j];
            }
            else{
                pos = move(pos,curdir,i,obstacles);
                int dis = pos[1]*pos[1] + pos[0]*pos[0];
                maxdis = max(maxdis , dis);
            }
        }
        return maxdis;
    }
};
