
/*

PROBLEM STATEMENT :


Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9


*/

class Solution
{
public:
    bool isValid(string s)
    {
        if (s[0] > '2')
            return false;
        if (s[0] == '2')
        {
            if (s[1] >= '4')
            {
                return false;
            }
        }

        if (s[2] >= '6')
            return false;

        return true;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        //Base Case For The Problem:
        if (nums.size() <= 1)
            return {nums};

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto res = permute(v);

            for (int j = 0; j < res.size(); j++)
            {
                vector<int> _v = res[j];
                _v.insert(_v.begin(), nums[i]);
                result.push_back(_v);
            }
        }

        return result;
    }

    string largestTimeFromDigits(vector<int> &A)
    {
        vector<vector<int>> res;
        vector<string> valid; //For Only Storing the Valid Time Permutations

        res = permute(A);

        //Now , Iterating Over All the Permutations:
        for (int i = 0; i < res.size(); i++)
        {
            string curr = "";
            for (int j = 0; j < res[i].size(); ++j)
            {
                curr += static_cast<char>(res[i][j]) + '0';
            }
            if (isValid(curr))
                valid.push_back(curr);
        }
        sort(valid.begin(), valid.end());

        string ans = ""; //The Final Answer that we have to return at the end.

        if (valid.size() > 0)
        {
            //Now , perform the Required Operations:
            string temp = valid[valid.size() - 1];
            ans = temp.substr(0, 2) + ":" + temp.substr(2);
        }

        return ans;
    }
};