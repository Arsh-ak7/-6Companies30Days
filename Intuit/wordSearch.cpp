vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
bool dfs(vector<vector<char>> &board, string word, int i, int j, int n)
{
    if (n == word.size())
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[n])
        return false;
    board[i][j] = '0';
    for (int k = 0; k < 4; ++k)
    {
        if (dfs(board, word, i + dx[k], j + dy[k], n + 1))
        {
            board[i][j] = word[n];
            return true;
        }
    }
    board[i][j] = word[n];
    return false;
}
bool isWordExist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}