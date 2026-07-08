/*Leetcode ps-3756. Concatenate Non-Zero Digits and Multiply by Sum II
You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].
For each queries[i], extract the substring s[li..ri]. Then, perform the following:
Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.
Since the answers may be very large, return them modulo 109 + 7.*/


/* Approach - Prefix Sums & Modular Arithmetic (Time: O(N + Q), Space: O(N))
 * Basically, we efficiently process multiple substring queries by precomputing prefix arrays for digit sums, non-zero digit counts, and the running concatenated values, allowing us to answer any query in O(1) time.
 * * Observation: 
 * - Processing each query naively would take O(N) time per query, resulting in O(N * Q) overall, which is too slow. Prefix arrays let us answer range queries instantly.
 * - To extract the concatenated number for a specific substring [l, r], we can't just subtract the values. We have to take the total concatenated number up to 'r', and subtract the prefix up to 'l-1' ONLY AFTER shifting that prefix left by the exact number of non-zero digits present in the [l, r] window.
 * - Because the concatenated numbers grow astronomically large, we must heavily rely on modulo 10^9+7 arithmetic at every addition and multiplication step, including precomputing powers of 10!
 * * How it runs:
 * First, we initialize and populate four prefix arrays in O(N) time: 'pow10' to store modular powers of 10, 'nonZeroCount' to track the shifting lengths, 'digitSumUpTo' for the basic sum of digits, and 'numberUpTo' for the running concatenated value of non-zero digits.
 * Then, we iterate through each query [l, r]. Using our prefix arrays, we instantly calculate the number of non-zero digits in our target range ('subStrLen') and the total sum of the digits ('sum'). If 'subStrLen' is 0, we can immediately return 0 for that query.
 * Finally, we apply our mathematical extraction trick to isolate the concatenated substring value 'x': we multiply the prefix before 'l' by 10^subStrLen, subtract it from the prefix at 'r', and add MOD before taking the final modulo to perfectly handle negative numbers. We then multiply 'x' by 'sum', mod it one last time, and store the result!
 */


class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> nonZeroCount(n, 0);    // non-zero digits count in s[0..i]
        vector<ll> numberUpTo(n, 0);      // number formed from non-zero digits in s[0..i]
        vector<ll> digitSumUpTo(n, 0);    // digit sum of s[0..i]
        vector<ll> pow10(n + 1, 0);  // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;


        nonZeroCount[0]      = (s[0] != '0') ? 1 : 0;
        numberUpTo[0]   = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l  = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore   = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            ll x   = (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};
