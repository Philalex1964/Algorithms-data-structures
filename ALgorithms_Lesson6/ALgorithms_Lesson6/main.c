//
//  main.c
//  ALgorithms_Lesson6
//
//  Created by Alexander Filippov on 7/23/19.
//  Copyright © 2019 Alexander Filippov. All rights reserved.
//

/*
 1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
 
 2. Написать программу, реализующее двоичное дерево поиска.
 а) Добавить в него обход дерева различными способами;
 б) Реализовать поиск в двоичном дереве поиска;
 в) Добавлять элемент в дерево
 */

#include <stdio.h>
#include <stdlib.h>

//1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.

int hashString()
{
    int sum = 0, i, len;
    char string[100];
    
    printf("Enter the string : ");
    scanf("%s", string);
    
    len = strlen(string);
    for (i = 0; i < len; i++)
    {
        sum = sum + string[i];
    }
    printf("Hash Summe: %d \n",sum);
    return sum;
}

int main(int argc, const char * argv[]) {
    hashString();
    return 0;
}


