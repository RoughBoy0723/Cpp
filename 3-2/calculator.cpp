#include "calculator.h"
#include <iostream>

using namespace std;

Calculator::Calculator(){
    add_cnt = 0;
    div_cnt = 0;
    mul_cnt = 0;
    min_cnt = 0;
}

double Calculator::Add(double a, double b){
    add_cnt++;
    return a + b;
}

double Calculator::Min(double a, double b){
    min_cnt++;
    return a - b;
}

double Calculator::Mul(double a, double b){
    mul_cnt++;
    return a * b;
}

double Calculator::Div(double a, double b){
    div_cnt++;
    return a / b;
}

void Calculator::showOpCount(){
    printf("덧셈: %d 뺄셈: %d 곱셈: %d 나눗셈: %d\n", add_cnt, min_cnt, mul_cnt, div_cnt);
}