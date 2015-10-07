#include <iostream>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int counter[256] = {0};
        if (s.size() != t.size())
            return false;
        for (auto c: s)
            if (counter[int(c)] == 0)
                counter[int(c)] = 1;
            else
                counter[int(c)] += 1;
        for (auto c: t)
            if (counter[int(c)] != 0)
                counter[int(c)] -= 1;
            else
                return false;

        return true;
    }
};

int main()
{
    Solution s;
    s.isAnagram("asd","das");
}
