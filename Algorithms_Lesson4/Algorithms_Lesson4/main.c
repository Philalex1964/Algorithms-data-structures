//
//  main.c
//  Algorithms_Lesson4
//
//  Created by Alexander Filippov on 7/16/19.
//  Copyright © 2019 Alexander Filippov. All rights reserved.
//

/*
 1. * Найти количество маршрутов шахматного короля на поле с препятствиями.
 
 2. *** Требуется обойти конём шахматную доску размером 8х8,
 пройдя через все поля доски по одному разу.
 Здесь алгоритм решения такой же как и в задаче о 8 ферзях.
 
 +3 рекурсивное решение бинарного поиска
 */
#include <stdio.h>
#include <stdlib.h>
//#define X 10
//#define Y 10

int routes(int x, int y, int map[10][10]) {
    if (x == 0 || y == 0)
        return 1;
    else if (map[y][x] == 0)
        return 0;
    else
        return routes(x - 1, y, map) + routes(x, y - 1, map);
}

void mapValue(int map[10][10]) {
    int i;
    int j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = 1;
        }
    }
}

int main(int argc, const char** argv){
//    1. * Найти количество маршрутов шахматного короля на поле с препятствиями.
    int i;
    int j;
    int map[10][10];
    mapValue(map);
    map[1][1] = 0;
    map[2][4] = 0;
    map[5][5] = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%6d", routes(i, j, map));
        }
        printf("\n");
    }
    return 0;
}
