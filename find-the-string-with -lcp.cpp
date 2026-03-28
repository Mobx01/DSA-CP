/*leetcode ps - 2573. Find the String with LCP (given problem statement is too human )🥲
We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:
lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.
A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.*/

/* approach  - written with week english(this shitt is not understandble)

start with word having length n and all values $.
for(int i : 0 to n ){
    for(int j :0 to i){
        if(lcp[j][i] !=0) word[i]=word[j] break;
        
        if(word[i]= $){
            assign the smallest possible character among  a to z(use forbidden vector for that)
            break
        }
        if(word[i]=$){//still unassigned means cant form a word
        return "";
        }
    }
}
  return checklcp(word) == lcp ? word :"";//checks if word formed can have a valid lcp

  checklcp{
    fill last row- lcp[i][n-1] = 1 if word[i]=word[n-1] else 0
    fill last col - lcp[n-1][i]=1 if word[n-1]=wordp[i] else 0

    for rest {
        if(word[i]==word[j]) {
            lcp[i][j] = 1+lcp[i+1][j+1];
        }
        else {
            lcp[i][j]=0;
        }
    }
  }
*/
/*used ai to make this  shitt understandble by humans */
/*
APPROACH:

1. Setup: 
   - Make a string 'word' of size n, filled with a placeholder like '$'.
   - Keep track of the current letter to assign, starting at 'a'.

2. Build the string greedily:
   - Loop through each index 'i' from 0 to n-1.
   - If word[i] is already assigned a letter, just skip to the next.
   - If word[i] is empty ('$'):
       - If we've passed 'z', we ran out of allowed letters -> return "".
       - Assign our current letter to word[i].
       - Look ahead in the LCP matrix (j from i+1 to n-1). 
       - If lcp[i][j] > 0, it means word[j] MUST match word[i]. 
         So, assign that exact same letter to word[j] right now.
       - Move to the next letter in the alphabet (e.g., 'a' becomes 'b') 
         for the next time we find an empty spot.

3. Verify:
   - The greedy step above only groups matching characters. 
   - We must calculate the actual LCP matrix for the word we just built.
   - If our calculated LCP perfectly matches the given LCP matrix, return the word.
   - If it doesn't match (meaning the given matrix had impossible rules), return "".
*/

class Solution {
public:
    vector<vector<int>> checklcp(string word){
        int n = word.length();
        vector<vector<int>> ret(n,vector(n,0));
        for(int i = 0 ; i < n ;i++){
            if(word[i]==word[n-1]) ret[i][n-1] = 1;
        }

        for(int j = 0;j<n;j++){
            if(word[n-1]==word[j]) ret[n-1][j] = 1;
        }

        for(int i = n-2 ; i>=0 ;i--){
            for(int j = n-2; j>=0 ;j--){
                if(word[i]==word[j]) {
                    ret[i][j]=1+ret[i+1][j+1];
                }
            }
        }
        return ret;

    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n,'$');

        for(int i = 0 ; i < n;i++ ){
            
            for(int j =0 ; j<i;j++){
                if(lcp[j][i] != 0){
                    word[i]=word[j];
                    break;
                }
            }

            if(word[i]=='$'){
                vector<bool> forbidden(26,false); //assign all char a,b,c,..,z to false means they can be used;
                for(int j =0;j<i;j++){
                    if(lcp[j][i] == 0){ // if lcp is 0 then new word will be used so the char will be be forbidden
                        forbidden[word[j]-'a'] = true;
                    }
                }   

                for(int k = 0 ; k < 26;k++){
                    if(forbidden[k]== false){
                        word[i]= 'a'+k;//first not forbidden char is assigned
                        break;
                    }
                }     
            }

            if(word[i]== '$') return ""; // still no char could be assigned so no word is possible
            }
        return checklcp(word) == lcp ? word : "" ;
    }
};
