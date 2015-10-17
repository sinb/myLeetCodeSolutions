#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;
//寻找哪天卖股票最好
//还是贪心法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int min_price = INT_MAX, max_profit = INT_MIN;
        for (int i = 0; i < prices.size(); ++i)
        {
            min_price = min(prices[i], min_price);//始终是最小价格
            max_profit = max(prices[i]-min_price, max_profit);//哪一天价格高,prices-min_price就会大
        }
        return max_profit;
    }
};

int main()
{
}
