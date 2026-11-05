class Solution {
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;

    void rebalance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            long long x = *it;

            low.erase(it);
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            long long x = *it;

            high.erase(it);
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    }

    void add(long long x) {
        if (low.empty() || x <= *prev(low.end())) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        rebalance();
    }

    void remove(long long x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= x;
        } else {
            it = high.find(x);
            high.erase(it);
            sumHigh -= x;
        }

        rebalance();
    }

    long long getCost() {
        long long med = *prev(low.end());

        return med * (long long)low.size() - sumLow
             + sumHigh - med * (long long)high.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost;

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost.push_back(getCost());

        for (int r = x; r < n; r++) {
            add(nums[r]);
            remove(nums[r - x]);
            cost.push_back(getCost());
        }

        int m = cost.size();

        const long long INF = 4e18;

        vector<long long> prev(m + 1, 0), cur(m + 1, INF);

        for (int t = 1; t <= k; t++) {
            fill(cur.begin(), cur.end(), INF);

            for (int i = 1; i <= m; i++) {
                cur[i] = cur[i - 1];

                int p = max(0, i - x);

                if (prev[p] != INF) {
                    cur[i] = min(
                        cur[i],
                        prev[p] + cost[i - 1]
                    );
                }
            }

            swap(prev, cur);
        }

        return prev[m];
    }
};