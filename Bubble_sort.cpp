#include <bits/stdc++.h>

using namespace std;

//Include Poetry - Code. (2020, 4 de enero). Bubble sort. Obtenido de https://www.include-poetry.com/Code/C++/Metodos/Ordenamientos/Bubble-sort/
void bubbleSort(int conjunto[], int N){
    int tmp;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 1; j++){
            if (conjunto[j] > conjunto[j + 1]){
                tmp = conjunto[j];
                conjunto[j] = conjunto[j + 1];
                conjunto[j + 1] = tmp;
            }
        }
    }
}
void tiempo(int arr1[],int l1,int arr2[],int l2, int arr3[],int l3){
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    bubbleSort(arr1, l1);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    cout << ms_double.count() << " ms\n";

    auto t3 = high_resolution_clock::now();
    bubbleSort(arr2, l2);
    auto t4 = high_resolution_clock::now();
    duration<double, milli> ms_double2 = t4 - t3;
    cout << ms_double2.count() << " ms\n";

    auto t5 = high_resolution_clock::now();
    bubbleSort(arr3, l3);
    auto t6 = high_resolution_clock::now();
    duration<double, milli> ms_double3 = t6 - t5;
    cout << ms_double3.count() << " ms\n";
}
//O(n^2)
int main(){
    int l1=10,l2=1000,l3=100000;
    int arr1[l1], arr2[l2], arr3[l3];
    for(int i=0;i<l1;i++){
        arr1[i]=rand() % l1;
    }
    for(int i=0;i<l2;i++){
        arr2[i]=rand() % l2;
    }
    for(int i=0;i<l3;i++){
        arr3[i]=rand() % l3;
    }
    cout<<"random:\n";
    tiempo(arr1,l1,arr2,l2,arr3,l3);

    for(int i=0;i<l1;i++){
        arr1[i]=i;
    }
    for(int i=0;i<l2;i++){
        arr2[i]=i;
    }
    for(int i=0;i<l3;i++){
        arr3[i]=i;
    }
    cout<<"ordenado ascendiente:\n";
    tiempo(arr1,l1,arr2,l2,arr3,l3);
    
    for(int i=0;i<l1;i++){
        arr1[i]=l1-i;
    }
    for(int i=0;i<l2;i++){
        arr2[i]=l2-i;
    }
    for(int i=0;i<l3;i++){
        arr3[i]=l3-i;
    }
    cout<<"ordenado descendiente:\n";
    tiempo(arr1,l1,arr2,l2,arr3,l3);
    
    return 0;
}