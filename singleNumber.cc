#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//出现两次的,两次异或之后就为0了.
//只留下出现一次的
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            x ^= nums[i];
            //cout << x << endl;
        }
        return x;

    }
//所有数字,除了一个,都出现了3次,找到出现一次的.
//把一个整数看成二进制,比如一个int是4字节,32位二进制
//用一个大小32的数组来存储一个整数里每一位1的位置
//如果这个数字出现了3次,在对应位置上count[i]的值就是3
//如果只出现了一次,就是1
//那么用%3就能过滤掉所有出现了3次的数字
//把留下的重新拼成一个整数即可
    int singleNumberII(vector<int>& nums) {
        const int W = sizeof(int)*8; //32 bit for an integer
        int count[W] = {0};
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                count[j] += (nums[i]>>j)&1; //store the '1' appearence times of the jth bit
                count[j] %= 3; // if appearence times is 3, just leave it
            }
        }
        int result = 0;
        for (int i = 0; i < W; ++i)
        {
            result += (count[i]<<i);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> a = {77,2,44,11,11,2,77,1,44};
    vector<int> b = {77,2,44,11,11,2,77,5,44,77,2,44,11};
    s.singleNumber(a);
    cout << s.singleNumberII(b);

}
