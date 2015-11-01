#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, c;
        int max = 0;
        int loc = 0;
        bool odd = false;
        int n = s.size();
        for (i = 0; i < n; ++i) // for every char
        {
            for (j = 0; (i - j) >= 0 && (i + j) < n; ++j) // odd substr
            {
                if (s[i-j] != s[i+j])
                {
                    break;
                }

                c = 2*j+1;
            }
            if (c > max)
            {
                max = c;
                loc = i;
                odd = true;
            }

            for (j = 0; (i - j) >= 0 && (i + j + 1) < n; ++j)
            {
                if (s[i-j] != s[i+j+1])
                    break;
                c = 2*j+2;
            }
            if (c > max)
            {
                max = c;
                loc = i;
                odd = false;
            }
        }
        if (odd)
            return s.substr(loc-int(max/2), max);
        else
            return s.substr(loc-max/2+1, max);

    }
};
int main()
{
    Solution s;
    cout << s.longestPalindrome("abba");
}
