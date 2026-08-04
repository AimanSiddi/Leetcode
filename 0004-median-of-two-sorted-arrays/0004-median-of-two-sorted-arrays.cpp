class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> v(n+m);
        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) v[k++]=nums1[i++]; 
            else v[k++]=nums2[j++];
        }
        if(i==n){
            while(j<m){
                v[k++]=nums2[j++];
            }
        }
        if(j==m){
            while(i<n){
                v[k++]=nums1[i++];
            }
        }
        if((n+m) % 2 != 0) 
          return v[(n+m)/2];
        else 
          return (v[(n+m)/2] + v[(n+m)/2 - 1]) / 2.0; 
    }
};