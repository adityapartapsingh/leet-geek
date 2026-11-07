class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > freeServers; // {weight, index}

        priority_queue<
            tuple<ll,int,int>,
            vector<tuple<ll,int,int>>,
            greater<tuple<ll,int,int>>
        > busy; // {freeTime, weight, index}

        int n = servers.size(), m = tasks.size();

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);

        ll time = 0;

        for (int i = 0; i < m; i++) {
            time = max(time, (ll)i);

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();
                freeServers.push({w, idx});
            }

            if (freeServers.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    freeServers.push({w, idx});
                }
            }

            auto [w, idx] = freeServers.top();
            freeServers.pop();

            ans[i] = idx;
            busy.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};