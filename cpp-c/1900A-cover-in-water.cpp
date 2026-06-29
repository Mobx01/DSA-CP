#include<iostream>
#include<vector>

using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<char> nums(n);
    for(int i =0;i<n;i++){
        cin >> nums[i];
    }

    // if there are 3 consecutive blanks we can fill 2 of the side ones to get unlimited water in middle one 
    // thats way we can fill all using only 2. else we need to fill all blanks using extra water

    int consec3 =0,count =0;
    for(int i =0;i<n;i++){
        if(nums[i] == '.' && nums[i+1] == '.' && nums[i+2] == '.'){
            consec3 = 1;
            break;
        }
        if(nums[i] == '.') count++;
    }

    return (consec3 == 1) ? 2 : count; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
       cout << solve() << endl;
    }
    return 0;
}