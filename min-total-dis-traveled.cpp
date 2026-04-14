/*Leetcode ps- 2463. Minimum Total Distance Traveled
There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.
The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.
All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.
At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.
Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.
Note that
All robots move at the same speed.
If two robots move in the same direction, they will never collide.
If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
If the robot moved from a position x to a position y, the distance it moved is |y - x|.
*/

class Solution {
public:
    long long t[101][101]; 

    long long solve(int r_idx, int f_idx, vector<int>& robot, vector<vector<int>>& factory) {
        if (r_idx == robot.size()) return 0;
        if (f_idx == factory.size()) return 1e18;
        if (t[r_idx][f_idx] != -1) return t[r_idx][f_idx];

        // Skip the current factory 
        long long ans = solve(r_idx, f_idx + 1, robot, factory);

        // assign k robots to current factory
        long long current_dist = 0;
        int limit = factory[f_idx][1];
        
        // Assign  1 - limit robots to factory
        for (int k = 1; k <= limit && r_idx + k - 1 < robot.size(); ++k) {
            
            current_dist += abs(robot[r_idx + k - 1] - factory[f_idx][0]);
            
            long long next_ans = solve(r_idx + k, f_idx + 1, robot, factory);
            
            if (next_ans != 1e18) {
                ans = min(ans, current_dist + next_ans);
            }
        }

        return t[r_idx][f_idx] = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        for(int i =0 ;i<101;i++){
            for(int j =0 ;j<101;j++){
                t[i][j] = -1;
            }
        }

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        return solve(0,0,robot,factory);
    }
};
