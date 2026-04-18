/*Leetcode ps:- 1888. Minimum Number of Flips to Make the Binary String Alternating
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.*/

/*Brute force approach - 
  sliding window + comparing for all possible type1 flips
  possible alternating strings are s1 = 101010.. and s2= 010101..
  concatinating s with s (s= s+s) now each substring is a possible string by applying type1 operation.
  using sliding window to compare non equal elements between s,s1 and s,s2 and storre minimum flips required in result.
 //NOT OPTIMISED.
*/
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s= (s+s);
        //possible alternating strings are
        string s1;// s1 = 101010..
        string s2;//s2 = 010101...
    for(int i= 0; i< 2*n;i++){
        s1 += (i%2 ? '0':'1');
        s2 += (i%2 ? '1' : '0');
    }

    int res= INT_MAX;
    int flip1 = 0;
    int flip2 = 0;
    int i= 0 , j =0;
    //sliding window
    while(j<2*n){
        if(s[j] != s1[j]) flip1++;
        if(s[j] != s2[j]) flip2++;

        if(j-i+1 > n){ //shifting lower bound of window
            if(s[i] != s1[i]) flip1--;
            if(s[i] != s2[i]) flip2-- ;
            i++;
        }
        if(j-i+1 == n){
            res = min({res , flip1 , flip2});       
        }
        j++;
    }
    return res;

    }

};


//OPTIMISED APPROACH
/*for j and i in sliding window we can use s[j%n] to form a circular string .
this way we can skip the modifing of input (concatinaition of s with s). 
to remove creation of s1 and s2 - s1-> odd index(0) and even index(1) ,s2-> odd index(1) and even index(0)
improves space complexity O(1)*/

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

    int res= INT_MAX;
    int flip1 = 0;
    int flip2 = 0;
    int i= 0 , j =0;
    //sliding window
    while(j<2*n){
      char exps1 = (j%2) ? '1' : '0';
      char exps2 = (j%2) ? '0' : '1';
        if(s[j%n] != exps1) flip1++;
        if(s[j%n] != exps2) flip2++;

        if(j-i+1 > n){ //shifting lower bound of window
           char exps1 = (i%2) ? '1' : '0';
           char exps2 = (i%2) ? '0' : '1';
            if(s[i%n] != exps1) flip1--;
            if(s[i%n] != exps2) flip2-- ;
            i++;
        }
        if(j-i+1 == n){
            res = min({res , flip1 , flip2});       
        }
        j++;
    }
    return res;

    }

}
