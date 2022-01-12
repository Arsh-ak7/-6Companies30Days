vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

void bfs(vector<vector<int>> &grid, int i, int j, int n, int m, int &count)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        count++;
        for (int k = 0; k < 8; k++)
        {
            int r = top.first + dir[k].first;
            int c = top.second + dir[k].second;
            if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != 1)
                continue;
            grid[r][c] = 0;
            q.push({r, c});
        }
    }
}

int findMaxArea(vector<vector<int>> &grid)
{
    // Code here
    int maxArea = 1;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = -1;
                bfs(grid, i, j, n, m, count);
                maxArea = max(maxArea, count);
            }
        }
    }
    return maxArea;
}