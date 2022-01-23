class Solution
{
public:
    int calcDist(int x1, int x2, int y1, int y2)
    {
        return (abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
    }
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                mp[i][calcDist(points[i][0], points[j][0], points[i][1], points[j][1])]++;
            }
        }
        int count = 0;
        for (auto it : mp)
        {
            for (auto &i : it.second)
            {
                count += (i.second) * (i.second - 1);
            }
        }
        return count;
    }
};