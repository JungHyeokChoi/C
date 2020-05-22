#ifndef _SORT_DEF_
#define _SORT_DEF_

void slectionSort(int value[], int count); //���� ����
void bubbleSort(int value[], int count); //���� ����
void quickSort(int value[], int start, int end); //�� ����
int partitionQuickSort(int value[],int start,int end); //�� ����
void insertionSort(int value[], int count); //���� ����
void shellSort(int value[], int count); //�� ����
void shellInsertionSort(int value[], int start, int end, int interval); //�� ����
void mergeSort(int value[], int buffer[], int start, int end); //���� ����
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end); //���� ����
void radixSort(int value[], int count, int radix, int digit); //��� ����
void heapSort(int value[], int count); //���� ����
void printArray(int value[], int count); //1���� ��� ���

#endif
