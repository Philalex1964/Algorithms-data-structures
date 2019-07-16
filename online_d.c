/*
 * online_d.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 193 of year 2019 (Jul 12), 20:37
 */
#include <stdio.h>
#include <stdlib.h>

int routes(int x, int y) {
  if (x == 0 || y == 0)
	return 1;
  else
	return routes(x - 1, y) + routes(x, y - 1);
}

#define X 8
#define Y 8
#define QUEENS 8
int board[Y][X];

void annull() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  board[i][j] = 0;
	}
  }
}

void printBoard() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  printf("%d ", board[i][j]);
	}
	printf("\n");
  }  
}

int checkQueen(int x, int y) {
    int i;
	int j;
	for(i = 0; i < Y; i++)
        for(j = 0; j < X; j++)
          if (board[i][j] != 0) // Если нашли фигуру
              if (!(i == x && j == y)) {// Если это не наша фигура
                  // Лежат на одной вертикали или горизонтали
                  if (i - x == 0 || j - y == 0) return 0;
				  // Лежат на одной диагонали
                  if (abs(i - x) == abs(j - y)) return 0;
              }
	// Если дошли сюда, то всё в порядке
	return 1;
}

int checkBoard() {
	int i;
	int j;
	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			if (board[i][j] != 0)
				if (checkQueen(i, j) == 0)
					return 0;
	return 1;
}
int operations = 0;

int queens(int n) {
  if (checkBoard() == 0) return 0;
  if (n == QUEENS + 1) return 1;
  int row;
  int col;
  for (row = 0; row < Y; row++) {
	for (col = 0; col < X; col++) {
	  operations++;
	  if (board[row][col] == 0) {
		board[row][col] = n;
		if (queens(n + 1))
		  return 1;
		board[row][col] = 0;
	  }
	}
  }
  return 0;
}
/*
1. * Найти количество маршрутов шахматного короля на поле с препятствиями.

2. *** Требуется обойти конём шахматную доску размером 8х8, 
пройдя через все поля доски по одному разу. 
Здесь алгоритм решения такой же как и в задаче о 8 ферзях.

+3 рекурсивное решение бинарного поиска
*/
int main(int argc, const char** argv) {
  // int i;
  // int j;
  // for (i = 0; i < 10; i++) {
  // 	for (j = 0; j < 10; j++) {
  // 	  printf("%6d", routes(i, j));
  // 	}
  // 	printf("\n");
  // }
  annull();
  queens(1);
  printBoard();
  printf("%d\n", operations);

  return 0;
}
