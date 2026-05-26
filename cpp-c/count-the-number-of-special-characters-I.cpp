/*Leetcode ps- 3120. Count the Number of Special Characters I
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
Return the number of special letters in word.
 */


/* Approach:
1. We need to find letters that show up as both lowercase and uppercase.
2. First, we go through the word and grab every lowercase letter we see. 
   We throw them into a hash set (which is just a data structure that automatically ignores duplicates and lets us search really fast).
3. Then, we go through the word a second time, but now we only look at the uppercase letters.
4. For every uppercase letter, we check our set to see if we already found its lowercase twin. 
   (We do this by adding 32 to the ASCII value, because 'A' is 65 and 'a' is 97).
5. If the lowercase twin is sitting in the set, we found a special character! We increase our count.
6. The trick: We immediately delete that lowercase twin from the set. This stops us from double-counting if the exact same uppercase letter shows up again later in the word.
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> small; //using hashset to avoid duplicates
        for(char c : word){
            if(c >= 97 && c <= 122){// insert all unique small character
                small.insert(c);
            }
        }
        int count =0;
        for(char c : word){
            if(c >= 65 && c <= 90){ //for captial character
                if(small.find(c+32) != small.end()){//check if its small character is present 
                    count++;
                    small.erase(c+32);//remove the small charactre from hashset to avoid duplicate counting
                }
            }
        }
        return count;
    }
};
