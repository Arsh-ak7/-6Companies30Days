class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        sum = sum / 2;
        int dp[sum + 1] = {0};
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = sum; j >= arr[i]; j--)
            {
                if (dp[j - arr[i]] == 1 || j == arr[i])
                    dp[j] = 1;
            }
        }
        return dp[sum];
    }
};