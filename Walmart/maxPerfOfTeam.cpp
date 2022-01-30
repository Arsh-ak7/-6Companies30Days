class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v.push_back({efficiency[i], speed[i]});
        sort(rbegin(v), rend(v));
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long curr = 0;
        for (auto [eff, sp] : v)
        {
            curr += sp;
            pq.push(sp);
            if (pq.size() > k)
            {
                curr -= pq.top();
                pq.pop();
            }
            long long currVal = curr * eff;
            ans = max((long long)ans, (long long)currVal);
        }
        long long MOD = 1e9 + 7;
        return ans % (int)MOD;
    }
};