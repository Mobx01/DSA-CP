/*Leetcode ps - 3838. Weighted Word Mapping
You are given an array of strings words, where each string represents a word containing lowercase English letters.
You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.
The weight of a word is defined as the sum of the weights of its characters.
For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').
Return a string formed by concatenating the mapped characters for all words in order.

*/

/*
### Approach: Calculating and Translating Word Scores
This solution processes a list of words and assigns a single, specific letter to represent each word. It does this by calculating a total "score" for each word using a custom point system, and then translating that score into a new letter using a reverse-alphabet formula.

**1. The Setup**
We start with an empty string called `res`. This will act as our final answer, collecting exactly one new letter for every word we process in the list.

**2. Scoring Each Word**
We loop through every word in our `words` list. For each word, we start a fresh `weight` counter at 0. 
Next, we look at every single character in that word. We use `c - 'a'` as a clever C++ trick to find the character's numerical position in the alphabet (where 'a' is 0, 'b' is 1, and so on). We use that position to look up its specific point value in our `weights` array and add it to our word's total score.

**3. The Wrap-Around (Modulo)**
Once we have the total score for the word, we do `weight %= 26`. This is the modulo operator. Because there are only 26 letters in the English alphabet, this acts as a boundary restrictor. It ensures our final score strictly falls between 0 and 25, automatically wrapping around no matter how massive the total weight got. 

**4. The Reverse Alphabet Translation**
Now for the math: `'a' + (26 - weight - 1)`. 
This formula maps our wrapped 0-25 score onto a perfectly reversed alphabet! 
* If our score is 0: `26 - 0 - 1 = 25`. Adding 25 to 'a' gives us **'z'**.
* If our score is 25: `26 - 25 - 1 = 0`. Adding 0 to 'a' gives us **'a'**.

We take this newly translated letter, slap it onto the end of our `res` string using `push_back()`, and move on to score the next word. Once the loop finishes, we return the fully built string!
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(string cur : words ){
            int weight = 0;
            for(char c : cur){
                weight += weights[c-'a'];
            }
            weight %= 26;
            res.push_back('a' + (26 - weight - 1));
        }
        return res;
    }
};
