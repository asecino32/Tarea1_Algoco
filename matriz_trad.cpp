#include <bits/stdc++.h>
using namespace std;

// Edit MACROs here, according to your Matrix Dimensions for
// mat1[R1][C1] and mat2[R2][C2]
#define R1 5000 // number of rows in Matrix-1
#define C1 5000 // number of columns in Matrix-1
#define R2 5000 // number of rows in Matrix-2
#define C2 5000 // number of columns in Matrix-2

//codigo obtenido de: https://www.geeksforgeeks.org/cpp-matrix-multiplication/
//se le modifico la memoria dinamica en la funcion multMat
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
                rslt[i][j] += mat1[i][k] * mat2T[k][j];
            }
        }
    }

    for (int i = 0; i < R1; i++) {
        delete[] rslt[i];
    }
    delete[] rslt;
}

/*
    Recibe 2 matricez de arreglos con la dimension constante de sus columnas, luego toma el tiempo antes y 
despues de llamar a la funcion de multiplicacion, para calcular la diferencia en milisegundos y mostrarla por pantalla
*/
double tiempo(int** mat1, int** mat2) {
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    mulMat(mat1, mat2);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    return ms_double.count();
}
int main(){
    int** mat1 = new int*[R1];
    int** mat2 = new int*[R2];
    for (int i = 0; i < R1; i++){
        mat1[i] = new int[C1];
    }
    for (int i = 0; i < R2; i++){
        mat2[i] = new int[C2];
    }
    int N=1;
    double prom=0;
    srand(time(0));
    for(int z=0;z<N;z++){
        for(int i=0;i<R1;i++){
            for(int j=0;j<C1;j++){
                mat1[i][j]=rand()%(R1+C1);
            }
        }
        for(int i=0;i<R2;i++){
            for(int j=0;j<C2;j++){
                mat2[i][j]=rand()%(R2+C2);
            }
        }
        /*
        for(int i=0;i<R1;i++){
            for(int j=0;j<C1;j++){
                cout<<mat1[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
        for(int i=0;i<R2;i++){
            for(int j=0;j<C2;j++){
                cout<<mat2[i][j]<<' ';
            }
            cout<<'\n';
        }
        */
        //cout<<"multiplicacion de las matrices\n";
        prom+=tiempo(mat1, mat2);
    }
    prom/=N;
    cout<<"el promedio es: "<<prom<<" ms\n"; //el promedio de N casos de prueba
	return 0;
}
