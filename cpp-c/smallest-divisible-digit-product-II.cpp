/*Leetcode ps-3348. Smallest Divisible Digit Product II
You are given a string num which represents a positive integer, and an integer t.
A number is called zero-free if none of its digits are 0.
Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

*/

/* Approach - Greedy Prefix Preservation / Prime Factorization (Time: O(N), Space: O(N))
 * Basically, we mathematically shred our target target 't' into single-digit prime factors, aggressively scan the original number to find the exact bottleneck where the product fails or hits a zero, and brilliantly backtrack to bump a single digit and perfectly reconstruct the absolute smallest valid suffix!
 * * Observation: 
 * - The digit product of any number strictly consists of individual digits 1 through 9. This mathematically guarantees that the ONLY possible prime factors a valid 't' can have are 2, 3, 5, and 7! If 't' contains ANY prime factor strictly greater than 7 (like 11 or 13), it is physically impossible to construct, and we violently reject it right out of the gate by returning "-1"!
 * - (The Absolute Product Killer): A '0' in the string instantly permanently flatlines the entire running product to exactly 0! The exact millisecond we hit a '0', any digits after it are completely meaningless. Therefore, we aggressively lock our backtrack starting point (`zeroind`) exactly at that first '0', completely ignoring the dead tail!
 * - To mathematically guarantee we form the *smallest* possible number, we must greedily preserve as much of the original prefix as humanly possible. When we backtrack to bump a digit, we must fill the remaining suffix slots (`freeslots`) using the absolute fewest digits possible to reach our target product. We brilliantly achieve this by greedily dividing out the largest possible digits first (9 down to 2), and flawlessly padding any leftover empty slots with 1s (since multiplying by 1 changes absolutely nothing)!
 * * How it runs:
 * First, we safely extract all 2, 3, 5, and 7 prime factors from a copy of `t`. If anything is left over, the mathematical structure is broken, and we instantly crash out.
 * Then, we trigger a high-speed forward sweep using `remainingfactor`, aggressively deploying C++'s `std::gcd` to continuously track exactly what remaining fractional chunk of 't' is still desperately needed after consuming each digit of the prefix.
 * Next, we violently reverse direction, sweeping backwards starting from our `zeroind`. At every single position, we aggressively try bumping the current digit up (from `num[i] + 1` to 9). We instantly calculate the new `furtherreq` and fiercely check if its minimum required length (`getMinLength`) can physically fit into our remaining `freeslots`.
 * Finally, the exact millisecond a valid digit fits, we flawlessly reconstruct the strictly optimal suffix using `func` (padding with 1s and reversing to ensure ascending order), cleanly stitch it to the prefix, and confidently return it! If the entire original length fails, we boldly expand the string by exactly one digit (`n + 1`) and effortlessly return the absolute minimum expanded number!
 */

class Solution {
public:
    int getMinLength(long long num) {
        int len = 0;
        for (int digit = 9; digit >= 2; digit--) {
            while (num % digit == 0) {
                len++;
                num /= digit;
            }
        }
        return len;
    }

    // Changed to long long to prevent overflow
    string func(long long num, int length) {
        string str;
        for (int digit = 9; digit >= 2; digit--) {
            while (num % digit == 0) {
                str.push_back(digit + '0');
                num /= digit;
            }
        }
        // Pad the remainder with 1s
        while (str.length() < length) {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();
        long long temp = t;
        
        for (int primefact : {2, 3, 5, 7}) {
            while (temp % primefact == 0) {
                temp /= primefact;
            }
        }

        // Cannot form the number if factors greater than 7 exist
        if (temp != 1) return "-1"; 

        vector<long long> remainingfactor(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if (digit == 0) break;
            remainingfactor[i+1] = remainingfactor[i] / std::gcd(remainingfactor[i], (long long)digit);
        }

        // Return early only if it's perfectly divisible AND contains zero '0's
        if (remainingfactor[n] == 1 && num.find('0') == string::npos) return num; 

        int zeropos = num.find('0');
        int zeroind = n - 1;
        if (zeropos != string::npos) {
            zeroind = zeropos; 
        }

        for (int i = zeroind; i >= 0; i--) {
            long long required = remainingfactor[i];
            int freeslots = n - 1 - i;

            
            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                long long furtherreq = required / std::gcd(required, (long long)digit);
                
                
                if (getMinLength(furtherreq) <= freeslots) {
                    string requirednum = func(furtherreq, freeslots);
                    return num.substr(0, i) + char(digit + '0') + requirednum;
                }
            }
        }

        // We need more digits to get a valid number
        return func(t, n + 1);
    }
};
