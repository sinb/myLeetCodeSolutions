/**
 * Created by ningbo.si on 2016/6/20.
 [1][2][3][4]
 [5][6][7][8]
 [9][0][1][2]
 [3][4][5][6]
 Becomes:
 [3][9][5][1]
 [4][0][6][2]
 [5][1][7][3]
 [6][2][8][4]
 顺时针旋转矩阵90度（不是转置！）
 方法是分层来旋转，看这张图 https://github.com/sinb/myLeetCodeSolutions/blob/master/RotateMatrixIterations.png
 同时进行4个数值的交换（旋转）
 */
public class rotateMatrix {
    public static void printMatrix(int[][] matrix, int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                System.out.printf("%d\t", matrix[i][j]);
            }
            System.out.println();
        }
    }
    public static void rotate(int[][] matrix, int N)
    {
        for (int layer = 0; layer < N/2; ++layer)
        {
            for (int col = layer; col < N-layer-1; ++col)
            {
                int save = matrix[layer][col];
                matrix[layer][col] = matrix[N-1-col][layer];
                matrix[N-1-col][layer] = matrix[N-1-layer][N-1-col];
                matrix[N-1-layer][N-1-col] = matrix[col][N-1-layer];
                matrix[col][N-1-layer] = save;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
        rotate(matrix, 5);
        printMatrix(matrix, 5, 5);
    }
}
