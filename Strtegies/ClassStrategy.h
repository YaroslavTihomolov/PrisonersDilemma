//
// Created by я on 29.10.2022.
//

#ifndef PRISONERSDILEMMA_CLASSSTRATEGY_H
#define PRISONERSDILEMMA_CLASSSTRATEGY_H
#include <iostream>
#include "StrategyFactoryRegistration.h"
#include "HistoryOfMoves.h"

using namespace std;

class Strategy {
public:
    int num_of_strategy;
    int num_in_cur_game;
    Strategy() { num_of_strategy = 0; }
    void AddNum(int);
    virtual char Move();
    int points = 0;
    int GetNum();
    virtual ~Strategy() = default;
};


#endif //PRISONERSDILEMMA_CLASSSTRATEGY_H
