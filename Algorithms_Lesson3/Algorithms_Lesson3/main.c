//
//  main.c
//  Algorithms_Lesson3
//
//  Created by Alexander Filippov on 7/12/19.
//  Copyright © 2019 Alexander Filippov. All rights reserved.
//
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

// 2. *Реализовать шейкерную сортировку.
void shakerSort(int *arr, int len)
{
    int j;
    int last = len-1;
    int left = 1;
    int right = len-1;
    
    
    while (left < right) {
        for(j = left; j <= right; j++) {
            if(arr[j-1] > arr[j])
            {
                swap(&arr[j-1], &arr[j]);
                last = j;
            }
        }
        right = last-1;
        
        for(j = right; j >= left; j--) {
            if(arr[j-1] > arr[j])
            {
                swap(&arr[j-1], &arr[j]);
                last = j;
            }
        }
        left = last + 1;
    }
}

int linearSearch(int* arr, int len, int v) {
    int i = 0;
    while (i < len && arr[i] != v) i++;
    
    return (i == len) ? -1 : i;
}

// 3. Рекурсивное решение задачи линейного поиска
int linearSearchRecursive(int* arr, int len, int i, int v) {
    if (arr[i] == v) {
        return i;
    } else {
        return (linearSearchRecursive(arr,len,i+1,v));
    }
    return -1;
}

int main(int argc, const char** argv) {
    const int SIZE = 30;
    int arr[SIZE];
    int i;
    fillArray(arr, SIZE);
    printArray(arr, SIZE);
    // bubbleSort(arr, SIZE);
    shakerSort(arr, SIZE);
    printArray(arr, SIZE);
    //    printf("%d", linearSearch(arr, SIZE, 75));
    //    puts("");
    printf("%d", linearSearchRecursive(arr, SIZE, i, 78));
    puts("");
    return 0;
}


/*
 1. Оптимизировать пузырьковую сортировку.
 Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
 Написать функции сортировки, которые возвращают количество операций. - Не смог (((
 
 2. *Реализовать шейкерную сортировку. - готово
 
 3. Рекурсивное решение задачи линейного поиска - готово
 
 */
