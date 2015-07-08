#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        while (n > 1) {
            if (!(n%2)) {
                n = n / 2;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    cout << s.isPowerOfTwo(16);
}
