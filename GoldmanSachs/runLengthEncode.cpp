string encode(string src)
{
    // Your code here
    int i = 0;
    int n = src.length();
    string ans = "";
    while (i < n)
    {
        char curr = src[i];
        int count = 0;
        ans += curr;
        while (curr == src[i])
        {
            i++;
            count++;
        }
        string c = to_string(count);
        ans += c;
    }
    return ans;
}