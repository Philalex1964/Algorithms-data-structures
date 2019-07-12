#include <stdio.h>
#include <string.h>

// 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void toBinRecursive(int n, char* b) { // "b'"
    if (n)
        toBinRecursive(n / 2, b);
    else
    	return;
    strcat(b, (n % 2) ? "1" : "0");
    return;
}

// 2. Реализовать функцию возведения числа a в степень b:
//  a. без рекурсии;
long power(int b, int s) {
	long rslt = 1;
	int i;
	for (i = 0; i < s; i++)
		rslt *= b;
	return rslt;
}

//  b. рекурсивно;
long powerec(int b, int s) { // число б в степени С
	if (s)
		return powerec(b, s - 1) * b;  // число б в степени с-1 * б
	else
		return 1;
}

//  c. *рекурсивно, используя свойство чётности степени.
long pluspowerec(int b, int s) {
	if (s)
		if(s % 2)
			return pluspowerec(b, s - 1) * b;
		else
			return pluspowerec(b * b, s / 2);
//		return (s % 2) ? pluspowerec(b, s - 1) * b : pluspowerec(b * b, s / 2);
	else
		return 1;
}

/* 
3. * Программа преобразует целое число. У программы две команды:
  	  	  Прибавь 1
  	  	  Умножь на 2
	Сколько существует путей для данной программы, которые число 3 преобразуют в число 20? Решить с использованием рекурсии.
*/
int calc(int from, int to) {
	if (from < to)
		return calc(from + 1, to) + calc(from * 2, to);
	else if (from == to)
		return 1;
	else
		return 0;
}

int main(int argc, const char** argv) {
	char binary[64] = {"b'"};
	toBinRecursive(11, binary);
	printf("%s \n", binary);

	printf("%ld \n", powerec(2, 10));
	printf("%ld \n", pluspowerec(2, 11));
	printf("%d \n", calc(3, 20));
	return 0;
}
