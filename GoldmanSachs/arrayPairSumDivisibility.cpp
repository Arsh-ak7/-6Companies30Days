bool canPair(vector<int> nums, int k)
{
    map<int, int> mp;
    int n = nums.size();
    for (int it : nums)
        mp[it % k]++;

    for (int it : nums)
    {
        int rem = it % k;
        if (rem == 0)
        {
            if (mp[0] & 1)
                return 0;
        }
        else if (mp[rem] != mp[k - rem])
            return 0;
    }
    return 1;
}