class Solution
{
public:
    int findInMountainArray(int target, MountainArray &m)
    {
        int l = 0, r = m.length() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (m.get(mid) < m.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        int peak = l;
        l = 0, r = peak;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (m.get(mid) < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (m.get(l) == target)
            return l;

        l = peak + 1, r = m.length() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (m.get(mid) == target)
                return mid;
            if (m.get(mid) < target)
                r = mid;
            else
                l = mid + 1;
        }

        if (m.get(l) == target)
            return l;
        else
            return -1;
    }
};