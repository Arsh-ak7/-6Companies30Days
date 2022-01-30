class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        vector<double> mx(n, (double)0.0);
        pq.push({(double)1.0, start});
        mx[start] = 1.0;
        vector<int> visited(n, 0);
        while (!pq.empty())
        {
            pair<double, int> temp = pq.top();
            double probab = temp.first;
            int node = temp.second;
            pq.pop();
            if (!visited[node])
            {
                visited[node]++;
                for (auto &it : graph[node])
                {
                    if (mx[it.first] < it.second * probab)
                    {
                        mx[it.first] = it.second * probab;
                        pq.push({mx[it.first], it.first});
                    }
                }
            }
        }
        return mx[end];
    }
};