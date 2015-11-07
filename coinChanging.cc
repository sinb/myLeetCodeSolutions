#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoinChange(int money, vector<int> coins)
{
    int const n = coins.size();
    int count[money+1]; //count[p]表示组成面额为p需要的最小硬币数
    int s[money+1]; //s 是上一个使用的硬币
    count[0] = 0; s[0] = 0;
    for (int i = 1; i <= money; ++i)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            int coin = coins[j];
            if ((i - coin) < 0)
                continue;
            if (min > (count[i-coin]+1))
            {
                min = count[i-coin]+1;
                s[i] = coin;
            }
        }
        count[i] = min;
    }
    for (int i = 1; i <= money; ++i)
        cout << count[i] << " ";
    cout << endl;
    for (int i = 1; i <= money; ++i)
        cout << s[i] << " ";
    cout << endl;
    // find the coin been used in each step
    int currentLoc = money;
    int coinStep = s[currentLoc];
    while (coinStep !=0)
    {
        cout << coinStep << " ";
        currentLoc = currentLoc - coinStep;
        coinStep = s[currentLoc];
    }
    return 0;
}

int main()
{
    vector<int> coins = {1, 5, 12, 25};
    int money = 16;
    minCoinChange(money, coins);

}
