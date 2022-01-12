vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    sort(arr.begin(), arr.end());
    int sz = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < sz - 3; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < sz - 2; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int left = j + 1, right = sz - 1;
            int currSum = arr[i] + arr[j];
            while (left < right)
            {
                if (currSum + arr[left] + arr[right] == k)
                {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                    left++, right--;
                    while (left < right && arr[left] == arr[left - 1])
                        left++;
                    while (right > left && arr[right] == arr[right + 1])
                        right--;
                }
                else if (currSum + arr[left] + arr[right] < k)
                    left++;
                else
                    right--;
            }
        }
    }
    return ans;
}