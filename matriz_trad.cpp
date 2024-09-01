#include <bits/stdc++.h>
using namespace std;

// Edit MACROs here, according to your Matrix Dimensions for
// mat1[R1][C1] and mat2[R2][C2]
#define R1 1000 // number of rows in Matrix-1
#define C1 1000 // number of columns in Matrix-1
#define R2 1000 // number of rows in Matrix-2
#define C2 1000 // number of columns in Matrix-2

//codigo obtenido de: https://www.geeksforgeeks.org/cpp-matrix-multiplication/
//se le modifico la memoria dinamica en la funcion multMat
void mulMat(int mat1[][C1], int mat2[][C2])
{
	
    int** rslt = new int*[R1];
    for (int i = 0; i < R1; i++) {
        rslt[i] = new int[C2];
    }

    // Multiplicación de matrices
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < R1; i++) {
        delete[] rslt[i];
    }
    delete[] rslt;
}

double tiempo(int mat1[][C1],int mat2[][C2]){
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    mulMat(mat1, mat2);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    //cout << ms_double.count() << " ms\n\n";
    return ms_double.count();
}

int main(){
	int mat1[R1][C1];
	int mat2[R2][C2];
    int N=10;
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
