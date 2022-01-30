class Solution
{
public:
    struct comp
    {
        bool operator()(string &a, string &b)
        {
            if (a.size() > b.size())
                return true;
            else if (a.size() < b.size())
                return false;
            else
            {
                int n = a.size();
                for (int i = 0; i < n; i++)
                {
                    if (a[i] - '0' > b[i] - '0')
                        return true;
                    else if (a[i] - '0' < b[i] - '0')
                        return false;
                }
                return false;
            }
        }
    };
    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, comp> pq;
        for (string &it : nums)
        {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};