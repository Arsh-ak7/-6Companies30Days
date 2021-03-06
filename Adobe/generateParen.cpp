vector<string> solve(int n, vector<vector<string>> &dp)
{
    if (dp[n][0] != "#")
        return dp[n];
    set<string> s;
    vector<string> c = solve(n - 1, dp);
    for (int i = 0; i < c.size(); i++)
    {
        s.insert("(" + c[i] + ")");
    }
    for (int i = n - 1, j = 1; i >= j; i--, j++)
    {
        vector<string> a = solve(i, dp), b = solve(j, dp);
        for (int k = 0; k < a.size(); k++)
        {
            for (int l = 0; l < b.size(); l++)
            {
                s.insert(a[k] + b[l]);
                s.insert(b[l] + a[k]);
            }
        }
    }
    vector<string> v(s.begin(), s.end());
    dp[n] = v;
    return v;
}
vector<string> AllParenthesis(int n)
{
    vector<vector<string>> dp(13, {"#"});
    dp[1] = {"()"};
    return solve(n, dp);
}