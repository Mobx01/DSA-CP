/*1356. Sort Integers by The Number of 1 Bits
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more 
integers have the same number of 1's you have to sort them in ascending order.
Return the array after sorting it.*/
/*Approach
 modify the sort function using lambda function.
  modification in sort function -calculate the number of 1 bit in a number .
           --if they are not equal then return the one with more 1.
               else return the greater one.
*/

class Solution {
public:
    int cal1(int n){
        int res =0;
        while(n>0){
            if(n & 1) res++ ;
            n >>= 1;
        }
        return res ;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end(), [&](int& a , int& b ){
            if(cal1(a) != cal1(b)) return cal1(a) < cal1(b);
            return a < b;
        });
        return arr;
    }
};
// what i learned new : defining a custom sorting logic in sort funtion by lambda.
