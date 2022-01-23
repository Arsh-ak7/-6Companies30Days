class Solution
{
public:
    int binarySearch(int mid, int m, vector<int> &nums)
    {
        int currSum = 0, currCnt = 1;
        for (int num : nums)
        {
            currSum += num;
            if (currSum > mid)
            {
                currCnt++;
                currSum = num;
                if (currCnt > m)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int> &nums, int m)
    {
        int minVal = INT_MIN, maxVal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            minVal = max(minVal, nums[i]);
            maxVal += nums[i];
        }
        while (minVal < maxVal)
        {
            int mid = minVal + (maxVal - minVal) / 2;
            if (binarySearch(mid, m, nums))
                maxVal = mid;
            else
                minVal = mid + 1;
        }
        return minVal;
    }
};