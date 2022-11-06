//
// Created by я on 04.11.2022.
//
#include "Strategy_3.h"

char Strategy_3::Move() {
    srand(time(NULL));
    int number = (rand() % 100000) % 2;
    if (number == 0) return 'C';
    else return 'D';
}
