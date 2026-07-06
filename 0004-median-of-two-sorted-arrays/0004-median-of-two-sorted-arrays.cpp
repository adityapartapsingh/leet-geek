class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m =nums1.size();
        int n = nums2.size();
        int t =m+n;
        
        int i=0,j=0;
        int m1=-1,m2=-1;

        for (int count =0; count<=t /2;count++){
            m2 =m1;

            if(i< m && (j>=n || nums1[i]<=nums2[j])){
                m1=nums1[i++];
            }else {
                m1 =nums2[j++];
            }
        }

        if (t % 2==1){
            return m1;
        }
        else{
            return (double)(m1+m2)/2.0 ;
        }
    }
};