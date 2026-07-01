/*Leetcode ps - 493. Reverse Pairs
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].*/




/* Approach - Modified Merge Sort (space complexity O(N))
 * Basically, we use the divide-and-conquer strategy of Merge Sort to count valid pairs efficiently. By ensuring the left and right halves are already sorted before counting, we can use a fast two-pointer technique to count the reverse pairs in linear time during each merge step, completely avoiding a slow O(N^2) brute-force check!
 * We keep a few main variables/structures to track this:
 * - 'temp' is a temporary array used during the standard merge step to properly combine and sort the halves.
 * - 'cnt' keeps a running tally of all the valid reverse pairs we discover at every level of our recursion.
 * - 'i' and 'right' act as our two pointers in the 'countPairs' function to scan and compare the sorted halves.
 *
 * How it runs:
 * First, our 'mergeSort' function recursively divides the array into smaller halves until we reach single elements, exactly like standard Merge Sort.
 * Then, as the recursive calls resolve, right before we actually merge two sorted halves back together, we call our special 'countPairs' function.
 * Inside 'countPairs', we loop our 'i' pointer through the left half. Because both halves are currently sorted in ascending order, we dynamically slide our 'right' pointer forward in the right half as long as the strict condition (arr[i] > 2 * arr[right]) is met. Once the condition breaks, we instantly know exactly how many valid elements the 'right' pointer passed, and we mathematically add that chunk (right - (mid + 1)) to our 'cnt'.
 * Finally, after the pairs are safely tallied, we run the standard 'merge' function to perfectly sort the two halves together into one. This guarantees that when this combined chunk is compared to an even larger half higher up in the recursion tree, the sorting property remains perfectly intact for the two-pointer trick to work again!
 */



class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // start index of left half of arr
        int right = mid + 1;   // start index of right half of arr
    
        //storing elements in the temporary array in a sorted manner
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
    
        // if elements on the left half are still left 
    
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    
        //  if elements on the right half are still left 
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr 
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += countPairs(arr, low, mid, high); //Modification
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
