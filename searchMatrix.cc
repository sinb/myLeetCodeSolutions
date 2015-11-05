#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        int i = 0;
        int j = COL-1;
        int val = matrix[i][j]; // upper-right value
        while (true)
        {
            if (val == target)
                return true;
            else if (val > target && j > 0)
            {
                val = matrix[i][--j]; // val is too large, move left
            }
            else if (val < target && i < ROW-1)
            {
                val = matrix[++i][j]; // val is too small, move down
            }
            else
                return false;
        }
    }
    //递归， 很慢
    bool searchMatrixRecur(vector<vector<int>>& matrix, int target) {

        return searchMatrixRecurHelper(matrix, 0, 0, target);

    }
    bool searchMatrixRecurHelper(vector<vector<int>>& matrix, int r, int c, int target)
    {
        if ((r == matrix.size()) || (c == matrix[0].size()))
            return false;
        if (target < matrix[r][c])
            return false;
        if (target == matrix[r][c])
            return true;
        else
        {
            return searchMatrixRecurHelper(matrix, r+1, c, target) || searchMatrixRecurHelper(matrix, r, c+1, target);;
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,7,9}};
    Solution s;
    cout << s.searchMatrix(matrix, 5);
}
