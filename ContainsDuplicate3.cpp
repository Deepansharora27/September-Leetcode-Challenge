

//Time Complexity Of This Approach : O(N^2)
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if (!nums.size())
            return false;
        vector<pair<long long, int>> vect;
        for (int i = 0; i < nums.size(); ++i)
        {
            vect.push_back(make_pair(nums[i], i));
        }

        sort(vect.begin(), vect.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size() && vect[j].first - vect[i].first <= t; ++j)
            {
                if (abs(vect[i].second - vect[j].second) <= k)
                    return true;
            }
        }

        return false;
    }
};