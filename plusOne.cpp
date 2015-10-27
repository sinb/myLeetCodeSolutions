#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
//        int const size = digits.size();
//        bool carry[size];
//
//        bool allCarry = true;
//        for (int i = 0; i < digits.size()-1; i++) {
//            if (digits[i+1] == 9)
//                carry[i] = true;
//            else
//                carry[i] = false;
//        }
//        if (digits[size-1] == 9) //handle last digit
//            carry[size-1] = true;
//        else
//            carry[size-1] = false;
//        for (int i = 0; i < digits.size(); i++) {
//            if (!carry[i])
//                allCarry = false;
//        }
//
//        if
//
//
    }
    long digits2int(vector<int>& digits) {
        long result = 0;
        for (int i = 0; i < digits.size(); i++)
            result += digits[i] * pow(10, digits.size()-1-i);
        return result;
    }
};
int main() {
    Solution s;
    vector<int> digits = {8, 7, 9, 5, 0};
//    s.plusOne(digits);
    cout << s.digits2int(digits);
    int a[5] = {};

    for (int i = 0; i < 5; i++) {
        cout << endl << a[i];
    }

}

