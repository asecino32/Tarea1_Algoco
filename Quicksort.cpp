#include <iostream>
#include <chrono>

using namespace std;

//codigo sacado de : https://www.programiz.com/dsa/quick-sort
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//codigo sacado de : https://www.programiz.com/dsa/quick-sort
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

//codigo sacado de : https://www.programiz.com/dsa/quick-sort
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void tiempo(int arr1[],int l1,int arr2[],int l2, int arr3[],int l3){
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    quickSort(arr1, 0, l1 - 1);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    cout << ms_double.count() << " ms\n";

    auto t3 = high_resolution_clock::now();
    quickSort(arr2, 0, l2 - 1);
    auto t4 = high_resolution_clock::now();
    duration<double, milli> ms_double2 = t4 - t3;
    cout << ms_double2.count() << " ms\n";

    auto t5 = high_resolution_clock::now();
    quickSort(arr3, 0, l3 - 1);
    auto t6 = high_resolution_clock::now();
    duration<double, milli> ms_double3 = t6 - t5;
    cout << ms_double3.count() << " ms\n";
}
//O(nlog(n)) (peor caso es n^2)
int main() {
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