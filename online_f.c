/*
 * online_f.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 200 of year 2019 (Jul 19), 19:58
 */
/*
1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.

2. Написать программу, реализующее двоичное дерево поиска.
 а) Добавить в него обход дерева различными способами;
 б) Реализовать поиск в двоичном дереве поиска;
 в) Добавлять элемент в дерево
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *parent;
  struct Node *left;
  struct Node *right;
} Node;

void preOrderTravers(Node *root) {
  if (root) { // if (root != NULL)
	printf("%d", root->data);
	preOrderTravers(root->left);
	preOrderTravers(root->right);
  }
}

int arr[] = {5,8,7,3,0,9,1,2,4};
int i = 0;

Node* tree(int amount) {
  Node *node;
  if (amount == 0) {
	node = NULL;
  } else {
	int value;
	// here we read the value ex. value = arr[i++];
	node = (Node*) malloc(sizeof(Node));
	amount--;
	node->data = value;
	node->left = tree(amount / 2);
	node->right = tree(amount - amount / 2);
  }
  return node;
}

int main(int argc, const char** argv) {
  tree(10);
  
  return 0;
}
