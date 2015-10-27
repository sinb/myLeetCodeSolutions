#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
