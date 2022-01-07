class Solution
{
public:
    int lr[4] = {0, 0, -1, 1};
    int dr[4] = {-1, 1, 0, 0};
    int orangesRotting(vector<vector<int>> &grid)
    {
        int freshOranges = 0, rotten = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int count = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    rotten++;
                }
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int r = p.first + lr[i];
                    int c = p.second + dr[i];
                    if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        q.push({r, c});
                        freshOranges--;
                    }
                }
            }
            count++;
        }
        if (freshOranges > 0)
            return -1;
        if (count == -1)
            return 0;
        return count;
    }
};