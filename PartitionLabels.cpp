

/*

PROBLEM STATEMENT : 

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.

*/

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> last_occurence(26, 0);
        for (int i = 0; i < S.length(); ++i)
        {
            last_occurence[S[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;
        int end = 0;
        for (int i = 0; i < S.length(); ++i)
        {
            end = max(end, last_occurence[S[i] - 'a']);
            if (i == end)
            {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};