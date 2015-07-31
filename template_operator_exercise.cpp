#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/*
编程题＃1 cxsjsxmooc.openjudge.cn/test/7w6/

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB
描述

实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，使得下面程序输出结果是：

0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,

注意，只能写一个类模版，不能写多个。

#include <iostream>
using namespace std;
// 在此处补充你的代码
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
return 0;
}
*/
template <class T>
class CArray2D {
    private:
    T **mArray2D;
    public:
    CArray2D(int x, int y, int z) {
        mArray2D = new T*[x];
        for (int i=0; i < x; i++)
            mArray2D[i] = new T[y];
    }
    T* operator[] (int i) {
        return mArray2D[i];
    }
};
template <class T>
class CArray3D {

    private:
    T ***mArray3D;

    public:
    CArray3D(int x, int y, int z) {
        mArray3D = new T**[x];
        for (int i = 0; i < x; i++) {
            mArray3D[i] = new T*[y];
            for (int j = 0; j < y; j++)
                mArray3D[i][j] = new T[z];
        }
    }
    T** operator[] (int i) {
        return mArray3D[i];
    }
};
int main(){
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
