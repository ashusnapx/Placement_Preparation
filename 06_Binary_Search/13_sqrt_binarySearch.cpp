int floorSqrt(int n)
{
    if(n == 0) return 0;
    int lo = 1, hi = n;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        long long val = mid * mid;

        if (val <= n) // Handle non-perfect square roots
        {
            lo = mid + 1; // Update lower boundary
        }
        else
        {
            hi = mid - 1; // Update upper boundary
        }
    }

    return hi;
}
