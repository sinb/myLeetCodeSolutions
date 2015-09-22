#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> num_pos;
        int shift = 0;
        //get zero's position
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                num_pos.push_back(i);
            }
        }
        // for every zero position, move
        for (size_t i = 0; i< num_pos.size(); i++)
        {
            for (int j = num_pos[i]-shift; j < nums.size(); j++)
            {
                nums[j] = nums[j+1];
            }
            shift += 1;
        }
        // fix zeros
        for (size_t i = (nums.size()-num_pos.size()); i < nums.size(); i++)
        {
            nums[i] = 0;
        }

    }
};
int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution s;
}
