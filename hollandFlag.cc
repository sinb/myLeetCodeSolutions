#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//荷兰国旗问题是把3种颜色的球分开,就好像把数组排成0,0,0,1,1,2,2,2一样.
//还是用快排的划分想法,把数组分成3部分.
//使用3个指针,一个头,一个尾,一个current从头扫描到尾,
//碰到0就交换到前面,碰到2就交换到后面,碰到0不交换继续往后走
void hollandFlag(vector<int>& balls)
{
    int pbegin = 0, pend = balls.size()-1, pcurr = 0;
    while (pcurr < pend)
    {
        if (balls[pcurr] == 0)
        {
            swap(balls[pcurr], balls[pbegin]);
            pcurr++;
            pbegin++;
        }
        else if (balls[pcurr] == 1)
        {
            pcurr++;
        }
        else
        {
            swap(balls[pcurr], balls[pend]);
            pend--;
        }
    }
}

int main()
{
    vector<int> balls = {0, 1, 2, 1, 1, 2, 0, 2, 1, 0};
    hollandFlag(balls);
    for (size_t i = 0; i < balls.size(); ++i)
        cout << balls[i] << " ";

}
