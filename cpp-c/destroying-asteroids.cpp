/*Leetcode ps- 2126. Destroying Asteroids
You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.
You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.
Return true if all asteroids can be destroyed. Otherwise, return false.*/

/*
     * APPROACH: Greedy Strategy
     * * 1. Sort the asteroids: To maximize our chances of survival, we should always 
     * try to destroy the smallest asteroids first. This helps the planet safely 
     * build up its mass to tackle the larger ones later.
     * 2. Prevent overflow: We use `long long` for `curmass` because adding 
     * multiple large integers together can easily exceed the maximum limit of 
     * a standard 32-bit `int`.
     * 3. Simulate collisions: Loop through the sorted asteroids. 
     * - If our mass >= asteroid mass, we destroy it and add its mass to ours.
     * - If an asteroid is larger than our current mass, we are destroyed (return false).
     * 4. If we successfully check all asteroids without failing, return true.
     */

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long curmass = mass;
        for(int i : asteroids){
            if(curmass >= i){
                curmass += i;
            }else{
                return false;
                }
        }
        return true;
    }
};
