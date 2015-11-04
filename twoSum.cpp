#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
//用一个辅助数组,存下 target - nums[i]
//然后一个指针从头,一个从尾扫描
//如果碰到nums[i] == aux[j]的,说明找到了一组,可以停下了
//比如nums: 6, 2, 9, 8, 16, target是10
//   aux : 4, 8, 1, 2, -6
//可以发现nums[1] = aux[3] == 2,找到了
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int auxArray[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            auxArray[i] = target - nums[i];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size()-1; j >= 0; j--)
                if (nums[i] == auxArray[j]) {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
        }
        return result;
    }
//还有一种不需要辅助数组的,先排序
//然后还是从头和末尾扫描,
//通过判断当前的current sum是比target大还是小,移动begin或者end,直到begin不小于end或者找到为止
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        size_t begin = 0;
        size_t end = nums.size() - 1;
        while (begin < end)
        {
            int currentSum = nums[begin] + nums[end];
            if (currentSum == target)
            {
                    result.push_back(nums[begin]);
                    result.push_back(nums[end]);
                    return result;
            }
            else
            {
                if (currentSum > target)
                    --end;
                else
                    ++begin;
            }
        }
        return result;
    }
};
int main() {
    vector<int> a = {12, 7, 11, 4,7456,11,2,4,55,12,2,6,657};
    Solution s;
    vector<int> result;
    result = s.twoSum(a, 13);
    cout << result.size() << endl;
    cout << result[0] << endl;
    cout << result[1];
}
