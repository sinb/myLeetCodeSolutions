#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//判断字符串a里的字符是否全部包含字符串b里的字符,就是是否是全集和子集
//先排序,a不包含b的意思是
//1.排序后b的地第一个字符就比a的第一个字符小
//2.

bool StringContain(string &a,string &b)
{
    const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97, 101};
    unsigned long f = 1;
    for (int i = 0; i < a.length(); ++i)
    {
        int x = p[a[i] - 'A'];
        if (f % x)
        {
            f *= x;
        }
    }
    for (int i = 0; i < b.length(); ++i)
    {
        int x = p[b[i] - 'A'];
        if (f % x)
        {
            return false;
        }
    }
    return true;
}
int main() {
    string a = "ABCDEEEESSSXXXVVQQWWGREE";
    string b = "ABC";
    bool c = StringContain(a, b);
    cout << c;
    string str = "wet";
    transform(str.begin(), str.end(),str.begin(), ::toupper);
    cout << str << endl;
    return 0;
}
