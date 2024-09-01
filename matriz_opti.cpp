#include <bits/stdc++.h>
using namespace std;

#define R1 1000
#define C1 1000
#define R2 1000
#define C2 1000

//codigo base modificado de: https://www.geeksforgeeks.org/cpp-matrix-multiplication/
void mulMat(int** mat1, int** mat2T) {
    int** rslt = new int*[R1];
    for (int i = 0; i < R1; i++) {
        rslt[i] = new int[C2];
    }

    // Multiplicación de matrices
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2T[j][k];
            }
        }
    }

    for (int i = 0; i < R1; i++) {
        delete[] rslt[i];
    }
    delete[] rslt;
}

double tiempo(int** mat1, int** mat2T) {
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    mulMat(mat1, mat2T);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    return ms_double.count();
}

int main() {
    int** mat1 = new int*[R1];
    int** mat2 = new int*[R2];
    int** mat2T = new int*[C2];

    for (int i = 0; i < R1; i++){
        mat1[i] = new int[C1];
        }
    for (int i = 0; i < R2; i++){
        mat2[i] = new int[C2];
    }
    for (int i = 0; i < C2; i++){
        mat2T[i] = new int[R2];
    }

    int N = 10;
    double prom = 0;
    srand(time(0));
    for (int z = 0; z < N; z++) {
        for (int i = 0; i < R1; i++) {
            for (int j = 0; j < C1; j++) {
                mat1[i][j] = rand() % (R1 + C1);
            }
        }
        for (int i = 0; i < R2; i++) {
            for (int j = 0; j < C2; j++) {
                mat2[i][j] = rand() % (R2 + C2);
            }
        }
        for (int i = 0; i < C2; i++) {
            for (int j = 0; j < R2; j++) {
                mat2T[i][j] = mat2[j][i];
            }
        }
        prom += tiempo(mat1, mat2T);
    }
    prom /= N;
    cout << "el promedio es: "<< prom <<" ms\n";

    for (int i = 0; i < R1; i++){
        delete[] mat1[i];
    }
    for (int i = 0; i < R2; i++){
        delete[] mat2[i];
    }
    for (int i = 0; i < C2; i++){
        delete[] mat2T[i];
    }

    delete[] mat1;
    delete[] mat2;
    delete[] mat2T;

    return 0;
}
