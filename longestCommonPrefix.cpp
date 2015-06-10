#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
// Use the first string in strs as the object to conduct compares.
// Dont have to worry about the index overflow problem because this is
// STL implementation.

// When meets a different char, stops and return
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return NULL;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if(strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
int main() {
    vector<string> a;
    a.push_back("a");
    a.push_back("ab");

    Solution s;
    string b = s.longestCommonPrefix(a);
    cout << b;

}

