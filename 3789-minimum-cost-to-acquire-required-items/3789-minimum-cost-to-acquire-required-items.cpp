class Solution {
public:
    long long minimumCost(long long cost1, long long cost2,
                          long long costBoth,
                          long long need1, long long need2) {

        auto calc = [&](long long x) -> long long {
            return x * costBoth
                 + max(0LL, need1 - x) * cost1
                 + max(0LL, need2 - x) * cost2;
        };

        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        return min({calc(0), calc(mn), calc(mx)});
    }
};