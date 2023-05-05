#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

void matrixMultiplicationAndPrint() {
    int rowsA, colsA;
    cout << "Please enter the dimensions of the first matrix: ";
    cin >> rowsA >> colsA;
    int rowsB, colsB;
    cout << "Please enter the dimensions of the second matrix: ";
    cin >> rowsB >> colsB;
    vector<vector<int>> A(rowsA, vector<int>(colsA));
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    if (colsA != rowsB) {
        cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        cout << "Multiplication cannot be performed."<<endl;
        return;
    } else {
        cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed." <<endl;
    }
    cout << "Please enter the numbers for the first matrix."<<endl;
    for (int i = 0; i < rowsA; i++) {
        cout<<"Enter the numbers for row #"<<i+1<<": ";
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }
    cout << "The first matrix is:\n";
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout<<endl;
    
    
    cout << "Please enter the numbers for the second matrix."<<endl;
    for (int i = 0; i < rowsB; i++) {
        cout<<"Enter the numbers for row #"<<i+1<<": ";
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }
    cout << "The second matrix is:\n";
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    
    
    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));
    
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    cout<<endl;
    cout << "Result of the Multiplication Operation:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void transposeMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    int transpose[MAX_SIZE][MAX_SIZE];
    
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    
    cout << "Result of the Transpose Operation:\n";
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << "\n";
    }
    cout<<endl;
}


void matrix_addition() {
    int m, n, p, q;
    
    cout << "Please enter the dimensions of the first matrix: ";
    cin >> m >> n;
    
    cout << "Please enter the dimensions of the second matrix: ";
    cin >> p >> q;
    
    if (m != p || n != q) {
        cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
        return;
    }
    
    cout << "The two matrices have the same dimensions. Addition can be performed." << endl;
    cout<<endl;
    vector<vector<int>> matrix1(m, vector<int>(n));
    vector<vector<int>> matrix2(p, vector<int>(q));
    
    cout << "Please enter the numbers for the first matrix." << endl;
    for (int i = 0; i < m; i++) {
        cout << "Enter the numbers for row #" << i+1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }
    
    cout << "The first matrix is: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Please enter the numbers for the second matrix." << endl;
    for (int i = 0; i < p; i++) {
        cout << "Enter the numbers for row #" << i+1 << ": ";
        for (int j = 0; j < q; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    cout << "The second matrix is: " << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout << endl;
    cout << "Result of the Sum Operation: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}


void powerOperation() {
    int rows, cols, power;
    cout << "Please enter the dimensions of the matrix: ";
    cin >> rows >> cols;
    if (rows != cols) {
        cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << endl;
        
        cout<<endl;
        return;
    }
    cout << "The matrix has the same number of rows as columns. Power can be performed." << endl;
    
    cout<<endl;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Please enter the numbers for the matrix." << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Enter the numbers for row #" << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "The matrix is: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
    
    cout << "Please enter the power: ";
    cin >> power;
    
    
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    for (int p = 1; p <= power; p++) {
        if (p == 1) {
            result = matrix;
        } else {
            vector<vector<int>> temp(rows, vector<int>(cols, 0));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    for (int k = 0; k < cols; k++) {
                        temp[i][j] += result[i][k] * matrix[k][j];
                    }
                }
            }
            result = temp;
        }
    }
    
    
    cout << "Result of the Power Operation:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



int main() {
    int choice,rows,cols;
    int matrix[MAX_SIZE][MAX_SIZE];
    do {
        cout<<"Pick a choice from the list: "<<endl;
        cout<<"1- Addition Operation"<<endl;
        cout<<"2- Multiplication Operation"<<endl;
        cout<<"3- Power Operation"<<endl;
        cout<<"4- Transpose Operation"<<endl;
        cout<<"5- Exit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        cout<<endl;
        if (choice == 1) {
            matrix_addition();
        } else if (choice == 2) {
            matrixMultiplicationAndPrint();
        } else if (choice == 3) {
            powerOperation();
        } else if (choice == 4) {
            cout << "Please enter the dimensions of the matrix: ";
            cin >> rows >> cols;
            cout << "Please enter the numbers for the matrix.\n";
            for (int i = 0; i < rows; ++i) {
                cout << "Enter the numbers for row #" << i+1 << ": ";
                for (int j = 0; j < cols; ++j) {
                    cin >> matrix[i][j];
                }
            }
            cout << "The matrix is:\n";
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cout << matrix[i][j] << " ";
                }
                cout << "\n";
            }
            cout<<endl;
            transposeMatrix(matrix, rows, cols);
            
        }
        
    } while(choice != 5);
    
    
    
    

    return 0;
}

