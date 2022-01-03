string helper(string s, int &i)
{
    string ans = "";
    int c = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
            c = 10 * c + s[i] - '0';
        else if (s[i] == '[')
        {
            i++;
            string temp = helper(s, i);
            while (c--)
                ans += temp;
            c = 0;
        }
        else if (s[i] == ']')
            return ans;
        else
            ans += s[i];
        i++;
    }
    return ans;
}
string decodedString(string s)
{
    int i = 0;
    return helper(s, i);
}