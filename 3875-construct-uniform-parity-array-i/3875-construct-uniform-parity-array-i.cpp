class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0, evenCount = 0;
        for (int x : nums1) {
            if (x % 2 == 0) evenCount++;
            else oddCount++;
        }
        return true;
    }
};