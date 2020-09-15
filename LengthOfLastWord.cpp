/*
PROBLEM STATEMENT : 

Solution
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*/
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        vector<string> s1;
        istringstream iss(s);

        do
        {
            string subs;
            iss >> subs;
            s1.push_back(subs);
        } while (iss);

        if (s1.size() < 2)
        {
            return 0;
        }

        string tmp = s1[s1.size() - 2];

        return tmp.length();
    }
};