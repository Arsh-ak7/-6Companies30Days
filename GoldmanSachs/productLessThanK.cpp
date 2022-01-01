int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    // int n = a.size();
    int cnt = 0;
    long long prod = 1;
    int i = 0, j = 0;

    while (j < n)
    {
        prod *= a[j];
        if (prod >= k)
        {
            while (prod >= k && i <= j)
            {
                prod /= a[i];
                i++;
            }
        }

        cnt += (j - i + 1);
        j++;
    }
    return cnt;
}