#include <bits/stdc++.h>
using namespace std;

// Size of the matrices
#define N 500

// print the matrix
void print(vector<vector<int>> matrix) {
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

// sacado de: https://www.naukri.com/code360/library/strassens-matrix-multiplication
// Add two matrices and return the result
vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B, int split_index, int multiplier = 1) {
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            A[i][j] = A[i][j] + (multiplier * B[i][j]);
    return A;
}

// sacado de: https://www.naukri.com/code360/library/strassens-matrix-multiplication
vector<vector<int>> strassen_multiplication(vector<vector<int>> A, vector<vector<int>> B) {

    int col_1 = A[0].size();
    int row_1 = A.size();
    int col_2 = B[0].size();
    int row_2 = B.size();

    if (col_1 != row_2) {
        cout << "The Two Matrices cannot be multiplied";
        return {};
    }

    vector<int> result_row(col_2, 0);
    vector<vector<int>> result(row_1, result_row);

    if (col_1 == 1)
        result[0][0] = A[0][0] * B[0][0];
    else {
        int split_index = col_1 / 2;
        vector<int> row_vector(split_index, 0);

        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = A[i][j];
                a01[i][j] = A[i][j + split_index];
                a10[i][j] = A[split_index + i][j];
                a11[i][j] = A[i + split_index][j + split_index];
                b00[i][j] = B[i][j];
                b01[i][j] = B[i][j + split_index];
                b10[i][j] = B[split_index + i][j];
                b11[i][j] = B[i + split_index][j + split_index];
            }

        vector<vector<int>> p1(strassen_multiplication(a00, add(b01, b11, split_index, -1)));
        vector<vector<int>> p2(strassen_multiplication(add(a00, a01, split_index), b11));
        vector<vector<int>> p3(strassen_multiplication(add(a10, a11, split_index), b00));
        vector<vector<int>> p4(strassen_multiplication(a11, add(b10, b00, split_index, -1)));
        vector<vector<int>> p5(strassen_multiplication(add(a00, a11, split_index), add(b00, b11, split_index)));
        vector<vector<int>> p6(strassen_multiplication(add(a01, a11, split_index, -1), add(b10, b11, split_index)));
        vector<vector<int>> p7(strassen_multiplication(add(a00, a10, split_index, -1), add(b00, b01, split_index)));

        vector<vector<int>> result_00(add(add(add(p5, p4, split_index), p6, split_index), p2, split_index, -1));
        vector<vector<int>> result_01(add(p1, p2, split_index));
        vector<vector<int>> result_10(add(p3, p4, split_index));
        vector<vector<int>> result_11(add(add(add(p5, p1, split_index), p3, split_index, -1), p7, split_index, -1));

        for (auto i = 0; i < split_index; i++) {
            for (auto j = 0; j < split_index; j++) {
                result[i][j] = result_00[i][j];
                result[i][j + split_index] = result_01[i][j];
                result[split_index + i][j] = result_10[i][j];
                result[i + split_index][j + split_index] = result_11[i][j];
            }
        }
    }
    return result;
}

int main() {
    double prom=0;
    int Casos=100;
    srand(time(0));
    for(int i=0;i<Casos;i++){
        vector<vector<int>> A(N, vector<int>(N));
        vector<vector<int>> B(N, vector<int>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = rand() % N;
                B[i][j] = rand() % N; 
            }
        }

        // Printing matrices A and B
        //cout << "Matrix A:" << endl;
        //print(A);
        //cout << "Matrix B:" << endl;
        //print(B);

        using chrono::high_resolution_clock;
        using chrono::duration_cast;
        using chrono::duration;
        using chrono::milliseconds;
        auto t1 = high_resolution_clock::now();
        vector<vector<int>> result(strassen_multiplication(A, B));
        auto t2 = high_resolution_clock::now();
        duration<double, milli> ms_double = t2 - t1;
        prom += ms_double.count();
        // Printing the result
        //cout << "Resultant Matrix:" << endl;
        //print(result);
    }
    prom/=Casos;
    cout<<"el tiempo promedio para las matricez de "<<N<<"x"<<N<<" fue: "<<prom<<" ms\n";
    return 0;
}
