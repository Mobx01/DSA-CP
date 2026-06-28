#include<iostream>
#include<vector>
using namespace std;

int solve(){
    int n,x;
    cin >> n >> x;

    vector<int> gas;//store all gas station points
    gas.push_back(0); //at 0 full fuel will be there so assume it to be a gas station

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