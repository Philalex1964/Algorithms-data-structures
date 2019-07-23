//
//  main.c
//  Algorithms_Lesson5
//
//  Created by Alexander Filippov on 7/19/19.
//  Copyright © 2019 Alexander Filippov. All rights reserved.
//

/*
 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 
 2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
 Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
 неправильных — )(, ())({), (, ])}), [(]) для скобок [,(,{.
 Например: (2+(2*2)) или [2/{5*(4+7)}]
 
 3. *Создать функцию, копирующую односвязный список (без удаления первого списка).
 
 4. Реализовать очередь.
 */


#include<stdio.h>
#include <stdlib.h>

//     1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.

#define SZ 100

typedef struct Stack {
    int data[SZ];
    int head;
} Stack;

void push(Stack *s,int x) {
    s->head=s->head+1;
    s->data[s->head]=x;
}

int pop(Stack *s) {
    int x;
    x=s->data[s->head];
    s->head=s->head-1;
    return(x);
}

int main(int argc, const char** argv) {
    
    //     1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
    Stack s;
    int num;
    s.head = -1;
    
    printf("Enter decimal number:");
    scanf("%d",&num);
    
    while((num!=0)) {
        if(num < SZ) {
            push(&s,num%2);
            num=num/2;
        } else {
            printf("Stack overflow \n");
            return 0;
        }
    }
    
    while(s.head != -1) {
        num=pop(&s);
        printf("%d",num);
    }
    printf("\n");
}

