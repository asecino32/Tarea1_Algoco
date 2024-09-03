#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//codigo sacado de: https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
/*
    Realiza el Merge de 2 subarreglos del arreglo original
el primer subarreglo es arreglo[inicio, mitad]
y el segundo subarreglo es arreglo[mitad+1, final]
crea arreglos temporales para almacenar los contenidos de
los subarreglos, luego los vuelve a unir
*/
void merge(int array[], int const left, int const mid, int const right){
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;
	auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
	for (auto i = 0; i < subArrayOne; i++){
		leftArray[i] = array[left + i];
    }
	for (auto j = 0; j < subArrayTwo; j++){
		rightArray[j] = array[mid + 1 + j];
    }
	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else{
			array[indexOfMergedArray] = 
			rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	while (indexOfSubArrayOne < subArrayOne){
		array[indexOfMergedArray] = 
		leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	while (indexOfSubArrayTwo < subArrayTwo){
		array[indexOfMergedArray] = 
		rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

//codigo sacado de: https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
/*
    begin es para el indice izquierdo (inicialmente 0) y end es para el indice derecho inicialmente (n)
del subarreglo de array[] que sera oredenado
*/
void mergeSort(int array[], int const begin, int const end){
	if (begin >= end)
		return;
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

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
    mergeSort(arr1, 0, l1 - 1);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    cout << ms_double.count() << " ms\n";

    auto t3 = high_resolution_clock::now();
    mergeSort(arr2, 0, l2 - 1);
    auto t4 = high_resolution_clock::now();
    duration<double, milli> ms_double2 = t4 - t3;
    cout << ms_double2.count() << " ms\n";
    if(l3!=0){
    auto t5 = high_resolution_clock::now();
    mergeSort(arr3, 0, l3 - 1);
    auto t6 = high_resolution_clock::now();
    duration<double, milli> ms_double3 = t6 - t5;
    cout << ms_double3.count() << " ms\n";
    }
}
//O(nlog(n))
int main() {
    int l1 = 10, l2 = 100, l3 = 1000, l4 = 10000, l5 = 100000, l6 = 100000000;
    int arr1[l1], arr2[l2], arr3[l3], arr4[l4], arr5[l5];
    int* arr6=new int[l6];
    
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
    for (int i = 0; i < l6; i++) { //para probar los tiempos de arr6, se debe probar 1 a 1
        arr6[i] = rand() % l6;
    } 
    /*
    for (int i = 0; i < l6; i++) {
        arr6[i] = i;
    }
    for (int i = 0; i < l6; i++) {
        arr6[i] = l6 - i;
    }
    */
    cout << "random:\n";
    tiempo(arr1, l1, arr2, l2, arr3, l3);
    tiempo(arr4, l4, arr5, l5, arr6, l6);
    delete[] arr6;
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
    
    l6=0;
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

    cout << "ordenado descendiente:\n";
    tiempo(arr1, l1, arr2, l2, arr3, l3);
    tiempo(arr4, l4, arr5, l5, arr6, l6);
    
    return 0;
}
