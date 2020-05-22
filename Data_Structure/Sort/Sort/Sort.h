#ifndef _SORT_DEF_
#define _SORT_DEF_

void slectionSort(int value[], int count); //선택 정렬
void bubbleSort(int value[], int count); //버블 정렬
void quickSort(int value[], int start, int end); //퀵 정렬
int partitionQuickSort(int value[],int start,int end); //퀵 정렬
void insertionSort(int value[], int count); //삽입 정렬
void shellSort(int value[], int count); //셸 정렬
void shellInsertionSort(int value[], int start, int end, int interval); //셸 정렬
void mergeSort(int value[], int buffer[], int start, int end); //병렬 정렬
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end); //병렬 정렬
void radixSort(int value[], int count, int radix, int digit); //기수 정렬
void heapSort(int value[], int count); //히프 정렬
void printArray(int value[], int count); //1차원 행렬 출력

#endif
