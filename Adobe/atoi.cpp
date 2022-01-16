class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        // Your code here
        int num = 0, i = 0;
        bool isNegative = false;
        if (str[0] == '-')
        {
            isNegative = true;
            i++;
        }
        while (i < str.length())
        {
            if (!isdigit(str[i]))
                return -1;
            else
            {
                num = num * 10 + (str[i] - '0');
            }
            ++i;
        }
        return isNegative ? -1 * num : num;
    }
};
