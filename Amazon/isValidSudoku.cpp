int isValid(vector<vector<int>> mat)
{
    bool unique[10];
    for (int i = 0; i < 9; i++)
    {
        memset(unique, false, sizeof(unique));
        for (int j = 0; j < 9; j++)
        {
            if (unique[mat[i][j]])
            {
                return false;
            }
            if (mat[i][j] != 0)
                unique[mat[i][j]] = true;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        memset(unique, false, sizeof(unique));
        for (int j = 0; j < 9; j++)
        {
            if (unique[mat[j][i]])
            {
                return false;
            }
            if (mat[j][i] != 0)
                unique[mat[j][i]] = true;
        }
    }
    for (int i = 0; i < 7; i += 3)
    {
        for (int j = 0; j < 7; j += 3)
        {
            memset(unique, false, sizeof(unique));
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (unique[mat[i + k][j + l]])
                    {
                        return false;
                    }
                    if (mat[i + k][j + l] != 0)
                        unique[mat[i + k][j + l]] = true;
                }
            }
        }
    }
    return true;
}