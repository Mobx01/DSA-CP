/*Leetcode ps- 3014. Minimum Number of Pushes to Type Word I
You are given a string word containing distinct lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
Return the minimum number of pushes needed to type word after remapping the keys.
An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.*/


/*
    APPROACH: Greedy Assignment  
    1. The Keypad Limit: 
       We have exactly 8 keys to map our letters to. 

    2. Fill the "Cheap" Spots First: 
       To get the minimum pushes, we should fill the 1st position of all 8 keys 
       first. 
       - The first 8 letters we process (indices 0 to 7) will cost exactly 1 push.

    3. Move to the Next Positions: 
       Once the 1st positions are full, we are forced to put the next batch of 
       letters in the 2nd position of those keys.
       - The next 8 letters (indices 8 to 15) will cost 2 pushes.
       - The next 8 letters (indices 16 to 23) will cost 3 pushes, and so on.

    4. The Mathematical Formula:
       Instead of writing complex if-else statements, we can use simple division 
       to figure out the cost for the i-th letter:
       Push Cost = (i / 8) + 1.
       
       Example:
       - i = 3  -> (3 / 8) + 1 = 0 + 1 = 1 push
       - i = 10 -> (10 / 8) + 1 = 1 + 1 = 2 pushes
       
    5. Calculate Total:
       We simply loop through the length of the word, calculate the push cost 
       for each character using the formula, and add it to our total!
*/

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalPushes = 0;
        
        // Since every character is distinct, we just place them on the 8 keys 
        // one by one. The first 8 cost 1 push, the next 8 cost 2 pushes, etc.
        for (int i = 0; i < n; i++) {
            int pushCost = (i / 8) + 1;
            totalPushes += pushCost; 
        }
        
        return totalPushes;
    }
};
