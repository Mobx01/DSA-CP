/*Leetcode ps- 28. Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/


/*
APPROACH:  (Sliding Window)

1. GET THE LENGTHS & HANDLE EDGE CASES:
   - `int hay=haystack.length(), need=needle.length();`
   - We store the lengths to make our loop logic cleaner.
   - `if(hay < need) return -1;`
   - If the word we are searching for (needle) is longer than the text 
     (haystack), it can't possibly be inside it. Return -1 to save time.

2. PREPARE THE SUBSTRING VARIABLE:
   - `string subs;`
   - You declared the string outside the loop. This is a smart little 
     memory optimization! Instead of creating and destroying a brand new 
     string variable on every single loop iteration, you create it once 
     up here and just overwrite its contents inside the loop.

3. THE "SLIDING WINDOW" LOOP:
   - `for(int i = 0; i < hay - need + 1; i++)`
   - We slide our window through the haystack. 
   - We stop at `hay - need + 1` because there's no point checking the 
     very end of the haystack if there aren't enough letters left to 
     even fit the needle.

4. EXTRACT AND COMPARE:
   - `subs = haystack.substr(i, need);`
   - We carve out a chunk of text starting at index `i` that is exactly 
     the length of our needle.
   - `if(subs == needle) return i;`
   - If this chunk perfectly matches the needle, we found it! We 
     immediately return `i` (the starting index).

5. NO MATCH FOUND:
   - `return -1;`
   - If the loop finishes completely without returning, the needle 
     isn't in the haystack at all. */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay=haystack.length(),need=needle.length();
        if(hay<need) return -1;
        string subs ;
        for(int i = 0 ;i<hay-need+1;i++){
            subs = haystack.substr(i,need);
            if(subs == needle)return i;
        }
        return -1;

    }
};
