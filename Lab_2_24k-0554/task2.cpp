#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** data;
    int rows;
    int cols;

public:
    DynamicMatrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~DynamicMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillMatrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void printMatrix() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addValue(int value, int oddIndex) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (oddIndex && (i + j) % 2 == 1) {
                    data[i][j] += value;
                } else if (!oddIndex && (i + j) % 2 == 0) {
                    data[i][j] += value;
                }
            }
        }
    }

    void resizeMatrix(int newRows, int newCols) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newData[i] = new int[newCols];
        }

        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) {
                    newData[i][j] = data[i][j];
                } else {
                    newData[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        data = newData;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** newData = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newData[i] = new int[rows];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                newData[j][i] = data[i][j];
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        data = newData;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    DynamicMatrix matrix(r, c);
    matrix.fillMatrix();
    matrix.printMatrix();

    matrix.addValue(2, 1);
    cout << "After adding 2 to odd index positions:" << endl;
    matrix.printMatrix();

    matrix.transpose();
    cout << "Transposed matrix:" << endl;
    matrix.printMatrix();

    return 0;
}