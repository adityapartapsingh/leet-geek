class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visited;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (visited.find(complement) != visited.end()) {
                return {visited[complement], i};
            }
            visited[nums[i]] = i;
        }

        return {}; 
    }
    
};