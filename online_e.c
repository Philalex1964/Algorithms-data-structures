/*
 * online_e.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 197 of year 2019 (Jul 16), 20:23
 */
#include <stdio.h>
#include <stdlib.h>

/*
1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.

2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. 
Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), 
неправильных — )(, ())({), (, ])}), [(]) для скобок [,(,{.
Например: (2+(2*2)) или [2/{5*(4+7)}]

3. *Создать функцию, копирующую односвязный список (без удаления первого списка).

4. Реализовать очередь.
*/

#define T char
#define SZ 100

// T Stack[SZ];
// int idx = -1;

// void push(T i) {
//   if (idx < SZ) {
// 	Stack[++idx] = i;
//   } else {
// 	printf("%s\n", "Stack overflow");
//   }
// }

// T pop() {
//   if (idx != -1) {
// 	return Stack[idx--];
//   } else {
// 	printf("%s\n", "Stack is empty");
// 	return -1;
//   }
// }

typedef struct Node {
  T data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} Stack;

int push(Stack *st, T val) {
  Node *temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL) return 0;

  temp->data = val;
  temp->next = st->head;

  st->head = temp;
  st->size++;
  return 1;
}

T pop(Stack *st) {
  if (st->size == 0) {
	return -1;
  }
  Node *temp = st->head;
  T result = st->head->data;

  st->head = st->head->next;
  st->size--;
  free(temp);
  return result;
}

int main(int argc, const char** argv) {
  Stack s;
  s.size = 0;
  s.head = NULL;

printf("%s\n", "This is linked list");
  
  push(&s, 'a');
  push(&s, 'b');
  push(&s, 'c');
  push(&s, 'd');
  push(&s, 'e');
  push(&s, 'f');

  while (s.size > 0) {
  	printf("%c ", pop(&s));
  }
  
  return 0;
}
