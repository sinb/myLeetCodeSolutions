#include <iostream>

using namespace std;
bool isPalindrome(const char* s, int n) {
    //从中心向两边比较
    if (s == NULL || n < 1)
        return false;
    int m = ((n>>1) - 1) >=0 ? (n>>1) - 1 : 0;
    char *first, *second;
    first = (char*)s + m;
    second = (char*)s + n - 1 - m;
    while (first >= s) {
        if (*(first--) != *(second++))
            return false;
    }
    return true;
    //先计算中心位置.
    //中心位置的定义,如果n是偶数比如4,abba,那么中心就是4/2-1=1, 0123
    //如果n是奇数比如5,那么中心就是5/2向下取整再减1, floor(5/2)-1 = 1, 01234,因为奇数的中心不需要比较
    //减1的原因,以为下标从0开始
    //边界情况,n=1时应该直接return true,怎么和其他情况放在一起?
    //n=2应该直接返回false
}
class Solution {
public:
//这个方法用了stack和队列,一个FILO,一个FIFO,比较每个字符即可
//这个方法很慢
    bool isPalindrome(string s) {
        stack<char> stk;
        queue<char> que;
        for (auto c :s)
        {
            if (isalpha(c) || isdigit(c))
            {
                stk.push(tolower(c));
                que.push(tolower(c));
            }
        }
        while (stk.size() != 0)
        {
            char s = stk.top();
            char q = que.front();
            if (s != q)
                return false;
            stk.pop();
            que.pop();
        }
        return true;
    }
};
int main()
{
    int n = 5;

    int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0; // m is themiddle point of s
    cout << m << endl;

    cout << isPalindrome("cdadc", 5);
    return 0;
}
