int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i = 0; i <= m; i++) prev[i] = i;

    for(int i = 1; i <= n; i++)
    {
        cur[0] = i;
        for(int j = 1; j <= m; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                cur[j] = prev[j-1];
            }
            else
            {
                cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
            }
        }
        prev = cur;
    }

    return prev[m];
}