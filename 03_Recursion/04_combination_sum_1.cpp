class Solution
{
    public:
        void helper(int ind, int target, vector<int> &c, vector<vector< int >> &ans, vector< int > &v)
        {
           	// base case
            if (ind == c.size())
            {
                if (target == 0)
                {
                    ans.push_back(v);
                }
                return;
            }

           	// now pick and not pick conditions
            if (c[ind] <= target)
            {
                v.push_back(c[ind]);
                helper(ind, target - c[ind], c, ans, v);
                v.pop_back();
            }
            helper(ind + 1, target, c, ans, v);
        }
    vector<vector < int>> combinationSum(vector<int> &c, int target)
    {
        vector<vector < int>> ans;
        vector<int> v;
        helper(0, target, c, ans, v);
        return ans;
    }
};
/*
time complexity : 2^t *k
space complexity : k *x
*/