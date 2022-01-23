class Solution
{
public:
    bool canShip(int mid, vector<int> &weights, int days)
    {
        int totalDays = 0;
        int currWeight = 0;
        int i = 0;
        while (i < weights.size())
        {
            if (weights[i] > mid)
                return false;
            currWeight += weights[i];
            if (currWeight >= mid)
            {
                if (currWeight > mid)
                    --i;
                currWeight = 0;
                ++totalDays;
            }
            ++i;
        }
        if (currWeight > 0 && currWeight < mid)
            ++totalDays;
        return totalDays <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = 0;
        int right = 0;
        for (int it : weights)
            right += it;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canShip(mid, weights, days))
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};