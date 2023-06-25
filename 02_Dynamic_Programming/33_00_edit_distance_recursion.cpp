int helper(int n, int m, string a, string b)
{
    /* if string 1 gets exhausted, then you've to insert all the remaining portion of string 2 */
    if(n < 0) return m + 1;
    if(m < 0) return n + 1;

    /* if strings matched at some point, no work done */
    if(a[n] == b[m]) return 0 + helper(n-1, m-1, a, b);

    return 1 + min(helper(n-1, m, a, b), min(helper(n, m-1, a, b), helper(n-1, m-1, a, b)));
}
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    
    return helper(n-1, m-1, str1, str2);
}