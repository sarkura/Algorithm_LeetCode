/*
 * @lc app=leetcode id=151 lang=cpp
 * @lcpr version=30404
 *
 * [151] Reverse Words in a String
 */
// String.md
// String

// @lc code=start

#include <string>
using namespace std;

class Solution 
{
public:
    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        while (end < s.size()) 
        {
            while (end < s.size() && s[end] == ' ') end++;
            start = end;
            while (end < s.size() && s[end] != ' ') end++;
            reverse(s.begin() + start, s.begin() + end);
        }
        return s;
    }
    
    void removeExtraSpaces(string &s)
    {
        int slowindex = 0;
        for (int fastindex = 0; fastindex < s.size(); fastindex++)
        {
            if (s[fastindex] != ' ') 
            {
                if (slowindex != 0) 
                {
                    s[slowindex++] = ' ';
                }
                while (fastindex < s.size() && s[fastindex] != ' ') 
                {
                    s[slowindex++] = s[fastindex++];
                }
            }
        }
        s.resize(slowindex);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

