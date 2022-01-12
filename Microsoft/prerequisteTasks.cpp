bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vector<int> adj[N];
    for (auto &it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

    vector<int> inDegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
            inDegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        for (auto it : adj[curr])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    return count == N;
}