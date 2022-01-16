class Solution
{
public:
    int minInsAndDel(int A[], int B[], int N, int M)
    {
        // code here
        unordered_set<int> st(B, B + M);

        vector<int> lis;
        for (int i = 0; i < N; i++)
        {
            if (st.find(A[i]) != st.end())
            {
                auto it = lower_bound(lis.begin(), lis.end(), A[i]);
                if (it == lis.end())
                    lis.push_back(A[i]);
                else
                    *it = A[i];
            }
        }
        return N + M - 2 * lis.size();
    }
};