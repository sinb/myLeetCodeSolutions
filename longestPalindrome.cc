#include <iostream>
using namespace std;
class Solution {
public:
//对字符串中的每一个字符,以它为中心,向两边扩展
//判断这个扩展到的子字符串是不是回文,记录回文的长度,维护一个最大值,并记录最大回文对应的位置和长度以便最后返回
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
