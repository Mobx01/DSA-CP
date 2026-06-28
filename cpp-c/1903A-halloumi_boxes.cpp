#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin >> nums[i];
    }

    //observation-
    // if array is sorted then answer will be yes.
    // if unsorted then if k = 1 -> we can never sort it as we would not be able to change position of any element
    // for k >1 we can user k=2 case . and using k=2 we can send any digit to its desiered psotion in  some amount of operation 
    // so for k >1 we can alwaysa sort it so yes.

    for(int i =0 ; i<n-1;i++){
        if(nums[i]>nums[i+1]){//not sorted in asending order
            if(k==1){
                cout << "NO"<<endl; //can't sort
                return;
            }
            else {
                cout << "YES" <<endl;//for k>1 we can always sort
                return ;
            }
        }

    }
    //else already sorted
    cout << "YES" << endl;
    return;

}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}