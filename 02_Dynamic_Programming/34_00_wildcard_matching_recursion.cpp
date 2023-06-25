bool helper(int n, int m, string &pattern, string &text)
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
   if(pattern[n] == text[m] or pattern[n] == '?')
   {
      return helper(n-1, m-1, pattern, text);
   }
   if(pattern[n] == '*')
   {
      return helper(n, m-1, pattern, text) or helper(n-1, m, pattern, text);
   }
   return false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   return helper(n-1, m-1, pattern, text);
}
