/*
 * online_b.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 186 of year 2019 (Jul 05), 20:45
 */

/*
1 Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
2. Реализовать функцию возведения числа a в степень b:
 	 b. рекурсивно;
 	 c. *рекурсивно, используя свойство чётности степени.
2.5. Решить на листочке задачу ЕГЭ из урока с G(6)
3. * Программа преобразует целое число. У программы две команды:
  	  	  Прибавь 1
  	  	  Умножь на 2
	Сколько существует путей для данной программы, которые число 3 преобразуют в число 20? Решить с использованием рекурсии.

*/
#include <stdio.h>
#include <stdlib.h>

void cycle(int a, int b) {
  while (a < b) {
	printf("%d ", a);
	a++;
  }
  printf("%d ", a);
}

void loop(int a, int b) {
  printf("%d ", a++);
  if (a < b) {
	loop(a, b);
  }
  printf("%d ", a);
}

int fc(int n) { //O(n)
  int result = 1;
  while (n > 0)
	result *= n--;
  return result;
}

int F(int n) {
  if (n > 0)
	return F(n - 1) * n;
  else
	return 1;
}

// int F(int n) {
//   if (n > 2)
// 	return F(n - 1) + G(n - 2);
//   else
// 	return n;
// }

// int G(int n) {
//   if (n > 2)
// 	return G(n - 1) + F(n - 2);
//   else
// 	return 3 - n;
// }
// printf("%d\n", G(6));

int operations = 0;
void put(int from, int to) {
  printf("%d -> %d | ", from, to);
  if ((++operations % 10) == 0)
	printf("\n");
}

// 01^10=11, 01^11=10, 10^01=11, 11^10=01
// 1^2=3,    1^3=2,    2^1=3,    3^2=1
void hanoi(int from, int to, int n) {
  int temp = from ^ to;
  if (n == 1) {
	put(from, to);
  } else {
	hanoi(from, temp, n - 1);
	put(from, to);
	hanoi(temp, to, n - 1);
  }
  
}

int main(int argc, const char** argv) {
  cycle(0, 5);
  printf("\n");
  loop(0, 5);
  printf("\n");
  printf("%d\n", fc(5));
  printf("%d\n", F(6));
  int disks = 4;
  printf("pyramid size: %d\n", disks);
  hanoi(1, 3, disks);
  printf("\nOperations: %d", operations);
  return 0;
}
