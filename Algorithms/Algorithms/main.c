//
//  main.c
//  Algorithms
//
//  Created by Alexander Filippov on 7/4/19.
//  Copyright © 2019 Alexander Filippov. All rights reserved.
//
// 1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
// 2. Написать программу нахождения корней заданного квадратного уравнения.
// 3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
// 4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить, относятся ли к поля к одному цвету или нет.
// 5* Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. Например, 25 ^ 2 = 625. Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч

#include <stdio.h>
#include <string.h>
#include <math.h>


int calculateSquareEquation(int a, int b, int c, float* x1, float* x2) {
    double D; //discriminant
    D = b * b - 4 * a * c;
    if (a == 0) {
        *x1 = -c / b;
        return 0;
    } else if (D > 0) {
        *x1 = (-b + sqrt(D)) / 2 * a;
        *x2 = (-b - sqrt(D)) / 2 * a;
        return 1;
    } else if (D == 0) {
        *x1 = -b / (2 * a);
        return 0;
    } else {
        // D < 0;
        return -1;
    }
}

int spellAge(int age, int n) {
    n = age%10;
    if (n == 1 && (age != 11 && age !=111)) {
        
        printf("%d \n", age);
        return 1;
        
        
    } else if (n >=2 && n <= 4 && (age < 5 || age > 14) && (age < 105 || age > 114)) {
        
       printf("%d \n", age);
        return 2;
        
    } else {
        
        printf("%d \n", age);
        return 5;
    }
}


int main(int argc, const char * argv[]) {
    // 1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
    
//    float i, m, h;
//
//    printf("This program will calculate Body Mass Index (BMI)");
//    printf("\n Enter your weight: ");
//    scanf("%f", &m);
//    printf("\n Enter your height: ");
//    scanf("%f", &h);
//
//    i = m / (h * h);
//    printf("Your BMI equals: %.2f", i);
//    printf("\n");
//
//
//    // 2. Написать программу нахождения корней заданного квадратного уравнения (ax2 + bx + c = 0).
//
//    float a, b, c, x1, x2;
//
//    printf("This program will calculate a square equation 'ax2 + bx + c = 0'");
//    printf("\n Enter a: ");
//    scanf("%f", &a);
//    printf("\n Enter b: ");
//    scanf("%f", &b);
//    printf("\n Enter c: ");
//    scanf("%f", &c);
//
//    int result;
//    result = calculateSquareEquation(a, b, c, &x1, &x2);
//    switch (result) {
//        case 0:
//            printf("Equation has a unique root x = %f", x1);
//            break;
//        case 1:
//            printf("Equation has two roots x1 = %f, x2 = %f", x1, x2);
//            break;
//        case -1:
//            printf("Equation has no roots");
//            break;
//        default:
//            printf("Exceptional answer: %d", result);
//
//    }
    
    
    
// 3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
    
    int age;
    int n;
    
    printf("\n Введите ваш возраст цифрами: ");
    scanf("%d", &age);
    
    int enteredAge = spellAge(age, n);
    
    if (age > 0 && age <= 150) {
        switch (enteredAge) {
            case 1:
                printf("Ваш возраст - %d год.", age);
                break;
            case 2:
                printf("Ваш возраст - %d годa.", age);
                break;
            case 5:
                printf("Ваш возраст - %d лет.", age);
                break;
            default:
                printf("Ошибочка вышла.");
                printf("\n");
        }
    } else {
        printf("Люди столько не живут.");
    }

    
 
    
    
 // 4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить, относятся ли к поля к одному цвету или нет.
    
    
    
    
    
    
            printf("\n");

            return 0;
}

