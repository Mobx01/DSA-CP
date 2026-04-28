/*Leetcode ps-2033. Minimum Operations to Make a Uni-Value Grid
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.*/

/*
APPROACH:
---------
Intuition:
To minimize the number of operations (adding/subtracting x) to make all elements 
equal, we should convert all elements to the 'median' of the grid. It is a known 
mathematical property that the sum of absolute differences is minimized when 
we choose the median as our target value.

Steps:
1. Flatten the 2D grid into a 1D array (`arr`). This makes it easier to sort and 
   find the median.
2. Sort the 1D array.
3. Find the median element, which will be located at index `(n * m) / 2`.
4. Iterate through every element in the array:
   a. Calculate the absolute difference between the current element and the median.
   b. If this difference is not perfectly divisible by `x`, it means we can never 
      reach the target value by adding/subtracting `x`. Return -1.
   c. If it is divisible, the number of operations required for this specific 
      element is `difference / x`. Add this to our total operations counter (`minc`).
5. Return the total minimum operations (`minc`).

Complexity:
- Time Complexity: O(K log K) where K = n * m. The dominant operation is sorting 
  the 1D array. Flattening and calculating operations both take O(K) time.
- Space Complexity: O(K) where K = n * m, to store the flattened 1D array.
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr ;
        int minc=0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(),arr.end());
        int mid = n*m/2;
        
        for(int i =0;i< n*m;i++){
            int dif = abs(arr[mid] -arr[i]);
            if(dif%x == 0){
                 minc += dif/x;
            }else{
                return -1;
            }
        }
        return minc;
    }
};
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr ;
        int minc=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(),arr.end());
        int mid = n*m/2;
        for(int i =0;i< n*m;i++){
            int dif = abs(arr[mid] -arr[i]);
            if(dif%x == 0){
                 minc += dif/x;
            }else{
                return -1;
            }
        }
        return minc;

    }
};
