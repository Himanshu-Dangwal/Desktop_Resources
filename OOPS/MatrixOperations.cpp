#include <bits/stdc++.h>
using namespace std;

class Matrix
{
protected:
    int size;
    int matrix[10][10];

public:
    Matrix(int n) : size(n) {}

    // Member function to set matrix values
    void setMatrixValue(int i, int j, int value)
    {
        if (i < size && j < size)
        {
            matrix[i][j] = value;
        }
    }

    int getMatrixValue(int i, int j)
    {
        return matrix[i][j];
    }
    // Member function to display the matrix
    void displayMatrix()
    {

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class ScalarMatrix : public Matrix
{
private:
    int scalar;

public:
    ScalarMatrix(int n, int s) : Matrix(n), scalar(s) {}

    // Member function to multiply matrix by scalar
    void multiplyByScalar()
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] *= scalar;
            }
        }
    }
};

int main()
{
    // Input the size of the matrix
    int n;

    std::cin >> n;

    // Create Matrix object
    Matrix myMatrix(n);

    // Input the matrix elements

    int value;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> value;
            myMatrix.setMatrixValue(i, j, value);
        }
    }

    // Input the scalar value
    int scalar;
    std::cin >> scalar;

    // Create ScalarMatrix object
    ScalarMatrix myScalarMatrix(n, scalar);

    // Display original matrix
    myMatrix.displayMatrix();

    // Copy original matrix to ScalarMatrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            myScalarMatrix.setMatrixValue(i, j, myMatrix.getMatrixValue(i, j));
        }
    }

    // Multiply matrix by scalar
    myScalarMatrix.multiplyByScalar();

    // Display resultant matrix
    myScalarMatrix.displayMatrix();

    return 0;
}
