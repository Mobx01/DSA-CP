/*657. Robot Return to Origin
There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).
Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.
Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.*/


// approach:- 
// assuming magnitude of each step to be 1 .
// if current is (x,y)- then R- x++ , L -x-- , U -y++ , D - y--;
// return true if x== 0 and y==0
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> pos(2,0);

        for(char i : moves){
            if(i == 'R') pos[0]++ ;
            else if(i == 'L') pos[0]--;
            else if(i == 'U') pos[1]++ ;
            else if(i == 'D') pos[1]--;
        }

        return (pos[0] == 0 && pos[1] == 0);
    }
};
