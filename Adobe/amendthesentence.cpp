string amendSentence(string s)
{
    // your code here
    char ch = (char)tolower(s[0]);
    cout << ch;
    string ans = "";
    int i = 1, n = s.length();
    while (i < n)
    {
        if (isupper(s[i]))
        {
            ans += " ";
            ans += tolower(s[i]);
        }
        else
        {
            ans += s[i];
        }
        i++;
    }
    return ans;
}