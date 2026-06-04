/*Leetcode ps- 3753. Total Waviness of Numbers in Range II
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].*/

/*
Approach:
1. The Range Trick:
   - To find the answer for the range [num1, num2], we calculate the total waviness 
     from 1 to num2, and subtract the total waviness from 1 to num1 - 1. 
     Formula: count(num2) - count(num1 - 1).

2. The State (What we memorize in our 'dp' table):
   - 'pos': Which digit position we are currently placing.
   - 'sum': The total waviness (peaks + valleys) we've accumulated so far.
   - 'prv2' & 'prv': The last two digits we placed. We need a window of 3 digits to 
     check for peaks/valleys. (Initialized to 10 as a placeholder).
   - 'small': A boolean flag. If true, the number we are building is strictly smaller 
     than our limit, so we can safely place any digit from 0-9. If false, we are 
     tightly bound by the original number's digits.
   - 'nz' (non-zero): A boolean flag tracking if we've bypassed leading zeros. Leading 
     zeros don't count as part of the number for waviness.

3. The Logic ('solve' function):
   - At each position, we loop through all valid digits we can place (0 up to 'lim').
   - If we have placed at least two previous digits (prv2 and prv aren't 10), we 
     check if the current digit 'i' forms a peak (prv2 < prv AND prv > i) or a 
     valley (prv2 > prv AND prv < i).
   - If it forms either, we increase our 'nsum' (new sum) for the next step.
   - We save the result of this exact scenario in a 6D array (`dp`) so if we encounter 
     the exact same state again, we instantly return the saved answer instead of 
     recalculating it. This makes the code extremely fast!
*/



class Solution {
public:
    vector<int> d;
    long long dp[30][30][11][11][2][2];
    long long solve(int pos, int sum, int prv2, int prv, bool small, bool nz){
        if(pos == d.size()) return sum;
        if(dp[pos][sum][prv2][prv][small][nz]!=-1){
            return dp[pos][sum][prv2][prv][small][nz];
        }
        int lim=(small?9:d[pos]);
        long long ans=0;
        for(int i=0;i<=lim;i++){
            bool nsmall = (small || i<d[pos]);
            bool nnz = nz || (i!=0);
            if(nnz){
                int nprv2 = prv;
                int nprv = i;
                int nsum = sum;
                if (prv2 != 10 && prv != 10) {
                    nsum += (prv2 < prv && prv > i);
                    nsum += (prv2 > prv && prv < i);
                }
                ans+=solve(pos+1, nsum, nprv2, nprv, nsmall, nnz);
            }
            else ans+=solve(pos+1, sum, prv2, prv, nsmall, nnz);
        }
        return dp[pos][sum][prv2][prv][small][nz]=ans;
    }
    long long count(long long x){
        if(x==0) return 0;
        d.clear();
        while(x){
            d.push_back(x%10);
            x/=10;
        }
        reverse(d.begin(),d.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,10,10,0,0);
    }
    long long totalWaviness(long long num1, long long num2){
        return count(num2)-count(num1-1);
    }
};
