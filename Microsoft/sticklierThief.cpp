int FindMaxSum(int arr[], int n)
{
    // Your code here
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;

    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);

    return dp[n - 1];
}