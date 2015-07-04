#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxResult = -1;
        while (start < end) { // try every possible (not all actually) start and end height
            int result = min(height[start], height[end]) * (end-start);
            maxResult = max(result, maxResult);
            if (height[start] <= height[end]) { // start is lower, thus move end point don't change result area,
                ++start;                                // because only smaller height matter the result
            }
            else {
                --end;
            }
        }
        return maxResult;
    }
};
int main() {

}
