#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
    public:
        Matrix(int row, int col): 
            row(row), col(col)
    {
        count = row * col;
        data = new T(count * sizeof(T));
    }

        Matrix(int length): 
            row(length), col(length)
    {
        count = row * col;
        data = new T(count * sizeof(T));
    }

        T* const operator[](int num) 
        {
            return &data[num * col];
        }

        Matrix& operator *(double value)
        {
            for(int y = 0; y < row; y++)
                for(int x = 0; x < col; x++)
                    data[y][x] *= value;
            return *this;

        }

        Matrix& operator *(int value)
        {
            for(int y = 0; y < row; y++)
                for(int x = 0; x < col; x++)
                    data[y][x] *= value;
            return *this;

        }

    private:
        T *data;
        int row, col;
        int count;

};


int main()
{
    Matrix<int> test(5, 6);
    cout << test[1] << endl;
    cout << test[2] << endl;
}
