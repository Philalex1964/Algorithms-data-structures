#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

typedef int boolean;

const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int FULL_ANSWER = 2;
const int NOT_SQUARE = 3;

// 1.	Написать программу обмена значениями двух целочисленных переменных:
// b.	 *без использования третьей переменной.
void my_swap(int* a, int* b) {  // main a = 1 b = 2 O(1)
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
// K << N == K * 2 ^ N
// 2.	Написать программу нахождения корней заданного квадратного уравнения.
int square(int a, float b, int c, float *x1, float *x2) {
    if(a != 0) {
        int D = b * b - ((a * c) << 2);
        if(D < 0)
            return NO_ROOTS;
        else if (D == 0) {
		  *x1 = (-b / (a << 1));
		  return ONE_ROOT;
        } else {
            *x1 = (-b + sqrt(D)) / (a << 1);
            *x2 = (-b - sqrt(D)) / (a << 1);
            return FULL_ANSWER;
        }
    } else {
    		*x1 = -c / b;
    		return NOT_SQUARE;
    }
}

// 3.	Ввести возраст человека (от 1 до 150 лет) и вывести его вместе
// с последующим словом «год», «года» или «лет».
char* ageAdder(int age) {
    if (age % 10 == 1 && (age % 100 != 11))
        return "год";
    else if ((age % 10 >= 2 && age % 10 < 5) &&
             !(age % 100 >= 12 && age % 100 < 15))
        return "года";
    else
        return "лет";
}

// 4.	С клавиатуры вводятся числовые координаты двух полей шахматной
// доски (x1,y1,x2,y2). Требуется определить, относятся ли к поля к одному
// цвету или нет.
boolean areSame(int x1, int y1, int x2, int y2) {
	return ((x1 + y1) % 2) == ((x2 + y2) % 2);
}


// 5* Автоморфные числа. Натуральное число называется автоморфным,
// если оно равно последним цифрам своего квадрата. Например, 25^2 = 625.
// Напишите программу, которая вводит натуральное число N и выводит на экран
// все автоморфные числа, не превосходящие N.
boolean isAutomorph(int number) { //O(n)
	int temp = number;
	int width = 1;
	while (temp > 0) { //O(n)
		width *= 10;
		temp /= 10;
	}
	int square = (int) pow(number, 2); //O(k)
	return square % width == number;
}

void average() {
  int counter = 0;//-1
  float sum = 0;
  int in = 0;
  do {
	scanf("%d", &in);
	sum += in;
	counter++;
  } while (in != -1);
  if (counter != 1) {
	// printf("mean = %.2f\n", (float)(sum / counter));
	printf("mean = %.2f\n", (float)((sum - in) / --counter));
  } else {
	printf("%s\n", "No input");
  }
}

int main(int argc, const char** argv) {
  	// 1
    int swap_a = 1, swap_b = 2;
    printf("Before:  %d, %d \n", swap_a, swap_b);
    my_swap(&swap_a, &swap_b);
    printf("Swapped: %d, %d \n", swap_a, swap_b);

    //2
    float r1, r2;
    switch(square(2, 3, 4, &r1, &r2)) {
	case NO_ROOTS:
	  printf("No roots \n");
	  break;
	case ONE_ROOT:
	  printf("x = %f\n", r1);
	  break;
	case FULL_ANSWER:
	  printf("x1 = %f\n", r1);
	  printf("x2 = %f\n", r2);
	  break;
	case NOT_SQUARE:
	  printf("Your equation is not square, but it has a root: %f\n", r1);
	  break;
	default:
	  printf("Unexpected function behavior\n");
    }

    //3
    int age = 112;
    printf("Введённый возраст %d %s.\n", age, ageAdder(age));

    //4
    printf("Colors are %s \n", areSame(1, 1, 4, 4) ? "same" : "different");

    //5
    int i;
    for (i = 0; i < 1000000; i++)
        if(isAutomorph(i))
		  printf("number %d is automorpic to %d \n", i, (int)pow(i, 2));

	return 0;
}
