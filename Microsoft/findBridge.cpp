void dfs(int start, vector<bool> &visited, vector<int> adj[], int c, int d)
{
    visited[start] = true;
    for (auto &node : adj[start])
    {
        if (start == c && node == d || start == d && node == c)
            continue;
        if (!visited[node])
            dfs(node, visited, adj, c, d);
    }
}
// Function to find if the given edge is a bridge in graph.
int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Code here
    vector<bool> visited(V);
    dfs(c, visited, adj, c, d);
    if (!visited[d])
        return 1;
    return 0;
}