/*Leetcode ps- 3121. Count the Number of Special Characters II
You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
Return the number of special letters in word.*/


/* How this works:
1. We want to make sure EVERY lowercase letter appears BEFORE the first uppercase letter.
2. First pass: We go through the word and save the LAST index where we saw each lowercase letter. 
   (If we see 'a' at index 2, and again at index 5, we only remember 5).
3. Second pass: We go through the word again, looking only at uppercase letters.
4. When we find a capital letter (like 'A'), we check our map to see if we found an 'a' earlier.
5. If 'a' is in the map, we check the rule: is the index of 'A' greater than the last index of 'a'?
   If yes, we found a match and increase our count!
6. The trick: We immediately delete 'a' from the map right after checking it, regardless of whether it passed or failed. 
   Why? 
   - It stops us from double-counting if we see another 'A' later.
   - If the first 'A' failed (because an 'a' came after it), deleting 'a' makes sure any future 'A's are correctly ignored. The first 'A' locks in the final decision.
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> smallmap; //store the character and its last index
        
        // Store small characters and their last appearing index
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(c >= 'a' && c <= 'z'){
                    smallmap[c] = i;//ensures last index is stored(where c appearead)
            }
        }
        
        int count = 0;
        
        // Check capital letters 
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(c >= 'A' && c <= 'Z'){ 
                char smallChar = c + 32; 
                if(smallmap.find(smallChar) != smallmap.end()){ // Check if its corresponding small letter is present in the map
                    if(i > smallmap[smallChar]){// Check if the capital letter's index is bigger than the small letter's index
                        count++;
                    }
                        smallmap.erase(smallChar);// Remove the small letter from the map to avoid duplicate countinm
                }
            }
        }
        return count;
    }
};
