class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int mx = -1;
        for (int &it : piles)
        {
            mx = max(it, mx);
        }
        int left = 1, right = mx;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int time = 0;
            for (int it : piles)
            {
                time += (it / mid) + (it % mid != 0);
            }
            if (time <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int l=1, r=1000000000;
    //     while(l<=r)
    //     {
    //         int m=l+(r-l)/2, t=0;
    //         for(int i=0; i<piles.size(); ++i)
    //             t+=(piles[i]/m + (piles[i]%m != 0));
    //         if(t>h)
    //             l=m+1;
    //         else
    //             r=m-1;
    //     }
    //     return l;
    // }
};