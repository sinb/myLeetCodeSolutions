//============================================================================
// Name        : leetcode.cpp
// Author      : hehe
// Version     :
// Copyright   : Your copyright notice
// Description : summaryRanges,分段比较,判断的琐碎了一点,时间复杂度O(n)
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> sum;
    	if (nums.size() == 0) {
        	return sum;
        }
    	if (nums.size() == 1) {
    		sum.push_back(to_string(nums[0]));
    		return sum;
        }

    	int start_idx = 0;
        while (start_idx < nums.size()) {
        	int range = 1;
        	if (start_idx == nums.size()-1) { //time to finish
        		sum.push_back(to_string(nums[start_idx]));
        		break;
        	}
            for (int i = 0; i < nums.size() - start_idx; i++) {
                if (nums[start_idx+i+1] - nums[start_idx+i] == 1) {
                    range += 1;
                }
                else {
                    if (range == 1) { //only one number
                        sum.push_back(to_string(nums[start_idx]));
                    }
                    else {
                        sum.push_back(to_string(nums[start_idx]) + "\->" + to_string(nums[start_idx+range-1]));
                	}

                    start_idx += range;
                    break;
                }
            }
        }
        return sum;
    }
};


int main() {
    vector<int> nums = {0, 1, 2, 5, 6, 7, -1, 0};
    vector<string> sum;



    Solution solution;
    sum = solution.summaryRanges(nums);

    for(int i = 0; i < sum.size(); i++) {
        cout << sum[i]<<endl;
    }
    return 0;
}
