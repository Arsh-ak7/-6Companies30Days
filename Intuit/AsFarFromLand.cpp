class Solution
{
public:
    vector<int> dr{0, 0, -1, +1};
    vector<int> dc{-1, +1, 0, 0};

    bool isValid(int nx, int ny, int n)
    {
        return (nx >= 0 && ny >= 0 && nx < n && ny < n);
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        int curr = 0;
        while (!q.empty())
        {
            int qsize = q.size();
            while (qsize--)
            {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dr[i];
                    int ny = y + dc[i];
                    if (isValid(nx, ny, n) && grid[nx][ny] != -1)
                    {
                        grid[nx][ny] = -1;
                        q.push({nx, ny});
                    }
                }
            }
            curr++;
        }
        if (curr == 0 || curr == 1)
            return -1;
        return curr - 1;
    }
};