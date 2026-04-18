/*349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/
// o(nlogn)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i =0 , j =0 ;
        vector<int> res;
        while(i != nums1.size() && j != nums2.size()){
            if(nums1[i]==nums2[j] && (res.empty() || res.back() != nums1[i])) res.push_back(nums1[i]);
            if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return res;
    }
};
