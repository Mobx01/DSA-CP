/*Leetcode ps - 2657. Find the Prefix Common Array of Two Arrays
You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.*/

/*
    APPROACH : (not optimal).
    1. Setup: 
       - We create a result array `c` of the same size as A and B, filled with zeros. 
         This will hold our final answers.
       - We create two hash maps (dictionaries), `freq1` and `freq2`, to keep track of 
         how many times we have seen each number in array A and array B so far.
    2. Step-by-Step Traversal:
       - We loop through both arrays at the same time, using index `i`. 
       - At each step, we look at the current number in A and increase its count in `freq1`.
       - We do the same for the current number in B, increasing its count in `freq2`.
    3. Counting the Common Elements:
       - Still inside our current step, we now need to figure out how many numbers are 
         common in the prefixes we've seen so far.
       - To do this, we iterate through every single number currently recorded in `freq1`.
       - For each number, we check: "Is the count of this number in A (`x.second`) exactly 
         equal to the count of this number in B (`freq2[x.first]`)?"
       - If they match, it means this number has appeared in both prefixes! We add 1 to 
         our answer for this step (`c[i]++`).
    4. Return:
       - Once the outer loop finishes checking all elements, we return the array `c`, 
         which now contains the prefix common count for every index.
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> c(n,0);
        unordered_map<int,int> freq1 , freq2;
        for(int i = 0 ;i < n;i++){
            freq1[A[i]]++;
            freq2[B[i]]++;
            for(auto &x : freq1){
                if(x.second == freq2[x.first])c[i]++;
            }
        }
        return c;
    }
};



/*
    APPROACH : (optimal)
    1. The Core Idea (Permutation Property): 
       - Since both arrays A and B are permutations of numbers from 1 to n, 
         every number will appear exactly once in A and exactly once in B.
       - This means a number can appear a maximum of 2 times in total. 
       - If we keep a running count of how many times we've seen each number, 
         the moment a number's count hits 2, it means it has now appeared in 
         both array A and array B.
    2. Setup:
       - We create a `freq` array of size n + 1 (since the numbers go from 1 to n) 
         to tally how many times we see each number.
       - We keep a running counter, `com`, to track how many numbers have reached 
         a frequency of 2 so far.
       - We create an `ans` array to store our final results.
    3. Step-by-Step Traversal:
       - We loop through both arrays at the same time using index `i`.
       - Processing A[i]: We mark that we've seen the current number from A by 
         increasing its tally in `freq`. If its tally hits 2, we just found a 
         common element, so we increase our `com` counter.
       - Processing B[i]: We do the exact same thing for the current number from B. 
         If its tally hits 2, it's a common element, so we increase `com`.
         (Note: If A[i] and B[i] are the same number, the first check makes its 
         tally 1, and the second check makes it 2, safely counting it once!).
    4. Storing the Result:
       - At the end of each step, the `com` counter holds the total number of 
         common elements seen in the prefixes so far. We save this in `ans[i]`.
    5. Return:
       - Once the loop is done, we return the `ans` array.
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n+1,0);
        // given arrays are permutation of lenght n means each number will appear ones in each array so if frequency of any number become 2 means it has appear in both of the array  so it will counted as common element.
        int com = 0 ;
        vector<int> ans(n);
        for(int i = 0 ; i < n;i++){
            freq[A[i]]++;
            if(freq[A[i]] == 2) com++;
            freq[B[i]]++;
            if(freq[B[i]] == 2) com++;
            ans[i]= com;
        }
        return ans;     
    }
};
