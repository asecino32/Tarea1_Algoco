#include <bits/stdc++.h>
using namespace std;

#define R1 5000
#define C1 5000
#define R2 5000
#define C2 5000

//codigo base modificado de: https://www.geeksforgeeks.org/cpp-matrix-multiplication/
/*
    recibe las matrices, las multiplica y el resultado lo almacena
en una matriz diferente
*/
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


/*
    Recibe 2 matricez de arreglos, luego toma el tiempo antes y 
despues de llamar a la funcion de multiplicacion, para calcular la diferencia en milisegundos y mostrarla por pantalla
*/
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

/*
    Traspone la matriz que recibe
*/
void transponerMatriz(int** mat, int R, int C) {
    for (int i = 0; i < R; i++) {
        for (int j = i + 1; j < C; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main() {
    int** mat1 = new int*[R1];
    int** mat2 = new int*[R2];
    for (int i = 0; i < R1; i++){
        mat1[i] = new int[C1];
    }
    for (int i = 0; i < R2; i++){
        mat2[i] = new int[C2];
    }
    int N = 1;
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
        transponerMatriz(mat2, R2, C2);

        prom += tiempo(mat1, mat2);
    }
    prom /= N;
    cout << "El promedio es: "<< prom <<" ms\n";
    for (int i = 0; i < R1; i++){
        delete[] mat1[i];
    }
    for (int i = 0; i < R2; i++){
        delete[] mat2[i];
    }
    delete[] mat1;
    delete[] mat2;
    return 0;
}

