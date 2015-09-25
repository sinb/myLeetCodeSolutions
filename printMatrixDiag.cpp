#include <iostream>
using namespace std;
template <size_t n>
//从右上开始
void printMatrixDiagUpRight(int arr[][n])
{
    for (int j = n; j > 0; j--)
    {
        int shift = 0;
        for (int i = 0; i < n-j+1; i++)
        {
            cout <<arr[i][j-1+shift] << endl;
            shift++;
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        int row = i;
        int shift = i;
        for (int j = 0; j < n-i; j++)
        {
            cout << arr[row+j][row+j-shift] << endl;
        }
        cout << endl;
    }
}
int main()
{
    const int n = 5;
    int a[][n] = {{1,2,3,4,5}, {6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}, {21,22,23,24,25} };
    printMatrixDiagUpRight(a);

}
