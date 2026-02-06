#include <iostream>
using namespace std;

class Matrix {
public:
    int** data;
    int rows, cols;

    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
        }
    }

    void freeUp() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    void resize(int newR, int newC, int fillVal = 0) {
        int** newData = new int*[newR];
        for (int i = 0; i < newR; i++) {
            newData[i] = new int[newC];
            for (int j = 0; j < newC; j++) {
                if (i < rows && j < cols)
                    newData[i][j] = data[i][j];
                else
                    newData[i][j] = fillVal;
            }
        }
        freeUp();
        data = newData;
        rows = newR;
        cols = newC;
    }

    void transpose() {
        int** temp = new int*[cols];
        for (int i = 0; i < cols; i++) {
            temp[i] = new int[rows];
            for (int j = 0; j < rows; j++)
                temp[i][j] = data[j][i];
        }
        freeUp();
        int tmp = rows;
        rows = cols;
        cols = tmp;
        data = temp;
    }

    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i * cols + j) % 2 != 0)
                    cout << data[i][j] + 2 << " ";
                else
                    cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        freeUp();
    }
};

int main() {
    int r, c;
    cout << "enter rows and cols: ";
    cin >> r >> c;

    Matrix mat(r, c);

    cout << "enter matrix values:" << endl;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat.data[i][j];

    cout << "\noriginal matrix:" << endl;
    mat.printMatrix();

    int newR, newC, fillVal;
    cout << "\nnew rows, cols, fill value: ";
    cin >> newR >> newC >> fillVal;
    mat.resize(newR, newC, fillVal);
    cout << "after resize:" << endl;
    mat.printMatrix();

    mat.transpose();
    cout << "\nafter transpose (odd index +2 shown):" << endl;
    mat.printMatrix();

    return 0;
}
