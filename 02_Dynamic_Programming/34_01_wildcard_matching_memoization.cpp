bool helper(int n, int m, string &pattern, string &text, vector<vector<int>> &dp)
{
   if(n < 0 and m < 0) return true;
   if(n < 0 and m >= 0) return false;
   if(m < 0 and n >= 0)
   {
      for(int i = 0; i <= n; i++)
      {
         if(pattern[i] != '*')
         {
            return false;
         }
         return true;
      }
   }
   if(dp[n][m] != -1)
   {
    return dp[n][m];
   }
   if(pattern[n] == text[m] or pattern[n] == '?')
   {
      return dp[n][m] = helper(n-1, m-1, pattern, text, dp);
   }
   if(pattern[n] == '*')
   {
      return dp[n][m] = helper(n, m-1, pattern, text, dp) or helper(n-1, m, pattern, text, dp);
   }
   return dp[n][m] = false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
   return helper(n-1, m-1, pattern, text, dp);
}
