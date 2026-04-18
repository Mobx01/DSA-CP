/* LeetCode PS 3074 :- Apple Redistribution into Boxes
   You are given an array apple of size n and an array capacity of size m.
   There are n packs where the ith pack contains apple[i] apples. There are
   m boxes as well, and the ith box has a capacity of capacity[i] apples.
   Return the minimum number of boxes you need to select to redistribute these
   n packs of apples into boxes.
   Note that, apples from the same pack can be distributed into different boxes.

  #Intuition
  
    The goal is to use the minimum number of boxes.
    To achieve this, we should always use the boxes with the largest
    capacity first, as they can store more apples and reduce
    the total number of boxes needed.

  #Approach
  
    First, calculate the total number of apples.
    Sort the capacity array in descending order.
    Start picking boxes one by one from the largest capacity.
    Subtract each box's capacity from the remaining apples.
    Stop once all apples are stored.
    Return the number of boxes used.

  #Complexity
  
    Time Complexity: O(n log n)
    (Sorting the capacity array)

    Space Complexity: O(1)
*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());

        int sum = 0;
        for (int x : apple) {
            sum += x;
        }

        int ans = 0;
        for (int c : capacity) {
            if (sum <= 0) break;
            sum -= c;
            ans++;
        }
        return ans;
    }
};
