/*Leetcode ps- 2833. Furthest Point From Origin
You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.
In the ith move, you can choose one of the following directions:
move to the left if moves[i] = 'L' or moves[i] = '_'
move to the right if moves[i] = 'R' or moves[i] = '_'
Return the distance from the origin of the furthest point you can get to after n moves.*/

//approach - greedy(thats what i think :)
/*  -check frequency of 'L' and 'R'
    -if freq(L) > freq(R) use L move for each '_' 
     else use R move for each '_'.
    - start with dis =0(assume at 0 on x axis) iterate the moves and increase x value(dis++) for R move and decrese x value(dis--) for L move.  x-- -----------x=0------------x++

    why freq? - being greedy for maximum distance from origin if L is more in moves then converting '_' in L will push dis more away from origin whereas converting '_' in  R will decrease out the distance.
*/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lfreq = 0 ,rfreq = 0;
        for(char c : moves){
            if(c == '_')continue;
            else if(c =='L')lfreq++;
            else rfreq++;
        }
        int dis = 0;
        for(char c: moves){
            if(c == '_') dis = (lfreq>rfreq) ? dis-1 : dis+1;
            else if(c =='L')dis--;
            else dis++;
        }
        return abs(dis);
    }
};
