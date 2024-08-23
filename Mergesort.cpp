#include <iostream>
#include <chrono>

using namespace std;

//codigo sacado de: https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
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
void mergeSort(int array[], int const begin, int const end){
	if (begin >= end)
		return;
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

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

    auto t5 = high_resolution_clock::now();
    mergeSort(arr3, 0, l3 - 1);
    auto t6 = high_resolution_clock::now();
    duration<double, milli> ms_double3 = t6 - t5;
    cout << ms_double3.count() << " ms\n";
}
//O(nlog(n))
int main(){
    int l1=100,l2=10000,l3=1000000;
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
