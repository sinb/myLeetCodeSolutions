#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
//    这个算法时间o(n),空间o(1). idx 始终指向不重复的那个元素, 如果碰到重复的元素, idx就停下,只增加i往后判断,指导碰到不相同的赋给idx后的那个位置
    int removeDuplicates(vector<int>& nums) {
        size_t idx = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[idx] != nums[i])
                nums[++idx] = nums[i];
        }
        return idx + 1;
    }
//    使用STL的unique,unique返回的是指向最后一个不重复元素的迭代器,要用distance来换算成距离
    int removeDuplicatesSTL(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
//  这个是去除重复,但最多允许两次重复,想法和上面一样,idx始终记录的是最多允许两次重复的元素列表长度
//  把下面的2全部改成3就成了最多允许重复3次.
    int removeDuplicates2(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int idx = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[idx-2])
            {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {1,1,1,1,2,2,2,4,5};
    int j = s.removeDuplicates2(nums);
    for (auto i = 0; i < j; i++)
        cout << nums[i] << endl;
}
