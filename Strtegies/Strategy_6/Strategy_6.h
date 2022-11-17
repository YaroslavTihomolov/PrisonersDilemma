//
// Created by я on 15.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_6_H
#define PRISONERSDILEMMA_STRATEGY_6_H

#include "../ClassStrategy.h"
#include <fstream>
#include "C:\CLionProjects\PrisonersDilemma\Strtegies\StrategyFactory\StrategyFactoryRegistration.h"

class Strategy_6: public Strategy {
private:
    int flag;
    int count_of_moves;
    std::ifstream conf;
    char NumOfStrategy;
    std::string first_strategy;
    std::string second_strategy;
    Strategy* s_1;
    Strategy* s_2;
public:
    Strategy_6();
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_6> Strategy_5("META_STRATEGY");
}

#endif //PRISONERSDILEMMA_STRATEGY_6_H
