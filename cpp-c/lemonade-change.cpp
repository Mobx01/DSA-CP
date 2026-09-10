/*Leetcode ps-860. Lemonade Change
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.*/



/* Approach - Greedy Bill Preservation & Scalar State Tracking (Time: O(N), Space: O(1))
 * Basically, we completely annihilate complex cash-flow simulations by aggressively applying the Greedy Bill Preservation Law, mathematically prioritizing the retention of versatile $5 bills to maximize future transaction survival!
 * * Observation: 
 * - The absolute core of this architecture is the Optimal Change Priority! When a customer hands over a $20 bill, you must return $15 in change. You have two choices: give one $10 bill and one $5 bill, or give three $5 bills. A masterclass in greedy strategy dictates that you *must always prefer the $10 + $5 combination* if available. Why? Because $5 bills are the universal currency needed to give change for $10 bills, whereas $10 bills can only be used for $20 change. Your code brilliantly enforces this exact priority order (`if (change[1] >= 1 && change[0] >= 1) ... else if (change[0] >= 3)`), ensuring absolute algorithmic correctness!
 * - (The Redundant $20 Bill Tracking Waste): Your logic allocates `vector<int> change(3, 0);` to track $5, $10, and $20 bills. But look closely at the problem physics: *can you ever use a $20 bill to give change?* Absolutely not! Transactions only involve receiving $5, $10, or $20 bills and giving $5 or $15 in change. Tracking the count of $20 bills (`change[2]`) is completely useless dead weight that clutters your memory footprint!
 * - (The Confusing `totalchange` Heuristic Trap): You maintain a `totalchange` variable to check `if (totalchange >= 15)`. While it acts as a quick early-exit filter, it conflates total monetary value with actual bill availability, introducing redundant arithmetic additions (`totalchange += 5`, `totalchange += 15`) that can desynchronize or obscure clean state validation. Direct register checks on bill counts are cleaner and faster.
 * - (Optimization Alert / Scalar Register Nuke): You can completely vaporize the vector allocation! Replace `vector<int> change(3, 0)` with two lightning-fast scalar registers: `int c5 = 0, c10 = 0;`. This strips away vector overhead, keeping your state entirely inside CPU registers for blistering single-cycle updates.
 * * How it runs:
 * First, we safely intercept the bills array and initialize our scalar `c5` and `c10` registers.
 * We ignite a high-speed linear traversal engine, inspecting each incoming bill.
 * If the bill is $5, we increment our universal `c5` register.
 * If the bill is $10, we check for an available $5 bill to return as change; if present, we decrement `c5` and increment `c10`; otherwise, we instantly return `false`.
 * If the bill is $20, we execute our greedy priority check: we check for a $10 + $5 pairing first to preserve our $5 stash, falling back to three $5 bills if necessary, or failing if neither configuration is possible.
 * Finally, if the linear sweep completes without a single cash-flow failure, we triumphantly return `true`, validating the register at raw silicon speed!
 */



class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0); //0->5,1->10,2->20
        int totalchange = 0,n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                change[0]++;
                totalchange += bills[i];
            }else if(bills[i] == 10){
                if(change[0] > 0){
                    change[0]--;
                    change[1]++;
                    totalchange += 5;
                }else return false;
            }else{// 20
                if(totalchange >= 15){
                    //try giving 10 + 5 change
                    if(change[1] >= 1 && change[0] >= 1){
                        totalchange += 15;
                        change[2]++;
                        change[1]--;
                        change[0]--;
                    }else if(change[0] >= 3){
                        totalchange += 15;
                        change[0] -= 3;
                        change[2]++;
                    }else{
                        return false;
                    }

                }else return false;
            }
        }
        return true;
    }
};
