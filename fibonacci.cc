#include <iostream>
#include <string>
using namespace std;
// get the n th number in fibonacci array, 1, 2, 3, 5,.....
int fibonacci(int n)
{
    int result[2] = {1, 2};
    if (n < 1)
        return 0;
    if (n <= 2)
    {
        return result[n-1];
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
// get the n th number in fibonacci array, 1, 2, 3, 5....not using recursion
int fibonacciIter(int n)
{
    int result[3] = {1,2,3};
    if (n < 1)
    {
        return 0;
    }
    if (n < 3)
    {
        return result[n - 1];
    }
    for (int i = 2;i < n; i++)
    {
        result[2] = result[1] + result[0];
        result[0] = result[1];
        result[1] = result[2];
    }
    return result[2];
}
// pirint fibonacci array
void printFibonacciIter(int n)
{
    int result[3] = {1,2,3};
    if (n < 1)
    {
        return;
    }
    if (n < 3)
    {
        cout << result[n - 1];
    }
    for (int i = 2;i < n; i++)
    {
        cout << result[2] << "\t";
        result[2] = result[1] + result[0];
        result[0] = result[1];
        result[1] = result[2];
    }
    return;
}
int main()
{
//    for (int i = 1; i < 30; i++)
//        cout << fibonacci(i) << "\t";
    for (int i = 1; i <= 30; i++)
        cout << fibonacci(i) << "\t";
}
