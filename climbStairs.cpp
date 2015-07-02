#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int climbStairs_Fib(int n) {
        int result[2] = {1, 2};
        if (n <= 2 ) {
            return result[n-1];
        }
        return (climbStairs(n-1) + climbStairs(n-2));
    }
    int climbStairs(int n) {
        int fib[3] = {1, 1, 1}; //1,1,2,3,5,8....
        if (n < 2 ) {
            return 1;
        }
        for (int i = 2; i <= n; i++) { // first fib[2] will be item 2 in fib array
            fib[2] = fib[1] + fib[0];
            fib[0] = fib[1]; //move, to calculate item 3 in fib array
            fib[1] = fib[2]; //same as above

        }
        return fib[2];

    }
};
int main() {
    //1. n级楼梯,可以一次上一步也可以上两部,那么n级有几种上法
    //假设n级楼梯有f(n)中上法,那么f(1)=1,因为只能上1级,f(2)=2,因为有两种选择
    //一次上两级或者两次上一级.其他的f(n)可以这样看,如果当前选择上1级,那就剩下f(n-1)中走法,
    //因为剩下了n-1级台阶.如果选择上2级,那就剩下f(n-2)种走法.于是f(n) = f(n-1) + f(n-2),fibonacci数列.
    ////////////////////////////////////////////
    //2. fib数列除了用递归还可以用迭代去做,思路是,对于一个n,从头开始迭代计算f(2),f(3),f(4),f(5).....
    ////////////////////////////
    //3. 直接用fibonacci的通项公式最快时间空间都是O(1)

}
