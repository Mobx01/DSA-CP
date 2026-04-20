/*Leetcode ps- 2078. Two Furthest Houses With Different Colors
There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.
Return the maximum distance between two houses with different colors.
The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x*/

/*
The Golden Rule: The absolute furthest apart any two houses can be is the very first house and the very last house.
So, you start by looking at the first and last house. There are only two possibilities:

Scenario A: They are different colors.
BOOM. You are done. You just found the maximum possible distance. It physically cannot get wider than the first and last house.

Scenario B: They are the same color.
Uh oh. Since they are the same color, this maximum width doesn't count. You have to shrink your gap to find a different color. But here is the problem: Who takes a step inward? Do you move inward from the left side, or from the right side?

Because you don't know which side will give you a better result, you just test both.

Test 1 (Left Side Focus): You look at the left side. If the next house inward is a different color, you move the left side inward. If not, you move the right side inward. You keep shrinking until you hit two different colors. Note that distance.

Test 2 (Right Side Focus): You reset back to the start and end. This time, you focus on the right side. If the next house inward is a different color, you move the right side inward. If not, you move the left side inward. Note that distance.*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0 , j = colors.size()-1,maxdis = 1;
        while(i<j){
            if(colors[i] != colors[j]) {
                maxdis = max(maxdis, j-i);
                break;
            }
            else if(colors[i+1] != colors[i]) i++;
            else j--;
        }
        i = 0 , j = colors.size()-1;
        while(i<j){
            if(colors[i] != colors[j]) {
                maxdis = max(maxdis,j-i);
                break;
            }
            else if(colors[j-1] != colors[j]) j--;
            else i++;
        }
        return maxdis;
    }
};
