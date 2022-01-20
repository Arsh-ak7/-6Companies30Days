#define ll long long

class Solution
{
public:
    int MOD = 1e9 + 7;
    int kvowelwords(int n, int k)
    {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][k] * 21 % MOD;
                    if (j > 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 5 % MOD) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};