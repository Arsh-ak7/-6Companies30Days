class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int count = INT_MAX;
        int runningSum = 0;
        for (int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            while (runningSum >= target)
            {
                count = min(count, i + 1 - left);
                runningSum -= nums[left++];
            }
        }
        return count == INT_MAX ? 0 : count;
    }
};