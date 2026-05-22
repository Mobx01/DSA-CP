/*Leetcode ps- 3016. Minimum Number of Pushes to Type Word II
You are given a string word containing lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
Return the minimum number of pushes needed to type word after remapping the keys.
Note that 1, *, #, and 0 do not map to any letters.*/


/*
    APPROACH: Greedy Assignment 

    Imagine a classic old-school telephone keypad. We have 8 keys available 
    to map letters to (keys 2 through 9). Each key can hold multiple letters.
    The first letter on a key takes 1 push, the second takes 2 pushes, and so on.

    To get the *minimum* total pushes, we should map the letters we use the 
    MOST often to the first positions (1 push). The letters we use less often 
    can be pushed to the second or third positions (2 or 3 pushes).
  
    1. Count Frequencies: 
       First, we need to know exactly how many times each letter appears in the 
       word. We use a Hash Map (unordered_map) for this. 
       Example: "apple" -> a:1, p:2, l:1, e:1

    2. Handle Short Words (Shortcut): 
       If the word has 8 or fewer characters in total, we can just put each 
       character on its own key as the first letter. So, the total pushes 
       will just be the length of the word. We can return early!

    3. Sort by Frequency (The "Greedy" step): 
       Since maps can't be sorted directly, we move our letter-counts into a list 
       (vector of pairs) and sort them in DESCENDING order. 
       Now, our most heavily used letters are at the very front of the list.

    4. Calculate Pushes:
       We loop through our sorted list of letters.
       - The first 8 letters (index 0 to 7) get the 1st spot on the 8 keys. 
         Push Cost = 1.
       - The next 8 letters (index 8 to 15) get the 2nd spot on the 8 keys. 
         Push Cost = 2.
       - The next 8 letters (index 16 to 23) get the 3rd spot on the 8 keys. 
         Push Cost = 3.
       
       We can figure this out mathematically using: pushCost = (index / 8) + 1.
       Finally, we multiply the frequency of the letter by its pushCost, add it 
       to our total, and return the result!
*/


class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char w : word) freq[w]++;
        
        int n = word.length();
        if (n <= 8) return n;

        // Store and sort by frequency in descending order
        vector<pair<char, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        int totalPushes = 0;
        
        // Loop through the sorted frequencies
        for (int i = 0; i < vec.size(); i++) {
            // The first 8 most frequent chars cost 1 push (i=0 to 7)
            // The next 8 cost 2 pushes (i=8 to 15), and so on.
            int pushCost = (i / 8) + 1;
            totalPushes += vec[i].second * pushCost;
        }

        return totalPushes;
    }
};
