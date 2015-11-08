//最小距离两个点
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;
struct Point
{
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};
double PointDist(Point p, Point q)
{
    return pow(pow(p.x-q.x, 2) + pow(p.y-q.y, 2), 0.5);
}
double closetPairofPoints(vector<Point> pointset, int result[])
{
    double min_dist = INT_MAX;
    int n = pointset.size();
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i+1; j < n; ++j)
        {
            double dist = PointDist(pointset[i], pointset[j]);
            if (dist < min_dist)
            {
                min_dist = dist;
                result[0] = i;
                result[1] = j;
            }
        }
    }
    cout << "first is " << result[0] << endl;
    cout << "second is " << result[1] << endl;
    return min_dist;
}
int main()
{
    int n;
    double x, y;
    int result[2];
    vector<Point> pointset;
    freopen("input.txt", "r", stdin); //使用该文件作为输入
    cin >> n; //n是要输入的点的个数
    for (size_t i = 0; i < n; ++i)
    {
        cin >> x >> y;
        pointset.push_back(Point(x, y));
        cout << "x: " << pointset[i].x << "\ty: " << pointset[i].y << endl;
    }
    cout << closetPairofPoints(pointset, result);



}
