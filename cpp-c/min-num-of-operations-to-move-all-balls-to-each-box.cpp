/*Leetcode ps- 1769. Minimum Number of Operations to Move All Balls to Each Box
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.*/



// not optimised 0(n^2)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans , idx;
        int n = boxes.size();
        for(int i = 0;i<n;i++){
            if(boxes[i] == '1') idx.push_back(i);
        }

        for(int i = 0 ; i < n ;i++){
            int sum =0;
            for(int j : idx){
                sum += abs(i-j);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


// optimised - 0(n) : prefix + postfix sum approach
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int cnt=0;
        cnt+=boxes[0]=='1'?1:0;
        vector<int>pres(n,0),posts(n,0),ans(n,0);
        for(int i=1;i<n;i++){
            pres[i]=pres[i-1]+cnt;
            cnt+=boxes[i] =='1' ? 1:0 ;
        }
        cnt=0;
        cnt+=boxes[n-1]=='1' ? 1:0 ;
        for(int i=n-2;i>=0;i--){
            posts[i]=posts[i+1]+cnt;
            cnt+=boxes[i]=='1' ? 1:0 ;
        }
        for(int i=0;i<n;i++){
            ans[i]=pres[i]+posts[i];
        }
        return ans;
    }
};
