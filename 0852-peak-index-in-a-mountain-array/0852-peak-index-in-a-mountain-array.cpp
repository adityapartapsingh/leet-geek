class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int index=0;
        int max=arr[0];
        for(int i=1; i< arr.size();i++){
            if(arr[i]>max){
                max=arr[i];
                index=i;
            }
        }
        return index;
    }
};