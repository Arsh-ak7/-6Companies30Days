int helper(int arr[], int n, vector<vector<int>> &dp, int total, int curr)
{
    if (n == 0)
        return abs((total - curr) - curr);
    if (dp[n][curr] != -1)
        return dp[n][curr];
    dp[n][curr] = min(helper(arr, n - 1, dp, total, curr + arr[n - 1]), helper(arr, n - 1, dp, total, curr));

    return dp[n][curr];
}
int minDifference(int arr[], int n)
{
    // Your code goes here
    int total = accumulate(arr, arr + n, 0);
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
    int curr = 0;
    return helper(arr, n, dp, total, curr);
}