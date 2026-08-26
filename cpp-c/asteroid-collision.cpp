/*Leetcode ps -735. Asteroid Collision
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.*/




/* Approach - Stack-Based Simulation / Mass Annihilation (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the O(N^2) brute force collision tracking by aggressively deploying a Stack engine, violently simulating the physical destruction of the asteroid field in a single blistering O(N) linear sweep!
 * * Observation: 
 * - The absolute core of this physics engine is the collision trigger! A mathematical collision ONLY exists in one singular timeline: the stack's top is moving right (`> 0`) AND the incoming asteroid is moving left (`< 0`). Every other physical state (`-> ->`, `<- <-`, `<- ->`) peacefully diverges into the void without a scratch!
 * - (The Kinetic Shredder): Your `while` loop is an absolute masterstroke of simulated destruction! When a massive left-moving asteroid enters the timeline, it aggressively tears through the stack, violently popping every single smaller positive asteroid out of existence until it either hits a wall, mutually annihilates, or claims the stack!
 * - (Optimization Alert 1 / The Vector-as-Stack Nuke): Your logic is physically flawless, but you burn massive CPU cycles at the end extracting the `std::stack` into a new vector and aggressively calling `reverse()`! You can completely destroy this post-processing overhead by using `std::vector<int> ans` DIRECTLY as your stack! Just deploy `ans.push_back()` and `ans.pop_back()`! The exact millisecond the simulation ends, the vector is ALREADY in the flawless chronological order! Peak hardware supremacy!
 * - (Optimization Alert 2 / The Hardware Sign-Flip): Look incredibly closely at your `else` block. You repeatedly call `abs(cur)` to check masses. Because you mathematically ALREADY KNOW that `cur` is strictly negative inside that block, calling a function is a waste of bytecode! You can instantly bypass the function call overhead by simply writing `-cur`! It violently flips the sign bit at the raw hardware level in a pure O(1) cycle!
 * * How it runs:
 * First, we safely intercept the incoming asteroid field and ignite our stack engine.
 * We trigger a high-speed linear sweep across the universe. If the current asteroid is moving right (`cur > 0`), it is completely safe from immediate threats, so we aggressively slam it onto the stack!
 * If it's moving left (`cur < 0`), we instantly ignite the collision radar! We violently trigger the `while` loop, continuously shredding the top of the stack as long as the right-moving targets are mathematically weaker (`stk.top() < -cur`).
 * If it mathematically collides with a perfectly equal mass (`stk.top() == -cur`), mutual annihilation is achieved! We aggressively pop the stack and completely abandon the incoming asteroid!
 * If the incoming asteroid survives the entire gauntlet (the stack becomes empty, or the top asteroid is also moving left), it has officially survived, and we securely lock it into the timeline!
 * Finally, we confidently extract the surviving debris field, flawlessly completely the simulation!
 */



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        int i = 0, n = asteroids.size();

        while(i < n){
            int cur = asteroids[i];
            if(cur > 0){ // moving right
               stk.push(cur);
            } else { // moving left
               if(stk.empty() || stk.top() < 0){
                  stk.push(cur);
               } else {
                  if(stk.top() > abs(cur)){
                    // no action as current one will be destroyed
                  } else {
                    while(!stk.empty() && stk.top() > 0 && stk.top() < abs(cur)){
                        stk.pop();
                    }
                 
                    if(!stk.empty() && stk.top() == abs(cur)){
                        stk.pop(); // Both destroy each other
                    }
                    else if(stk.empty() || stk.top() < 0){
                        stk.push(cur);
                    }
                  }
               }
            }
            i++;
        }
        
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
