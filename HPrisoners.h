//
// Created by я on 22.10.2022.
//

#ifndef PRISONERSDILEMMA_HPRISONERS_H
#define PRISONERSDILEMMA_HPRISONERS_H
#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Strategy {
public:
    virtual char Move();
    int points = 0;
};

class Strategy_1: public Strategy {
public:
    char Move();
};

class Strategy_2: public Strategy {
public:
    char Move();
};

class Strategy_3: public Strategy {
public:
    char Move();
};

class Matrix {
public:
    map<int, int[3]> game_matrix;
    Matrix();
};

class Game {
    Strategy & strat_1;
    Strategy & strat_2;
    Strategy & strat_3;
    char cur_step1, cur_step2, cur_step3;
public:
    Matrix matrix;
    Game(Strategy & s_1, Strategy & s_2, Strategy & s_3);
    Game(Strategy && s_1, Strategy && s_2, Strategy && s_3);
    Strategy ChooseStrategy(int);
    void Detailed();
    void Fast(int);
    int NumberOfVariant ();
    void AddPoints(int number_of_variant);
    void OutputResult();
    void OutputCurMove(int);
};

#endif //PRISONERSDILEMMA_HPRISONERS_H
