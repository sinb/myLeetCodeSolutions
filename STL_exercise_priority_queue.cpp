/*
编程题＃6： priority queue练习题

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 2500ms 内存限制: 131072kB
描述

我们定义一个正整数a比正整数b优先的含义是：

*a的质因数数目（不包括自身）比b的质因数数目多；

*当两者质因数数目相等时，数值较大者优先级高。

现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。
输入

第一行: num (添加元素次数，num <= 30)

下面10*num行，每行一个正整数n（n < 10000000).
输出

每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。
样例输入

1
10 7 66 4 5 30 91 100 8 9

样例输出

66 5
*/
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
bool isPrime(int n)
{
    if (n < 2)
        return false;
    int i = 2;
    while (i < n) {
        if (!(n % i))
            return false;
        i++;
    }
    return true;
}
vector<int> findPrime(int n)
{
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
            result.push_back(i);
    }
    return result;
}
vector<int> primeFactorization(int n)
{
    vector<int> primeFactorLst = findPrime(n);
    vector<int> result;
    vector<int>::const_iterator i = primeFactorLst.begin();
    while (i != primeFactorLst.end())
    {
        if (!(n % (*i))) //*i is a factor
        {
            result.push_back(*i);
            n = n /(*i);
        }
        else
        {
            ++i; // move to next factor
        }
    }
    return result;
}
class MyLess
{
    public:
    bool operator() (int n1, int n2)
    {
        int num_factor_n1 = primeFactorization(n1).size();
        int num_factor_n2 = primeFactorization(n2).size();
        if (num_factor_n1 < num_factor_n2)
            return true;
        else if (num_factor_n1 == num_factor_n2)
        {
            if (n1 < n2)
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }


    }
};
class MyGreater
{
    public:
    bool operator() (int n1, int n2)
    {
        int num_factor_n1 = primeFactorization(n1).size();
        int num_factor_n2 = primeFactorization(n2).size();
        if (num_factor_n1 < num_factor_n2)
            return false;
        else if (num_factor_n1 == num_factor_n2)
        {
            if (n1 < n2)
                return false;
            else
                return true;
        }
        else
        {
            return true;
        }


    }
};
int main()
{
    ifstream in("in.txt", ios::in);
    int num;
    in >> num;
    priority_queue<int, vector<int>, MyLess> pq;
    priority_queue<int, vector<int>, MyGreater> pqr;
    while (num-- )
    {
        int i = 10;
        while ( i > 0)
        {
            int int_num;
            in >> int_num;
            pq.push(int_num);
            pqr.push(int_num);
            i--;
        }
    }
    cout << pq.top() << " ";
    cout << pqr.top() << endl;
    return 0;
}
