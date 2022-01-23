class Solution
{
public:
    void bfs(vector<vector<int>> &graph, int x, vector<bool> &visited)
    {
        visited[x] = true;
        queue<int> q;
        q.push(x);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                if (!visited[it])
                    bfs(graph, it, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(graph, i, visited);
                ++count;
            }
        }
        return count;
    }
};