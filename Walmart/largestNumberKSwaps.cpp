void helper(string &ans, int k, string &str, int ctr)
{
    if (k == 0)
        return;

    int n = str.length();
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; ++j)
    {
        if (maxm < str[j])
            maxm = str[j];
    }
    if (maxm != str[ctr])
        --k;
    for (int j = n - 1; j >= ctr; j--)
    {
        if (str[j] == maxm)
        {
            swap(str[ctr], str[j]);
            if (str.compare(ans) > 0)
                ans = str;
            helper(ans, k, str, ctr + 1);
            swap(str[ctr], str[j]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    string ans = str;
    helper(ans, k, str, 0);
    return ans;
}