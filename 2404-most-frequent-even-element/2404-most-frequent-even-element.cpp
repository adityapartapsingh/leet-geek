class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        int max=0;
        int freq=-1;
        
        for (int num : nums) {
            if(num%2==0){
                counts[num]++;
            }
            if (counts[num] >max) {
                max=counts[num];
                freq=num;
            }
            if(counts[num]==max && num<freq){
                freq=num;
            }
        }
        return freq; 
    }
};