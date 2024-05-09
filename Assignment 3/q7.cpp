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
        if (rows != cols)
        {
            throw invalid_argument("Matrix must be square for inversion");
        }

        size_t n = rows;
        Matrix identity(n, n, vector<vector<T>>(n, vector<T>(n)));
        for (size_t i = 0; i < n; ++i)
        {
            identity.data[i][i] = 1;
        }

        Matrix result(*this);

        for (size_t i = 0; i < n; ++i)
        {
            size_t pivot_row = i;
            for (size_t j = i + 1; j < n; ++j)
            {
                if (abs(result.data[j][i]) > abs(result.data[pivot_row][i]))
                {
                    pivot_row = j;
                }
            }

            if (pivot_row != i)
            {
                swap(result.data[i], result.data[pivot_row]);
                swap(identity.data[i], identity.data[pivot_row]);
            }

            for (size_t j = i + 1; j < n; ++j)
            {
                T factor = result.data[j][i] / result.data[i][i];
                for (size_t k = 0; k < n; ++k)
                {
                    result.data[j][k] -= factor * result.data[i][k];
                    identity.data[j][k] -= factor * identity.data[i][k];
                }
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                T factor = result.data[j][i] / result.data[i][i];
                for (size_t k = 0; k < n; ++k)
                {
                    identity.data[j][k] -= factor * identity.data[i][k];
                }
            }
        }

        for (size_t i = 0; i < n; ++i)
        {
            T divisor = result.data[i][i];
            for (size_t j = 0; j < n; ++j)
            {
                result.data[i][j] /= divisor;
                identity.data[i][j] /= divisor;
            }
        }

        return identity;
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
    Matrix<double> matrix1(2, 2, {{2, 3}, {1, 4}});
    Matrix<double> inverse_matrix = matrix1.Inverse();

    cout << "Original Matrix:" << endl;
    matrix1.Display();

    cout << "Inverse Matrix:" << endl;
    inverse_matrix.Display();

    return 0;
}
