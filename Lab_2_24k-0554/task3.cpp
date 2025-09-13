#include <iostream>
using namespace std;

class JaggedArray {
private:
    int** data;
    int* rowSizes;
    int numRows;

public:
    JaggedArray(int rows) {
        numRows = rows;
        data = new int*[numRows];
        rowSizes = new int[numRows];
        
        for (int i = 0; i < numRows; i++) {
            data[i] = nullptr;
            rowSizes[i] = 0;
        }
    }

    ~JaggedArray() {
        for (int i = 0; i < numRows; i++) {
            if (data[i] != nullptr) {
                delete[] data[i];
            }
        }
        delete[] data;
        delete[] rowSizes;
    }

    void createRow(int rowIndex, int size) {
        if (rowIndex >= 0 && rowIndex < numRows) {
            if (data[rowIndex] != nullptr) {
                delete[] data[rowIndex];
            }
            data[rowIndex] = new int[size];
            rowSizes[rowIndex] = size;
        }
    }

    void fillRow(int rowIndex) {
        if (rowIndex >= 0 && rowIndex < numRows && data[rowIndex] != nullptr) {
            cout << "Enter " << rowSizes[rowIndex] << " values for row " << rowIndex << ": ";
            for (int j = 0; j < rowSizes[rowIndex]; j++) {
                cin >> data[rowIndex][j];
            }
        }
    }

    void printArray() {
        cout << "Jagged Array:" << endl;
        for (int i = 0; i < numRows; i++) {
            cout << "Row " << i << ": ";
            if (data[i] != nullptr) {
                for (int j = 0; j < rowSizes[i]; j++) {
                    cout << data[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    void displayRowSums() {
        cout << "Sum of elements in each row:" << endl;
        for (int i = 0; i < numRows; i++) {
            int sum = 0;
            if (data[i] != nullptr) {
                for (int j = 0; j < rowSizes[i]; j++) {
                    sum += data[i][j];
                }
            }
            cout << "Row " << i << " sum: " << sum << endl;
        }
    }

    int getRowSize(int rowIndex) {
        if (rowIndex >= 0 && rowIndex < numRows) {
            return rowSizes[rowIndex];
        }
        return 0;
    }

    int getNumRows() const {
        return numRows;
    }
};

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    JaggedArray jaggedArr(rows);

    for (int i = 0; i < rows; i++) {
        int size;
        cout << "Enter size for row " << i << ": ";
        cin >> size;
        jaggedArr.createRow(i, size);
        jaggedArr.fillRow(i);
    }

    jaggedArr.printArray();
    jaggedArr.displayRowSums();

    return 0;
}