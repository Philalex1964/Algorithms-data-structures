/*
 * HwThree.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define RANGE 125

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int getMax(int* arr, int size) {
   if (size == 1) return arr[0];
   int r = arr[0];
   int i;
	for (i = 1; i < size; i++)
       if (r < arr[i])
           r = arr[i];
   return r;
}

int getMin(int* arr, int size) {
   if (size == 1) return arr[0];
   int r = arr[0];
   int i;
   for (i = 1; i < size; i++)
       if (r > arr[i])
           r = arr[i];
   return r;
}

int pigeon(int* arr, int size) {
	int steps = 0;
   int min = getMin(arr, size);
   int max = getMax(arr, size);
   const int length = max - min + 1;
   int freq[RANGE] = {0};
   for (int i = 0; i < size; i++) {
   		steps++;
       freq[arr[i] - min]++;
   }

   int arrIndex = 0;
   for (int i = 0; i < RANGE; i++)
       for (int elems = freq[i]; elems > 0; elems--) {
       		steps++;
           arr[arrIndex++] = i + min;
       }
   return steps;
}

void fillArray(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++)
		arr[i] = rand() % 100;
}

void copyArray(int* arrFrom, int* arrTo, int len) {
	int i;
	for (i = 0; i < len; i++)
		arrTo[i] = arrFrom[i];
}

void printArray(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	puts("");
}

int bubbleSort(int* arr, int len) {
	int i;
	int j;
	int count = 0;
	for (i = 0; i < len; i++)
		for (j = 0; j < len - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	return count;
}

//1. Оптимизировать пузырьковую сортировку.
int bubbleSortPlus(int* arr, int len) {
	int i;
	int j;
	int count = 0;
	for (i = 0; i < len; i++) {
		int flag = 1;
		for (j = (i % 2) ? 0 : 1; j < len - 1; j += 2) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}
		if (flag) break;
	}
	return count;
}

//2. *Реализовать шейкерную сортировку.
int shakerSort(int* arr, int len) {
	int count = 0;
	int left = 1;
   int right = len - 1;
   while (left <= right)
   {
       int i;
       for (i = right; i >= left; i--) {
       		count++;
           if (arr[i - 1] > arr[i])
           		swap(&arr[i], &arr[i - 1]);
       }
       left++;
       for (i = left; i <= right; i++) {
       		count++;
           if (arr[i - 1] > arr[i])
           		swap(&arr[i], &arr[i - 1]);
       }
       right--;
   }
   return count;
}

//3. **Реализовать линейный поиск с использованием рекурсивного подхода.
int linearSearch(int* arr, int len, int value) {
	--len;
	if (len >= 0)
		return (arr[len] != value) ? linearSearch(arr, len, value) : len;
	else
		return -1;
}

int main(int argc, const char** argv) {
	const int SIZE = 100;
	int arr0[SIZE];
	int arr1[SIZE];
	int arr2[SIZE];
	int arr3[SIZE];
	fillArray(arr0, SIZE);
	arr0[0] = -15;
	arr0[7] = -19;
	arr0[10] = -5;
	copyArray(arr0, arr1, SIZE);
	copyArray(arr0, arr2, SIZE);
	copyArray(arr0, arr3, SIZE);

	printf("bubbl: %d \n", bubbleSort(arr0, SIZE));
	printf("bubbl+ %d \n", bubbleSortPlus(arr1, SIZE));
	printf("shakr: %d \n", shakerSort(arr2, SIZE));
	printf("pigeon %d \n", pigeon(arr3, SIZE));

	printf("%d \n", linearSearch(arr0, SIZE, 4));

	printArray(arr0, SIZE);
	printArray(arr1, SIZE);
	printArray(arr2, SIZE);
	printArray(arr3, SIZE);

	return 0;
}
