#include <iostream>
#include <random>
#include <climits>
#include <chrono>
#include <thread>
using namespace std;
int randIntRange(int min, int max)
{
    //need to set random seed first
    return min + (rand() % (int)(max - min + 1));
}
int randomInt5()
{
    return randIntRange(1, 5);
}
int randomInt7()
{
    // using randomInt 5 to generate uniformly 1-7
    //first get randomInt25
    int x = INT_MAX;
    while (x > 21) //21是接近25但不超过25的7的倍数，可以用7*(25/7)计算得到
    {
        x = 5 * (randomInt5() - 1) + randomInt5(); // 1-25
    }
    return x%7 + 1;
}
int main()
{
    srand(time(NULL));
    while (1)
    {
        cout << randomInt7() << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
