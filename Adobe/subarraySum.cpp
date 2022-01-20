vector<int> subarraySum(int arr[], int n, long long s)
{
    // Your code here
    int low = 0, high = n - 1, sum = 0, i = 0;
    while (low <= high)
    {
        sum += arr[i];
        if (sum == s)
        {
            return {low + 1, i + 1};
        }
        if (sum > s)
        {
            while (sum > s)
            {
                sum -= arr[low];
                low++;
                if (sum == s)
                {
                    return {low + 1, i + 1};
                }
            }
        }
        i++;
    }
    return {-1};
}