class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    vector<vector<int>> ans;
    bool isValid(vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &vis, int height)
    {
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || height > heights[x][y] || vis[x][y])
            return false;
        else
            return true;
    }

    void dfs(vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &visited, vector<vector<bool>> &vis)
    {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            if (isValid(heights, x + dx[i], y + dy[i], visited, heights[x][y]))
            {
                dfs(heights, x + dx[i], y + dy[i], visited, vis);
            }
        }
        if (visited[x][y] && vis[x][y])
            ans.push_back({x, y});
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> atlantic(n, vector<bool>(m, 0)), pacific(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (!atlantic[i][m - 1])
                dfs(heights, i, m - 1, atlantic, pacific);
            if (!pacific[i][0])
                dfs(heights, i, 0, pacific, atlantic);
        }

        for (int i = 0; i < m; i++)
        {
            if (!atlantic[n - 1][i])
                dfs(heights, n - 1, i, atlantic, pacific);
            if (!pacific[0][i])
                dfs(heights, 0, i, pacific, atlantic);
        }
        return ans;
    }
};