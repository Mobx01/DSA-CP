/*leetcode ps - 3093. Longest Common Suffix Queries
You are given two arrays of strings wordsContainer and wordsQuery.
For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.
Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
*/

/*
    APPROACH: Suffix Trie (A Prefix Tree, but backwards!)

    1. The 'Smart' Trie Node:
       Usually, a Trie node just connects characters. Ours does a bit more. 
       At every single node, we store an 'idx'. This 'idx' answers the question: 
       "If a query stops matching exactly at this node, what is the best possible 
       container word to return?"
       (Notice we also added a destructor `~trieNode()`. This cleans up all our 
       'new' allocations so the LeetCode servers don't crash from memory leaks).

    2. Setting up the Root (The Fallback Answer):
       If a query doesn't match ANY suffix in our container, the rules say we 
       must return the shortest container word (and the earliest one if tied). 
       We handle this right at the start by finding that "overall best" word 
       and putting its index directly in the root node.

    3. Building the Tree:
       We loop through `wordsContainer` and insert each word from right to left.
       As we step through the characters and create nodes, we update the `idx` 
       at each node we touch. If the word we are currently inserting is shorter 
       than the one already recorded there, we overwrite it. 
       (Since our loop goes from i = 0 to m, if two words are the same length, 
       the earlier one naturally stays there, perfectly handling the tie-breaker).

    4. Answering Queries:
       For every query word, we walk down the Trie backwards. 
       - If the next character exists, we move down the tree.
       - If we hit a dead end (NULL), we simply stop! The 'idx' of the node we 
         are currently standing on already holds the correct, pre-calculated answer.
         
    5. Clean Up:
       We call `delete root;` at the end. Thanks to the destructor, this triggers 
       a chain reaction that safely deletes the whole tree.
*/

class Solution {
public:

    struct trieNode {
        int idx;
        trieNode* children[26];
        ~trieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    trieNode* getNode(int i) {
        trieNode* temp = new trieNode();
        temp->idx = i;

        for(int i = 0; i<26; i++) {
            temp->children[i] = NULL;
        }
        return temp;
    }

    void insertTrie(trieNode* pCrawl, int i, vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.size();

        for(int j = n-1; j >= 0; j--) {
            int ch_idx = word[j] - 'a';

            if(pCrawl->children[ch_idx] == NULL) {
                pCrawl->children[ch_idx] = getNode(i);
            }
            pCrawl = pCrawl->children[ch_idx];
            
            if(wordsContainer[pCrawl->idx].size() > n) {
                pCrawl->idx = i;
            }
        }
    }

    int search(trieNode* pCrawl, string &word) {
        int result_idx = pCrawl->idx;
        int n = word.size();

        for(int i = n-1; i >= 0; i--) {
            int ch_idx = word[i]-'a';
            pCrawl = pCrawl->children[ch_idx];
            if(pCrawl == NULL) {
                return result_idx;
            }
            result_idx = pCrawl->idx;
        }
        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> result(n);

        trieNode* root = getNode(0);

        for(int i = 0 ; i < m; i++) {
            if(wordsContainer[root->idx].size() > wordsContainer[i].size()) {
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }

        for(int i = 0; i < n; i++) {
            result[i] = search(root, wordsQuery[i]);
        }

        delete root;   // invokes destructor

        return result;
    }
};
