#include <iostream>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum = (currSum + nums[i]) > nums[i] ? (currSum + nums[i]) : nums[i];
            //如果currSum没有对下一个数字求和作出贡献(增大),那么当前的currSum就不要了,重新将nums[i]
            //视为新的子数组的开头
            maxSum = maxSum > currSum ? maxSum : currSum;

        }
        return maxSum;
    }
    int maxSubArrayWithStartEnd(vector<int>& nums, int &s, int &e) {
        int maxSum = nums[0];
        int currSum = 0;
        // init start and end index as zero
        s = 0;
        e = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((currSum + nums[i]) > nums[i]) {
                currSum = currSum + nums[i];
                if (maxSum > currSum) {
                    maxSum = maxSum;
                }
                else {
                    maxSum = currSum;
                    e = i; // there should update end index
                }
            }
            else {
                s = i; //update start and end index
                e = i;
                currSum = nums[i];
            }
        }
        return maxSum;
    }
};
int main() {
    vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};
    int s, e;
    Solution solution;
    cout << solution.maxSubArrayWithStartEnd(nums, s, e) << endl;
    cout << s << endl << e;
}
