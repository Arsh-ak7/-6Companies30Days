string gcdOfStrings(string str1, string str2)
{
    if (str2.size() > str1.size())
        swap(str1, str2);

    string ans = "";
    int i = 0;
    if (str1 + str2 != str2 + str1)
        return ans;
    int gcd = __gcd(str1.size(), str2.size());
    ans = str1.substr(0, gcd);
    return ans;
}