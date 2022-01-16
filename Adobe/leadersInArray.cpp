class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> ss(n, 0);
        ss[n - 1] = a[n - 1];
        int mxTillNow = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > mxTillNow)
            {
                mxTillNow = a[i];
            }
            ss[i] = mxTillNow;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= ss[i])
                ans.push_back(a[i]);
        }
        return ans;
    }
};