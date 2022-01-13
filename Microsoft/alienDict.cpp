void topSortUtil(map<char, list<char>> adj, map<char, bool> &visited, stack<char> &s, char curr)
{
    visited[curr] = true;
    for (char it : adj[curr])
    {
        if (!visited[it])
            topSortUtil(adj, visited, s, it);
    }
    s.push(curr);
}

void makeGraph(map<char, list<char>> &mp, char src, char dest)
{
    mp[src].push_back(dest);
}

string findOrder(string dict[], int N, int K)
{
    map<char, list<char>> mp;
    for (int i = 0; i < N - 1; i++)
    {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        int n = word1.length();
        int m = word2.length();
        int j = 0;
        while (j < min(n, m))
        {
            if (word1[j] != word2[j])
            {
                makeGraph(mp, word1[j], word2[j]);
                break;
            }
            j++;
        }
    }
    string s = "";
    stack<char> st;
    map<char, bool> visited;
    for (int i = 0; i < K; i++)
    {
        if (!visited[char(97 + i)])
            topSortUtil(mp, visited, st, char(97 + i));
    }
    // cout<<s<<endl;
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    // cout<<s;
    return s;
}