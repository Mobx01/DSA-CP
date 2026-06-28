/*Leetcode ps - 1901A. Line Trip
There is a road, which can be represented as a number line. You are located in the point 0 of the number line, and you want to travel from the point 0to the point x, and back to the point 0.
You travel by car, which spends 1 liter of gasoline per 1unit of distance travelled. When you start at the point 0, your car is fully fueled (its gas tank contains the maximum possible amount of fuel).
There are n gas stations, located in points a1,a2,…,an. When you arrive at a gas station, you fully refuel your car. Note that you can refuel only at gas stations, and there are no gas stations in points 0and x.

You have to calculate the minimum possible volume of the gas tank in your car (in liters) that will allow you to travel from the point 0to the point x and back to the point 0.
Input
The first line contains one integer t(1≤t≤1000) — the number of test cases.
Each test case consists of two lines:
the first line contains two integers nand x(1≤n≤50; 2≤x≤100);
the second line contains n integers a1,a2,…,an (0<a1<a2<⋯<an<x).
Output
For each test case, print one integer — the minimum possible volume of the gas tank in your car that will allow you to travel from the point 0 to the point x and back.*/

/* Approach - Greedy Observation
 * Basically, the entire solution boils down to a core observation about the gaps between refueling points on a round trip.
 * Observation: 
 * - For all the regular gas stations, you just need enough fuel to drive straight from one station to the next.
 * - However, for the very last stretch, you must drive from the final gas station to the destination 'x', turn around, and drive ALL the way back to that exact same final gas station without any extra refueling in between. Therefore, the required fuel for this specific segment is strictly double the distance: 2 * (x - last_station).
 * - The minimum fuel tank capacity we need overall is simply the absolute largest gap we are forced to cross at any point during the journey.
 *
 * How it runs:
 * First, we push 0 into our gas station list to represent our starting point, assuming we start with a full tank.
 * Then, we initialize our minimum required volume ('minvol') using our observation for that tricky final stretch: 2 * (x - gas[n]).
 * Finally, we loop through all our recorded gas stations to check the normal one-way distances between adjacent stations. We greedily update 'minvol' if the distance between the current station and the next station (gas[i+1] - gas[i]) is larger than our running maximum.
 */



#include<iostream>
#include<vector>
using namespace std;

int solve(){
    int n,x;
    cin >> n >> x;

    vector<int> gas;//store all gas station points
    gas.push_back(0); //at 0 full fuel will be there so assume it to be a gas staation

    for(int i =0 ;i <n;i++){
        int a;
        cin >> a;
        gas.push_back(a);
    }

    //so mainimum volumne size will be the maximum distance between gas stations.
    // for last gas sation we have to travel 2*(distance between last gas st to final point)
    
    int minvol = 2*(x - gas[n]);
    //use greedy to update the minvol
    for(int i=0;i<n;i++){
        minvol = max(minvol , gas[i+1] - gas[i]);
    }

    return minvol;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}
