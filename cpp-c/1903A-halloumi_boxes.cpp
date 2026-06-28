/*Codeforces ps- 1903A. Halloumi Boxes
Theofanis is busy after his last contest, as now, he has to deliver many halloumis all over the world. He stored them inside n
 boxes and each of which has some number ai
 written on it.
He wants to sort them in non-decreasing order based on their number, however, his machine works in a strange way. It can only reverse any subarray†
 of boxes with length at most k
Find if it's possible to sort the boxes using any number of reverses.

 Reversing a subarray means choosing two indices i
 and j
 (where 1≤i≤j≤n
) and changing the array a1,a2,…,an
 to a1,a2,…,ai−1,aj,aj−1,…,ai,aj+1,…,an−1,an
 The length of the subarray is then j−i+1
Input
The first line contains a single integer t
 (1≤t≤100
) — the number of test cases.
Each test case consists of two lines.
The first line of each test case contains two integers n
 and k
 (1≤k≤n≤100
) — the number of boxes and the length of the maximum reverse that Theofanis can make.
The second line contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the number written on each box.

Output
For each test case, print YES (case-insensitive), if the array can be sorted in non-decreasing order, or NO (case-insensitive) otherwise*/

/* Approach - Logic & Observation
 * Basically, the entire solution boils down to a core mathematical observation about how the 'k' operations work.
 * Observation: 
 * - If the array is already sorted, the answer is obviously YES. 
 * - If it's unsorted and k = 1, we can never change any element's relative position, meaning we can't sort it. The answer is NO. 
 * - However, if k > 1 (even just k = 2), we have enough flexibility to essentially swap adjacent elements one by one (exactly like Bubble Sort) to eventually move any element to its correct position. Therefore, for any k > 1, it's guaranteed we can sort it, so the answer is always YES.
 *
 * How it runs:
 * First, we loop through the array to check if there is any adjacent pair where the left element is strictly greater than the right element (meaning the array is currently not sorted).
 * If we find an out-of-order pair:
 * - We check our operations limit 'k'. If k is exactly 1, our observation proves we are stuck, so we immediately print "NO" and return.
 * - If k > 1, our observation proves we can always sort it, so we immediately print "YES" and return.
 * If the loop completely finishes without finding any out-of-order pairs, it means the array was already perfectly sorted to begin with! In that case, we just print "YES" and return.
 */


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
