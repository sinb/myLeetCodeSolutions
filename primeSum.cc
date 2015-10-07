#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    // 埃氏筛选法计算素数,这个不知道为什么C++提交不过去,改成C, int *counter = malloc(n*sizeof(int))就能过
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        int *counter = new int[n]; // 1,2,3,4,5.....n
        int c = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            //2*2, 2*3, ...2*5
            //这些数不是素数
            int times = i;
            while (i * times < n)
            {
                counter[i*times - 1] = 1;
                times += 1;
            }
        }
        for (int i = 1; i < n-1; i++)
        {
            if (counter[i])
            {
                ;
            }

            else
            {
                //cout << i+1 << " is prime " << endl;
                c += 1;
                //这里计算素数的个数
                // 也可以计算素数求和
            }
        }
        return c;
    }
};
int main()
{
    Solution s;
    int a = s.countPrimes(3);
    cout << a << endl;
}
