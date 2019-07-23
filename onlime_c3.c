/*
 * online_c.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 190 of year 2019 (Jul 09), 20:07
 */
/*
1. Оптимизировать пузырьковую сортировку. 
Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. 
Написать функции сортировки, которые возвращают количество операций.

2. *Реализовать шейкерную сортировку.

3. Рекурсивное решение задачи линейного поиска

*/
#include <stdio.h>
#include <stdlib.h>

void fillArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++)
	arr[i] = rand() % 100;
}

void printArray(int* arr, int  len) {
  int i;
  for (i = 0; i < len; i++)
	printf("%d ", arr[i]);
  printf("\n");
}

int linearSearch(int* arr, int len, int v) {
  int i = 0;
  while (i < len && arr[i] != v) i++;

  return (i == len) ? -1 : i;
}

int barrierSearch(int* arr, int len, int v) {
  int i = 0;
  // arr[len] = v;
  while (arr[i] != v) i++;

  return (i == len) ? -1 : i;
}

void swap(int *a, int *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void bubbleSort(int* arr, int len) {
  int i;
  int j;
  for (i = 0; i < len; i++)
	for (j = 0; j < len - 1; j++)
	  if (arr[j] > arr[j + 1])
		swap(&arr[j], &arr[j + 1]);
    
    
}

void pickSort(int* arr, int len) {
  int i;
  int j;
  for (i = 0; i < len; i++) {
	int flag = i;
	for (j = i + 1; j < len; j++) {
	  if (arr[j] < arr[flag]) {
		flag = j;		
	  }
	}
	if (arr[i] != arr[flag]) {
	  swap(&arr[i], &arr[flag]);
	}
  }
}

int binarySearch(int* arr, int len, int v) {
  int left = 0;
  int right = len - 1;
  int mid = (left + right) / 2;
  // int mid = left + ((v - arr[left]) * (right - left)) / (arr[right] - arr[left]); // interpolar
  while (left <= right && arr[mid] != v) {
	if (arr[mid] < v)
	  left = mid;
	else
	  right = mid;
	mid = (left + right) / 2;
  }
  
  if (arr[mid] == v)
	return mid;
  else
	return -1;
}

int main(int argc, const char** argv) {
  const int SIZE = 28;
  int arr[SIZE];
  fillArray(arr, SIZE);
  printArray(arr, SIZE);
  // printf("index = %d\n", barrierSearch(arr, SIZE, 92));
  // bubbleSort(arr, SIZE);
  pickSort(arr, SIZE);
  printArray(arr, SIZE);
  printf("index = %d\n", binarySearch(arr, SIZE, 92));
  
  return 0;
}
