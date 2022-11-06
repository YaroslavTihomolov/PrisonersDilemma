//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_1_H
#define PRISONERSDILEMMA_STRATEGY_1_H
#include "ClassStrategy.h"

class Strategy_1: public Strategy {
public:
    Strategy_1() { num_of_strategy = 1; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_1> Strategy_1(1);
}

#endif //PRISONERSDILEMMA_STRATEGY_1_H
