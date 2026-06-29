#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int min_val = *min_element(nums.begin(), nums.end());
    
    if(min_val == nums[0]) {
        cout << "YES\n"; 
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    // Fast I/O 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}