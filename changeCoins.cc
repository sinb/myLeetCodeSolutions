#include <iostream>
using namespace std;
//加入有100元零钱,有1 2 5 10 四种面额硬币
//(1) 怎么换才能让总硬币数目最小? 可以直接用贪心法即可,从最大面额的开找
//贪心法优点是效率高,无需考虑面额组合,每种面额只考虑一次
//它不考虑整体最优,只考虑局部最优选择,
//但它有局限,比如{0.11, 0.05, 0.01} 来组合0.15,用贪心法就是0.11 + 4*0.01,但是实际上用0.05*3就行
//这就是为啥人民币面额是100,50,20,10,5,2,1,它不会出现上面这种贪心法出错的情况.
//也可以用动态规划
//
int changeCoin(int coins[], int n, int sum)
{
    int counts = 0;
    for (int i = 0; i < n; ++i) //对每种硬币
    {
        int num = sum / coins[i];
        sum -= coins[i] * num; //num是整数
        counts += num;
        cout << "use " << num << " " << coins[i] << " coin!" << endl;
    }
    return counts;
}
int main()
{
    int coins[] = {10, 5, 2, 1};
    changeCoin(coins, 4, 19);
}
