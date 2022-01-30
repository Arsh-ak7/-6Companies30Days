class Solution
{
public:
    int height(int N)
    {
        // code here
        int i = 1;
        int curr = N;
        while (curr > 0)
        {
            curr -= (i + 1);
            i += 1;
        }
        return i - 1;
    }
};