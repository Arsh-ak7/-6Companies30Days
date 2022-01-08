class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {
        // code here
        int dp[K + 1][N + 1];

        for (int i = 0; i <= K; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= N; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int max_so_far = INT_MIN;
                for (int k = 0; k < j; k++)
                    max_so_far = max(max_so_far, A[j] - A[k] + dp[i - 1][k]);

                dp[i][j] = max(dp[i][j - 1], max_so_far);
            }
        }
        return dp[K][N - 1];
    }
};