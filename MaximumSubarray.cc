#include <iostream>
#include <string>
#include <vector>
using namespace std;
//动态规划
//找和最大的连续子数组,只需要遍历一次
//对于数组里的每一个数,它只有两个选择
//1. 加入之前的子数组
//2. 从它开始新算一个子数组
//这两种情况的选择是要看选哪个能做出更大贡献,如果加入到之前的子数组里去让总和变大,就加入,这意味着之前的子数组总和是正的.
//如果加入子数组后,总和还没有自己大,说明之前的子数组和是负的,所以就从它自身算起重新计一个子数组.
//然后用一个global记录下从头到尾遍历经过的子数组和的最大值.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int local = nums[0];
        int global = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            local = max(nums[i], local+nums[i]);
            global = max(global, local);
        }
        return global;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums);
}
