#include <iostream>
#include <cmath>
using namespace std;
double squareNewton(double n) //牛顿迭代求square root
{
//    求x^2 = n,就是找出f(x) = x^2 - n的正数根.
//    假设初始猜测点为x_n,那么在x_n点f(x)斜率为f'(x_n),该点斜率也可以写成(f(x_n) - 0) / (x_n - x_n+1)
//    画出图看看,x_n+1是切线和x轴的焦点,
//    这样可以得出x_n+1和x_n的递推关系,就是 x_n+1 = 0.5*(x_n + k / x_n)
    double x = 1.0;
    while (abs(x*x - n) > 0.000001)
    {
        x = 0.5*(x + n/x);

    }
    return x;
}

double squareBL(double n) // 二分查找求square root
{
    double low = 0;
    double high = max(1.0, n); //如果n小于1那么它的root它自己大且最大是1.
    double guess = (low + high) / 2.0;
    double diff = guess*guess - n;
    int iteration = 0;
    while (fabs(diff) > 0.01 && iteration < 100)
    {
        if (diff > 0) //guess is too big
        {
            high = guess;
        }
        else
        {
            low = guess; // guess is too small
        }
        guess = (low + high) / 2;
        diff = guess*guess - n;
        iteration++;
    }
    return guess;
}
int main()
{
    cout << squareBL(0.2);
}
