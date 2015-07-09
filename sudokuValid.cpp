#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
//分别对9行,9列,9个小块进行判断
//判断方法是看是否出现重复数字
//重复数字判断方法是用类似hash表的方法,因为这里是数字所以用的是一个一维数组
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
        bool row_true = oneRow(board[i]);
        bool col_true = oneCol(board, i);
        if (!row_true || !col_true)
                return false;
        }
        for (int i = 1; i < 8; i+=3) {
            for (int j = 1; j < 8; j+=3) {
                if (!oneBlock(board, i, j))
                    return false;
            }
        }
        return true;
    }
    bool oneRow(vector<char> row) {
        int counts[9] = {0};
        for (int i = 0; i < 9; i++) {
            if (row[i] == '.')
                continue;
            counts[row[i] - '0' - 1] += 1;
            if (counts[row[i] - '0' - 1] > 1)
                return false;
        }
        return true;
    }
    bool oneCol(vector<vector<char>> board, int colIdx) {
        int counts[9] = {0};
        for (int i = 0; i < 9; i++) {
            if (board[i][colIdx] == '.')
                continue;
            counts[board[i][colIdx] - '0' - 1] += 1;
            if (counts[board[i][colIdx] - '0' - 1] > 1)
                return false;
        }
        return true;
    }
    bool oneBlock(vector<vector<char>> board, int row, int col) {
        int counts[9] = {0};
        for (int i = row-1; i <= row+1; i++) {
            for (int j = col-1; j <= col+1; j++) {
                if (board[i][j] == '.')
                    continue;
                counts[board[i][j] - '0' - 1] += 1;
                if (counts[board[i][j] - '0' - 1] > 1)
                    return false;
            }
        }
        return true;
    }
};
int main() {

    vector<char> row1 = {'.', '.', '4', '.', '.', '.', '6', '3', '.'};
    vector<char> row2 = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> row3 = {'5', '.', '.', '.', '.', '.', '.', '9', '.'};
    vector<char> row4 = {'.', '.', '.', '5', '6', '.', '.', '.', '.'};
    vector<char> row5 = {'4', '.', '3', '.', '.', '.', '.', '.', '1'};
    vector<char> row6 = {'.', '.', '.', '7', '.', '.', '.', '.', '.'};
    vector<char> row7 = {'.', '.', '.', '5', '.', '.', '.', '.', '.'};
    vector<char> row8 = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> row9 = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<vector<char>> board;
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    board.push_back(row7);
    board.push_back(row8);
    board.push_back(row9);
    Solution s;
    bool a = s.isValidSudoku(board);
    cout << a;
}

