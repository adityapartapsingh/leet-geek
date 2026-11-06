class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        vector<pair<int,int>> qs;
        for (int i = 0; i < q; i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        vector<int> ans(q);

        unordered_map<int,int> freq;
        int activeServers = 0;

        int left = 0;
        int right = 0;

        for (auto& [queryTime, idx] : qs) {

            // Add logs with time <= queryTime
            while (right < logs.size() &&
                   logs[right][1] <= queryTime) {

                int server = logs[right][0];

                if (++freq[server] == 1)
                    activeServers++;

                right++;
            }

            // Remove logs with time < queryTime - x
            while (left < right &&
                   logs[left][1] < queryTime - x) {

                int server = logs[left][0];

                if (--freq[server] == 0)
                    activeServers--;

                left++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};