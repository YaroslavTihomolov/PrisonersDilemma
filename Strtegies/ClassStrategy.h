//
// Created by я on 29.10.2022.
//

#ifndef PRISONERSDILEMMA_CLASSSTRATEGY_H
#define PRISONERSDILEMMA_CLASSSTRATEGY_H
#include <iostream>
#include "StrategyFactory/StrategyFactoryRegistration.h"
#include "Moves_History/HistoryOfMoves.h"
#include "C:\CLionProjects\PrisonersDilemma\GameModes\ClassGame.h"
#include "C:\CLionProjects\PrisonersDilemma\Strtegies\InputInformation\Input.h"

using namespace std;

class Strategy {
public:
    std::string name_of_strategy;
    int num_in_cur_game;
    Strategy() = default;
    void AddNum(int);
    virtual char Move();
    int points = 0;
    std::string GetName();
    virtual ~Strategy() = default;
};


#endif //PRISONERSDILEMMA_CLASSSTRATEGY_H
