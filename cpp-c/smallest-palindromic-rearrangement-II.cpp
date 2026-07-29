/*Leetcode ps-3518. Smallest Palindromic Rearrangement II
You are given a palindromic string s and an integer k.
Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.*/


/* Approach - Combinatorics & Lexicographical Tree Pruning (Time: O(N), Space: O(N))
 * Basically, we mathematically build the first half of the palindrome character by character, calculating the exact number of valid permutations for each choice to brilliantly skip over millions of possibilities and land exactly on the k-th smallest one!
 * * Observation: 
 * - Instead of blindly generating every single possible palindrome sequence to find the k-th one, we can use combinatorics (`nCr`) to mathematically predict exactly how many valid palindromes start with 'a', 'b', etc.
 * - If the total number of ways to finish the string using our current character is strictly greater than or equal to our target `k`, we know with absolute certainty that our answer lies deep inside this branch, so we lock in this character!
 * - If the ways are less than `k`, we simply subtract those ways from `k` and confidently move to the next alphabetical character, completely bypassing the need to generate those failed branches!
 * - Calculating permutations with duplicates can easily cause catastrophic integer overflow! The custom `nCr` function beautifully solves this by aggressively capping the calculation the exact millisecond it reaches `k`.
 * * How it runs:
 * First, we safely extract the frequencies of all characters in the string (isolating the middle character if the length is odd) and halve them to figure out exactly what character pool we have available to build our first half.
 * Then, we trigger our outer loop to physically fill exactly `n/2` positions. For every single position, we try placing characters from 'a' to 'z' in strict alphabetical order.
 * Next, for each valid character we test, we calculate the total number of permutations (`ways`) we can mathematically form with the remaining available pool of characters.
 * If `ways >= k`, we have found the absolutely correct character for this position! We push it directly into our `halfResult`, lock it in, and instantly break to move to the next position. If not, we cleanly subtract `ways` from `k`, put the character back into our pool (`count[j] += 1`), and test the next one.
 * Finally, once the first half is flawlessly constructed, we beautifully mirror it using `reverse()` (sandwiching the original `mid` character if necessary) and confidently return our exact k-th smallest palindrome!
 */

class Solution {
public:

    long long nCr(int n, int r, int k) {
        //nCr == nC(n-r)
        //5C3 == 5C2
        //5C2 == 5C(5-2) = 5C3
        r = min(r, n-r); //nCr == nC(n-r)

        long long result = 1;

        for(int i = 1; i <= r; i++) {//O(log2(k))
            result = result * (n - r + i)/i; //result is becoming twice

            if(result >= k) 
                return k;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if(n%2 == 1) { //odd length
            mid = s[n/2];
        }

        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            if(n%2 == 1 && i == n/2) continue; //mid character reserverd for middle one
            count[s[i] - 'a']++;
        }

        //half frequency will be used to build halfResult
        for(int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        string halfResult = "";
        int half = n/2;

        for(int i = 0; i < half; i++) { //O(n/2)
            //I am trying to fill ith position
            //What if I could never fill a character in ith position
            bool placedCharacter = false; //in ith position
            for(int j = 0; j < 26; j++) { //which character to put
                if(count[j] > 0) {
                    count[j] -= 1;

                    //count number of ways
                    long long ways = 1;
                    int letters = 0;
                    for(int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for(int c = 0; c < 26; c++) {
                        if(count[c] > 0) {
                            ways *= nCr(letters, count[c], k); //log2(k)
                            letters -= count[c];
                        }

                        if(ways >= k) {
                            break;
                        }
                    }

                    if(ways >= k) { //this block contains my kth one
                        halfResult.push_back(j + 'a'); //fixed this character at ith position
                        placedCharacter = true;
                        break;
                    }

                    k -= ways; //when k >= ways
                    count[j] += 1;
                }
            }

            if(placedCharacter == false)
                return "";
        }

        //halfResult + mid + (reverse of halfResult)
        string rev = halfResult;
        reverse(begin(rev), end(rev)); //O(n/2)

        if(mid != ' ') {
            halfResult.push_back(mid);
        }

        return halfResult + rev;
    }
};



