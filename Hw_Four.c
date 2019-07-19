/*
 * HwFour.c
 *
 *  Created on: 24 авг. 2017 г.
 *      Author: ivanovcinnikov
 */
#include <stdio.h>
#include <stdlib.h>

const int He = 8;
const int Wi = 8;

// 1
int routes(int r, int c, int map[He][Wi]) {
  if (r == 0 || c == 0)
	return 1;
  else
	return (map[r][c] == 1) ?
	  routes(r - 1, c, map) + routes(r, c - 1, map) :
	  0;
}

// 2
int possible[][2] = {
  {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
  {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

int isPossible(int desk[He][Wi], int x, int y){
  return x >= 0 && x < He && y >= 0 && y < Wi && desk[x][y] == 0;
}

void initDesk(int desk[He][Wi]) {
  for (int i = 0; i < He; i++)
	for(int j = 0; j < Wi; j++)
	  desk[i][j] = 0;  
}

void printDesk(int desk[He][Wi]){
  printf("\n");
  for (int i = 0; i < He; i++) {
	for(int j = 0; j < Wi; j++)
	  printf("%3d ", desk[i][j]);
	puts("");
  }
}

int knightMove(int desk[He][Wi], int currentX, int currentY, int move){
  int nextX, nextY;
  int maxMoves = He * Wi - 1;
  desk[currentX][currentY] = move;
  if (move > maxMoves) return 1;

  for (int i = 0; i < 7; i++){
	nextX = currentX + possible[i][1];
	nextY = currentY + possible[i][0];
	if (isPossible(desk, nextX, nextY) && knightMove(desk, nextX,nextY, move + 1))
	  return 1;
  }

  desk[currentX][currentY] = 0;
  return 0;
}

void fillArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	arr[i] = i;
  }
}

void printArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	printf("%d ", arr[i]);
  }
  printf("\n");
}

int recBinSrch(int* arr, int start, int end, int value) {
  int mid = (start + end) / 2;
  if (arr[mid] == value) return mid;
  if (start < end) {
	if (arr[mid] < value)
	  return recBinSrch(arr, mid + 1, end, value);
	else
	  return recBinSrch(arr, start, mid, value);
  } else {
	return -1;
  }
}

int main(int argc, const char** argv) {

  // 1. *Количество маршрутов с препятствиями.
  // Реализовать чтение массива с препятствием и нахождение количество маршрутов.
  int arr[He][Wi];
  int obstacles[He][Wi];
  int i;
  int j;

  //init
  for (i = 0; i < He; i++)
	for (j = 0; j < Wi; j++)
	  obstacles[i][j] = 1;
  obstacles[0][3] = 0;
  obstacles[3][2] = 0;
  obstacles[5][5] = 0;
  obstacles[7][7] = 0;

  //fill
  for (i = 0; i < He; i++)
	for (j = 0; j < Wi; j++)
	  arr[i][j] = routes(i, j, obstacles);

  //print
  for (i = 0; i < He; i++) {
	for (j = 0; j < Wi; j++)
	  printf("%4d ", arr[i][j]);
	puts("");
  }

  // 2.	**Требуется обойти конём шахматную доску размером NxM,
  // пройдя через все поля доски по одному разу.

  int desk[He][Wi];
  int maxMoves = He * Wi - 1;

  initDesk(desk);
  knightMove(desk, 1,0,1);
  printDesk(desk);

  const int SIZE = 30;
  int array[SIZE];
  fillArray(array, SIZE);
  printArray(array, SIZE);
  printf("%d\n", recBinSrch(array, 0, SIZE-1, 28));

  return 0;
}
