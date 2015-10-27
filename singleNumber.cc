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
            cout << x << endl;
        }
        return x;

    }
};
int main()
{
    Solution s;
    vector<int> a = {77,2,44,11,11,2,77,1,44};
    s.singleNumber(a);

}
