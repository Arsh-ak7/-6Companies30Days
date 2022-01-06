class Solution
{
public:
    void matchPairs(char nuts[], char bolts[], int n)
    {
        // code here
        char arr[] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
        unordered_map<char, int> mp;
        for (char ch : arr)
            mp[ch] = 0;

        for (int i = 0; i < n; i++)
        {
            mp[nuts[i]]++;
        }
        int i = 0;
        for (auto it : arr)
        {
            if (mp[it] > 0)
            {
                int f = mp[it];
                while (f--)
                {
                    nuts[i] = it;
                    bolts[i] = it;
                    i++;
                }
            }
        }
    }
};