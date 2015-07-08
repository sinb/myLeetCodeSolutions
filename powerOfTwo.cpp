#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
    // just divide 2 to see if n%2 == 0
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
    bool isPowerOfTwo2(int n) {
    // use bit operation, number that is power of 2 only has one bit 1, like 8 = 0000 1000
        if (n < 1)
            return false;
        int sum = 0;
        int i = 0;

        for (i = 0; i < sizeof(n)*8 && sum <=1; ++i) {
            sum += ((n >> i) & 1);
        }
        if (i < sizeof(n)*8)
            return false;
        else
            return true;
    }
};
int main() {
    Solution s;
    cout << s.isPowerOfTwo2(33) << endl;
//    int number = 8;
//    number |= 1 << 1;
//    cout << number << endl;
//    int bit;
//    bit = (number >> 0) & 1;
//    cout << bit << endl;
//    cout << sizeof(number) << endl;
}
