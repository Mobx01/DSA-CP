/*3661. Maximum Walls Destroyed by Robots
There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
robots[i] is the position of the ith robot.
distance[i] is the maximum distance the ith robot's bullet can travel.
walls[j] is the position of the jth wall.
Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.

A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.

Return the maximum number of unique walls that can be destroyed by the robots.

Notes:

A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
Robots are not destroyed by bullets.*/


class Solution {
public:
    vector<vector<int>> t;
    int countwall(vector<int>& walls, int L ,int R){
        if (L > R) return 0; // safety catch to prevent negative counts
        int left = lower_bound(begin(walls),end(walls) , L) - begin(walls); // the minimumi index where value is greater than l
        int right = upper_bound(begin(walls),end(walls),R) - begin(walls);// the maximum index where value is greater than r

        return right - left ; // number of walls than lie between both index
    }
    int solve(vector<int>& walls,vector<pair<int,int>>& robodis, vector<pair<int,int>>& range ,int i,int prevdir ){

        if(i == robodis.size()) return 0;

        if(t[i][prevdir] != -1) return t[i][prevdir];
        int lstart = range[i].first;

        if(prevdir == 1){ // previous robot fired  bullet right
            lstart = max(lstart , range[i-1].second +1); // skip walls that has been already broken by previous robot to skip duplicate counting
        }

        int ltake = countwall(walls,lstart,robodis[i].first) + solve(walls , robodis ,range,i+1,0);
        int rtake = countwall(walls,robodis[i].first,range[i].second) + solve(walls , robodis ,range,i+1,1);

        return (t[i][prevdir] =  max(ltake,rtake) );

    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
       int n = robots.size();
       vector<pair<int,int>> robodis(n);

       for(int i = 0 ; i< n;i++){
        robodis[i]={robots[i], distance[i]};
       }

       sort(begin(robodis),end(robodis));
       sort(begin(walls),end(walls));

       vector<pair<int,int>> range(n); // this stores range of each robot

       for(int i =0 ;i<n;i++){
        int pos = robodis[i].first;
        int d = robodis[i].second;

        int llimit = (i==0) ? 1 : robodis[i-1].first+1;
        
        // FIX: The next robot blocks by its position (.first), not its distance (.second)
        int rlimit = (i==n-1) ? INT_MAX :robodis[i+1].first-1; 

        int L = max(pos-d,llimit);
        int R = min(pos+d , rlimit);

        range[i] = {L,R};
       } 

       t.assign(n+1,vector<int>(2,-1));
       return solve(walls,robodis,range,0,0); // prev = 0/1 (previous robot hit bullet to left/right)

    }
};
