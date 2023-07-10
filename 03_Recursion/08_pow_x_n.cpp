double myPow(double x, int n) {
    double ans = 1.0;

    // create a copy of n, so that even if it gets destroyed, no worries
    long long new_n = n;

    // now n can be +ve or it can be -ve, so if it is -ve then i can basically
    // multiply it with -1 and return ans as 1/ans
    if(new_n < 0) new_n = -1 * new_n;

    // traverse the number of times n exist
    while(new_n!=0)
    {
        // if n is even
        if(new_n % 2 == 0)
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

    if(n < 0) return (double)(1.0) / (double)(ans);
    return ans;
}