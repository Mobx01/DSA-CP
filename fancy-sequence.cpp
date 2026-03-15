/*Leetcode ps- 1622. Fancy Sequence
Write an API that generates fancy sequences using the append, addAll, and multAll operations.
Implement the Fancy class:
Fancy() Initializes the object with an empty sequence.
void append(val) Appends an integer val to the end of the sequence.
void addAll(inc) Increments all existing values in the sequence by an integer inc.
void multAll(m) Multiplies all existing values in the sequence by an integer m.
int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1*/

/*
Approach:
Instead of updating the whole array for addAll() and multAll(), we keep two
global values: mul and add. The real value of any element is:

value = stored * mul + add

When appending a new value, we store its normalized form by reversing the
current transformation using Fermat's Little Theorem to compute modular inverse.

Time Complexity:
append -> O(log M)
addAll, multAll, getIndex -> O(1)
*/

class Fancy {
public:
    vector<long long> fancy;
    long long M = 1e9 + 7;
    long long mul = 1 , add =0;
// binary exponentiation for fermat little theorem
    long long power(long long a , long long b){
        long long res = 1;
        a = a % M;

        while(b > 0){
            if(b & 1){
                res = (res * a) % M;
            }
            a = (a * a) % M;
            b = b >> 1;
        }

        return res;
    }

    Fancy() {}
    //(a-b)%M = ((x-b)%M+M)
// fermats little theorem ; for(a/b)%M = a*b^(M-2)%M for pow use binary exponentiation
    void append(int val) {
        long long x = (((val - add) % M + M)*power(mul,M-2)) % M;
        fancy.push_back(x);
    }
    
    void addAll(int inc) {
        // for(long long &i : fancy) // o(n)
        //     i = (i + inc) % M;
        add = (add + inc) % M; // o(1)
    }
    
    void multAll(int m) {
        // for(long long &i : fancy) //o(n)
        //     i = (i * m) % M;
            mul = (mul*m) % M;  //o(1)
            add = (add*m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= fancy.size()) return -1;
        return (mul*fancy[idx] + add) % M;
    }
};
/** * Your Fancy object will be instantiated and called as such: 
       *Fancy* obj = new Fancy(); 
       * obj->append(val); 
       * obj->addAll(inc); 
       * obj->multAll(m); 
       * int param_4 = obj->getIndex(idx); */
