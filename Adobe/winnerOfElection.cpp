vector<string> winner(string arr[], int n)
{
    // Your code here
    // Return the string containing the name and an integer
    // representing the number of votes the winning candidate got
    map<string, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    string str = "";
    int mx = 0;
    for (auto it : mp)
    {
        if (it.second > mx)
        {
            mx = it.second;
            str = it.first;
        }
    }
    return vector<string>({str, to_string(mx)});
}