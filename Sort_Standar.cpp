#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

/*
    Recibe 3 arreglos y su largo, luego toma el tiempo antes y despues de llamar a la funcion de 
ordenamiento calcula la diferencia en milisegundos y la muestra por pantalla
*/
void tiempo(int arr1[],int l1,int arr2[],int l2, int arr3[],int l3){
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    sort(arr1, arr1+l1);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    cout << ms_double.count() << " ms\n";

    auto t3 = high_resolution_clock::now();
    sort(arr2, arr2+l2);
    auto t4 = high_resolution_clock::now();
    duration<double, milli> ms_double2 = t4 - t3;
    cout << ms_double2.count() << " ms\n";

    auto t5 = high_resolution_clock::now();
    sort(arr3, arr3+l3);
    auto t6 = high_resolution_clock::now();
    duration<double, milli> ms_double3 = t6 - t5;
    cout << ms_double3.count() << " ms\n";
}

//O(nlog(n))
int main(){
    int l1 = 10, l2 = 100, l3 = 1000, l4 = 10000, l5 = 100000, l6 = 100000000;
    
    int arr1[l1], arr2[l2], arr3[l3], arr4[l4], arr5[l5];//,arr6[l6];
    int* arr6= new int[l6];
    for (int i = 0; i < l1; i++) {
        arr1[i] = rand() % l1;
        }
    for (int i = 0; i < l2; i++) {
        arr2[i] = rand() % l2;
        }
    for (int i = 0; i < l3; i++) {
        arr3[i] = rand() % l3;
        }
    for (int i = 0; i < l4; i++) {
        arr4[i] = rand() % l4;
        }
    for (int i = 0; i < l5; i++) {
        arr5[i] = rand() % l5;
        }
    for (int i = 0; i < l6; i++) {
        arr6[i] = rand() % l6;
        }
    
    cout << "random:\n";
    tiempo(arr1, l1, arr2, l2, arr3, l3);
    tiempo(arr4, l4, arr5, l5, arr6, l6);
    for (int i = 0; i < l1; i++) {
        arr1[i] = i;
        }
    for (int i = 0; i < l2; i++) {
        arr2[i] = i;
        }
    for (int i = 0; i < l3; i++) {
        arr3[i] = i;
        }
    for (int i = 0; i < l4; i++) {
        arr4[i] = i;
        }
    for (int i = 0; i < l5; i++) {
        arr5[i] = i;
        }
    for (int i = 0; i < l6; i++) {
        arr6[i] = i;
        }

    cout << "ordenado ascendiente:\n";
    tiempo(arr1, l1, arr2, l2, arr3, l3);
    tiempo(arr4, l4, arr5, l5, arr6, l6);
    
    for (int i = 0; i < l1; i++) {
        arr1[i] = l1 - i;
        }
    for (int i = 0; i < l2; i++) {
        arr2[i] = l2 - i;
        }
    for (int i = 0; i < l3; i++) {
        arr3[i] = l3 - i;
        }
    for (int i = 0; i < l4; i++) {
        arr4[i] = l4 - i;
        }
    for (int i = 0; i < l5; i++) {
        arr5[i] = l5 - i;
        }
    for (int i = 0; i < l6; i++) {
        arr6[i] = l6 - i;
        }

    cout << "ordenado descendiente:\n";
    tiempo(arr1, l1, arr2, l2, arr3, l3);
    tiempo(arr4, l4, arr5, l5, arr6, l6);
    return 0;
}