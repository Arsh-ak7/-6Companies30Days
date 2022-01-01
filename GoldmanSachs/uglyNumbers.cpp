ull getNthUglyNo(int n)
{
    // code here
    vector<ull> dp(n, 0);
    ull l2 = 0, l3 = 0, l5 = 0;
    dp[0] = 1;
    for (ull i = 1; i < n; i++)
    {
        ull ugly = min({dp[l2] * 2, dp[l3] * 3, dp[l5] * 5});
        dp[i] = ugly;
        ugly == dp[l2] * 2 ? ++l2 : l2 += 0;
        ugly == dp[l3] * 3 ? ++l3 : l3 += 0;
        ugly == dp[l5] * 5 ? ++l5 : l5 += 0;
    }
    return dp[n - 1];
}