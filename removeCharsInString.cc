#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//删除一个字符串里的某一个字符
//比如 abcdbbefg, 删除所有的b
//输出是acdefg
//使用时间O(n)和空间O(1)的方法,不用STL.
//是用两个指针一前一后来记录
//用i遍历字符串,j记录不是特定字符的位置,碰到特定字符时候i继续走,j停下,
//如果不是特定字符,执行input[j] = input[i],既可以移动字符又可以去除特定字符
//最后只返回input的前j个.
//当然也可以用STL的remove,并且用erase调整大小.
class Solution
{
public:
    string removeCharsInString(string input, char c)
    {
        size_t j = 0;
        for (size_t i = 0; i < input.size(); ++i)
        {
            if (input[i] != c)
            {
                input[j] = input[i];
                j += 1;
            }
        }
        return input.substr(0, j);
    }
    void removeCharsFromString( string &str, char* charsToRemove ) {
        for ( unsigned int i = 0; i < strlen(charsToRemove); ++i )
        {
            str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
        }
   }

};
int main()
{
    string str = "abcdbbefg";
    char c = 'b';
    Solution s;
    cout << s.removeCharsInString(str, c) << endl;
    cout << str << endl;
    cout << "Using STL" << endl;
    s.removeCharsFromString(str, "b");
    cout << str;
}
