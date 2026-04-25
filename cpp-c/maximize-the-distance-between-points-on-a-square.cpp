/*Leetcode ps- 3464. Maximize the Distance Between Points on a Square
You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.
You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.
You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.
Return the maximum possible minimum Manhattan distance between the selected k points.
The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.*/

/*
Approach:

Step 1: Flattening the Square
- We calculate a 1D distance for each point based on which side it sits on (moving clockwise).
- Finally, we sort these 1D distances so they are in order.

Step 2: Binary Search on Answer
- Instead of calculating exact placements, we guess a distance ('mid').
- If we can place k points separated by at least 'mid' distance, we try a larger guess (low = mid + 1).
- If we can't, our guess was too big, so we try a smaller one (high = mid - 1).

Step 3: Handling the Circular Wrap-around
- The square is a closed loop. Unrolling it creates a problem: the last placed point might be too close to the first point across the "seam".
- To fix this easily, we duplicate our sorted array and attach it to the end.
- We add the total perimeter length to these duplicated points.
- This perfectly simulates walking past the end of the square and looping back around.

Step 4: Greedily Picking Points
- In the check function, we try every single point in the original array as our starting position.
- From our start point, we need to find the next point that is at least 'mid' distance away.
- we use `lower_bound` to instantly jump to the next valid point.
- We keep jumping until we either place k points or run out of valid points.

Step 5: The Final Gap Check
- If we successfully grab k points, we do one last wrap-around check.
- We check the distance between our last placed point and the "wrapped-around" version of our start point.
- If this final gap is also >= 'mid', the setup is completely valid and we return true.
- If we try every start point and none of them work out, we return false.
*/

class Solution {
public:
    vector<long long> dis;

  bool check(long long mid, int k, int side) {
        int n = dis.size();
        long long L = 4LL * side; // Total perimeter
        
        // Duplicate the array to unroll the square into a straight line.(handles circular nature)
        vector<long long> A(2 * n);
        for (int i = 0; i < n; i++) {
            A[i] = dis[i];
            A[i + n] = dis[i] + L;
        }
        
        // Check for start point in 'dis' as start
        for (int i = 0; i < n; i++) {
            int count = 1; 
            long long last_placed = A[i]; //start point
            int cur_idx = i; // tracks our current position (for lowerbound)
            
            // Check for the next points check for till i + n - 1 (one full loop around)
            while (count < k) {
                // at least 'mid' distance
                auto it = lower_bound(A.begin() + cur_idx + 1, A.begin() + i + n, last_placed + mid);
                
                
                if (it == A.begin() + i + n) {// if we reach the end , no valid next point
                    break; 
                }
                
                cur_idx = distance(A.begin(), it);
                last_placed = A[cur_idx];
                count++;
                
                if (count == k) {
                    // if the distance between the last point placed and the starting point >= mid. (A[i + n] is starting point(circular nature).
                    if (A[i + n] - last_placed >= mid) {
                        return true; 
                    }
                    break; //the final gap was less than assumed distance mid 
                }
            }
        }
        
        // If none of the points satisfy condition then assumption was wrong
        return false; 
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        // calculating distance of each point if i move clockwise throughout the square
        for(auto& p : points){// p is coordinated of each points
           long long x = p[0]; //x coordinate
           long long y = p[1]; //y coordinate
           if(x == 0) dis.push_back(y); //left side
           else if(y == side) dis.push_back(side+x); //top side 
           else if(x == side) dis.push_back(3*(long long)side - y); // right side
           else dis.push_back(4*(long long)side - x); // bottom side
        }


        //applying binary seach to check all distance which adjust k points and chhose maximum one 

        sort(dis.begin() , dis.end()); // sort for binary search


        int low = 1; // minimum distance can be 1 because all points are unique so it can't be 0
        int high = side ; //minimum(k) =  4 so choose all corners  then manhanttan distance = side
        long long mid , maxdis = 0;
        while(low <= high){
            mid = low + (high-low)/2;
            if(check(mid,k,side)){ //checks if k points can be adjusted
                maxdis = mid;//if yes then ans is mid then explore higher distance
                low = mid+1;
            }
            else high = mid-1;//else explore lower distance
        }
        return maxdis;
    }
};
