#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
//这个题的意思是,只要在某一步上能够到达尾端n,那么就能到达了.
//搞不清楚这是贪心还是动态规划
//维护两个变量,reach是对整个数组来说,能走的最远距离
//nums[i]+i+1是在当前位置上,能走的最大距离
//最后检查reach是不是大于n,就能知道能否走到n的位置.
//用i去找到每一步台阶
//reach一定要比当前的i大,否则表示连当前的i级台阶都到达不了,所以就停止.
//在reach >= n时就说明已经可以到达了,所以应该停止.
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 1;
        for (int i = 0; i < reach&& reach < n; ++i)
        {
            reach = max(nums[i]+i+1, reach);
        }
        cout <<"reach: " << reach << endl;
        return reach >= n;
    }
};

int main()
{
    vector<int> nums = {0, 1};
    Solution s;
    cout << s.canJump(nums);
}
