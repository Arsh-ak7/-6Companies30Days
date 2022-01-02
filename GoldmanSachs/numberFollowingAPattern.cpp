string printMinNumberForPattern(string s)
{
    // code here
    stack<int> st;
    int num = 1;
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            st.push(num++);
            while (!st.empty())
            {
                ans += to_string(st.top());
                st.pop();
            }
        }
        else
            st.push(num++);
    }
    st.push(num++);
    while (!st.empty())
    {
        ans += to_string(st.top());
        st.pop();
    }
    return ans;
}