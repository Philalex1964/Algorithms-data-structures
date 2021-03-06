/*
 * online_g.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 204 of year 2019 (Jul 23), 19:50
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
  int data;
  int index;
  int used;
  struct List* children;
} GraphNode;

int widthTravers(GraphNode *start, GraphNode * stop) {
  pushQueue(q, start);
  start->used = 1;
  while (q->size != 0) {
	GraphNode current = popQueue(q);
	if (current->data == stop->data)
	  return 1;

	while (current->children.size != 0) {
	  int i;
	  for (i = 0; i < children.size; i++) {
		if (children.get(i).used != 1) {
		  pushQueue(q, children.get(i));
		  children.get(i).used = 1;
		}
	  }
	}
  }
}

const int w = 11;
const int h = 12;
const int OBSTACLE = -1;
const int UNVISITED = -2;
int grid[h][w];
int len;
int pointX[h * w];
int pointY[h * w];
int dx[] = {1, 0, -1, 0};
int dy[] = (0, 1, 0, -1);
//init grid with -2 here))

int lee(int sx, int sy, int ex, int ey) {
  int x, y, vector, dist, stop;
  if (sx == ex && sy == ey) return 0;
  if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE) return 0;

  dist = 0;
  grid[sy][sx] = dist;
  do {
	stop = 1;
	for (y = 0; y < h; y++) {
	  for (x = 0; x < w; x++) {
		if (grid[y][x] == dist) {
		  for (vector = 0; vector < 4; vector++) {
			int nextX = x + dx[vector];
			int nextY = y + dy[vector];
			if ( nextX >= 0 && nextX < w &&
				 nextY >= 0 && nextY < h &&
				 grid[nextY][nextX] == UNVISITED) {
			  stop = 0;
			  grid[nextY][nextX] == dist + 1;
			}
		  }
		}
	  }
	}
	dist++;
  } while (!stop && grid[ey][ex] == UNVISITED);

  if (grid[ey][ex] == UNVISITED) return 0;
  
  len = grid[ey][ex];
  x = ex;
  y = ey;
  while (dist > 0) {
	pointX[dist] = x;
	pointY[dist] = y;
	dist--;
	for (vector = 0; vector < 4; vector++) {
	  int nextX = x + dx[vector];
	  int nextY = y + dy[vector];
	  if ( nextX >= 0 && nextX < w &&
		   nextY >= 0 && nextY < h &&
		   grid[nextY][nextX] == dist) {
		x = nextX;
		y = nextY;
	  }
	}
  }
  return 1;
}

int main(int argc, const char** argv) {
  
  
  return 0;
}
