string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(int index, int N, int a[], string &curr, vector<string> &ans)
{
    if (index >= N)
    {
        ans.push_back(curr);
        return;
    }

    int currNum = a[index];
    string keyPad = keypad[currNum];
    for (int i = 0; i < keyPad.length(); i++)
    {
        curr.push_back(keyPad[i]);
        dfs(index + 1, N, a, curr, ans);
        curr.pop_back();
    }
}

vector<string> possibleWords(int a[], int N)
{
    // Your code here
    vector<string> ans;
    if (N == 0)
        return ans;
    string curr = "";
    dfs(0, N, a, curr, ans);
    return ans;
}