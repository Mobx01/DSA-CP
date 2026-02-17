/*Leetcode PS- 401. Binary Watch
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the rightGiven an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.
For example, "01:00" is not valid. It should be "1:00".
The minute must consist of two digits and may contain a leading zero.
For example, "10:2" is not valid. It should be "10:02".
*/
/*what i learned from this question ?
__builtin_popcount funtion 
*/
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int H = 0 ; H<=11;H++){
            for(int M= 0 ; M<=59 ; M++){
                if(__builtin_popcount(H) + __builtin_popcount(M) == turnedOn){
                    string h = to_string(H);
                    string m = (M<10? "0" :"") + to_string(M);
                    res.push_back(h + ":" +  m);
                }
            }
        }
        return res;
    }
};
