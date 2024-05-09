#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Matrix
{
private:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix() : rows(0), cols(0) {}
    Matrix(size_t numRows, size_t numCols, const vector<vector<T>> &matrixData)
        : rows(numRows), cols(numCols), data(matrixData)
    {
        if (data.size() != numRows || (numCols > 0 && data[0].size() != numCols))
        {
            throw invalid_argument("Invalid matrix dimensions");
        }
    }
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(other.data) {}
    Matrix operator+(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw invalid_argument("Matrices must have the same dimensions for addition");
        }
        Matrix result(rows, cols, vector<vector<T>>(rows, vector<T>(cols)));
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            throw invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication");
        }
        Matrix result(rows, other.cols, vector<vector<T>>(rows, vector<T>(other.cols)));
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < other.cols; ++j)
            {
                for (size_t k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    bool operator==(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            return false;
        }
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                if (data[i][j] != other.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Matrix Transpose() const
    {
        Matrix result(cols, rows, vector<vector<T>>(cols, vector<T>(rows)));
        for (size_t i = 0; i < cols; ++i)
        {
            for (size_t j = 0; j < rows; ++j)
            {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }
    Matrix SubMatrix(size_t startRow, size_t startCol, size_t numRows, size_t numCols) const
    {
        if (startRow + numRows > rows || startCol + numCols > cols)
        {
            throw invalid_argument("Invalid sub-matrix dimensions or start position");
        }
        Matrix result(numRows, numCols, vector<vector<T>>(numRows, vector<T>(numCols)));
        for (size_t i = 0; i < numRows; ++i)
        {
            for (size_t j = 0; j < numCols; ++j)
            {
                result.data[i][j] = data[startRow + i][startCol + j];
            }
        }
        return result;
    }
    Matrix Inverse() const
    {
        throw logic_error("Inverse operation not implemented");
    }
    void Display() const
    {
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix<int> matrix1(2, 3, {{1, 2, 3}, {4, 5, 6}});
    Matrix<int> matrix2(2, 3, {{7, 8, 9}, {10, 11, 12}});
    Matrix<int> matrix3(3, 2, {{1, 2}, {3, 4}, {5, 6}});

    cout << "Matrix 1:" << endl;
    matrix1.Display();
    cout << "Matrix 2:" << endl;
    matrix2.Display();
    cout << "Matrix 3:" << endl;
    matrix3.Display();

    cout << "Addition of Matrix 1 and Matrix 2:" << endl;
    (matrix1 + matrix2).Display();

    cout << "Multiplication of Matrix 1 and Matrix 3:" << endl;
    (matrix1 * matrix3).Display();

    cout << "Are Matrix 1 and Matrix 2 equal: " << (matrix1 == matrix2 ? "Yes" : "No") << endl;

    cout << "Transpose of Matrix 3:" << endl;
    matrix3.Transpose().Display();

    cout << "Sub-matrix of Matrix 1:" << endl;
    matrix1.SubMatrix(0, 1, 2, 2).Display();

    return 0;
}
