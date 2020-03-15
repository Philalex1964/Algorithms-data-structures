#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. Реализовать простейшую хеш-функцию. На вход функции подаётся строка,
//на выходе сумма кодов символов.

//2. Переписать программу, реализующее двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;

//3. *Разработать базу данных студентов из трёх полей “Имя”, “Возраст”,
// “Табельный номер” в которой использовать все знания, полученные на уроках.

//4. ****Считайте данные в двоичное дерево поиска. Реализуйте поиск по
//какому-нибудь полю базы данных (возраст, номер)

int hash(char* in) {
  int result = 0;
  while (*in != '\0')
	result += *in++;
  return result;
}

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
};
typedef struct Node Node;

void preOrderTravers(Node* root) {
  if(root) {
	printf("%d ", root->data);
	preOrderTravers(root->left);
	preOrderTravers(root->right);
  }
}

void inOrderTravers(Node* node) {
  if(node) {
	inOrderTravers(node->left);
	printf("%d ", node->data);
	inOrderTravers(node->right);
  }
}

void postOrderTravers(Node* node) {
  if(node) {
	postOrderTravers(node->left);
	postOrderTravers(node->right);
	printf("%d ", node->data);
  }
}

const int SIZE = 10;
int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i = 0;
Node* tree (int n) {
  Node* newNode;
  int value;
  int nL;
  int nR;
  if (n == 0)
	newNode = NULL;
  else {
	value = arr[i++];
	nL = n / 2;
	nR = n - nL - 1;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->left = tree(nL);
	newNode->right = tree(nR);
  }
  return newNode;
}

Node* insert(Node* t, int in) {
  Node* newNode;
  Node* current = t;
  Node* parent = t;
  newNode = (Node*) malloc(sizeof(Node));
  newNode->data = in;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;

  if (t == NULL) {
  	t = newNode;
  } else {
	while (current->data != in) {
	  parent = current;
	  if (current->data > in)  {
		current = current->left;
		if (current == NULL) {
		  parent->left = newNode;
		  newNode->parent = parent;
		  return t;
		}
	  } else {
		current = current->right;
		if (current == NULL) {
		  parent->right = newNode;
		  newNode->parent = parent;
		  return t;
		}
	  }
	}
  }
  return t;
}

void printTree(Node *root) {
  if (root)
    {
	  printf("%d", root->data);
	  if (root->left || root->right)
        {
		  printf("(");
		  if (root->left)
			printTree(root->left);
		  else
			printf("NULL");
		  printf(",");

		  if (root->right)
			printTree(root->right);
		  else
			printf("NULL");
		  printf(")");
        }
    }
}

int searchTree(Node* root, int value) {
  int result = 0;
  if(root) {
	result = searchTree(root->right, value);
	if(result == 0)
	  result = searchTree(root->left, value);
	if (root->data == value)
	  result = 1;
  }
  return result;
}

typedef struct {
  int number;
  char name[256];
  int age;
} Student;

struct StudentTree{
  Student* data;
  struct StudentTree* left;
  struct StudentTree* right;
};
typedef struct StudentTree StudentTree;

Student* readCSV(FILE* f) {
  Student* s = (Student*) malloc(sizeof(Student));
  int num;
  char name[256];
  int age;
  fscanf(f, "%d,%d,%[^\n]s", &num, &age, name);
  s->number = num;
  s->age = age;
  strcpy(s->name, name);
  return s;
}

StudentTree* studentsTree (int n, FILE* f) {
  StudentTree* newNode;
  int nL;
  int nR;
  if (n == 0)
	newNode = NULL;
  else {
	nL = n / 2;
	nR = n - nL - 1;
	newNode = (StudentTree*) malloc(sizeof(StudentTree));
	newNode->data = readCSV(f);
	newNode->left = studentsTree(nL, f);
	newNode->right = studentsTree(nR, f);
  }
  return newNode;
}

Student* searchAge(StudentTree* root, int value) {
  Student* result = NULL;
  if(root) {
	result = searchAge(root->right, value);
	if (result == NULL)
	  result = searchAge(root->left, value);
	if (root->data->age == value)
	  result = root->data;
  }
  return result;
}

int main(int argc, const char** argv) {
  char* expression = "Hello World";
  printf("%d \n", hash(expression));
  Node* greatTree = tree(SIZE);
  Node* insertTree = NULL;
  insertTree = insert(insertTree, 10);
  insertTree = insert(insertTree, 8);
  insertTree = insert(insertTree, 19);
  insertTree = insert(insertTree, 5);

  printTree(greatTree);
  printf("\n");
  printTree(insertTree);
  printf("\n");
  printf("value %sfound \n", (searchTree(greatTree, 10)) ? "" : "not ");
  printf("value %sfound \n", (searchTree(insertTree, 8)) ? "" : "not ");

  FILE *f;
  f = fopen("base.csv", "r");
  int lines = 0;
  while(!feof(f)){
	char c;
	fscanf(f, "%c", &c);
	if (c == '\n')
	  lines++;
  }
  fclose(f);
  f = fopen("base.csv", "r");

  StudentTree* s = studentsTree(lines, f);
  printf("%d %s %d\n", s->data->number, s->data->name, s->data->age);

  Student* v = searchAge(s, 20);
  if(v)
	printf("%d %d %s\n", v->number, v->age, v->name);
  else
	printf("Not Found");

  v = searchAge(s, 25);
  if(v)
	printf("%d %d %s\n", v->number, v->age, v->name);
  else
	printf("Not Found");

  fclose(f);

  return 0;
}
