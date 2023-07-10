class Solution
{
    public:
        double myPow(double x, int n)
        {
            double ans = 1.0;

           	// create a copy of n, so that even if it gets destroyed, no worries
            long long new_n = n;

           	// traverse the number of times n exist
            while (new_n != 0)
            {
               	// if n is even
                if (new_n % 2 == 0)
                {
                    x = x * x;
                    new_n = new_n / 2;
                }
               	// if n is odd
                else
                {
                    ans = ans * x;
                    new_n--;
                }
            }
            return ans;
        }
    int superPow(int a, vector<int> &b)
    {
        int n = b.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = b[i] *myPow(10, n - i - 1) + ans;
        }

        return myPow(a, ans);
    }
};