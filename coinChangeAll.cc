#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// 计算所有组合个数,不计算每种组合使用的硬币具体是啥.
int coinChangeAll(vector<int> coins, int sum)
{
    int n = coins.size(); // number of coins
    int T[n][sum+1];
    for (size_t i = 0; i < n; ++i)
        T[i][0] = 1; // 初始化第一列全为1
    for (size_t i = 0; i <= sum; ++i)
        T[0][i] = 1; //初始化第一行全为1, 参考影像笔记动态规划硬币里那张图
    for (size_t i = 1; i < n; ++i)
    {
        for (size_t j = 1; j <= sum; ++j)
        {
            if (j >= coins[i]) // 当前要组成j元,比当前这个硬币面额大,所以当前这个硬币能用上
            {
                T[i][j] = T[i-1][j] + T[i][j - coins[i]]; //第二项就是考虑当前硬币coins[i]了
            }
            else
            {
                T[i][j] = T[i-1][j];
            }
        }
    }
//    for (size_t i = 0; i < n; ++i)
//    {
//        for (size_t j = 0; j <= sum; ++j)
//            cout << T[i][j] << "\t";
//        cout << endl;
//    }

    return T[n-1][sum];
}
int main()
{
    vector<int> coins = {1,2,5,10};
    int sum = 1000;
    cout << coinChangeAll(coins, sum);
}
