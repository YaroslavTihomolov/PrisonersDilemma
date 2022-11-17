//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_1_H
#define PRISONERSDILEMMA_STRATEGY_1_H
#include "../ClassStrategy.h"

class Strategy_1: public Strategy {
public:
    Strategy_1() { name_of_strategy = "ALWAYS_C"; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_1> Strategy_1("ALWAYS_C");
}

#endif //PRISONERSDILEMMA_STRATEGY_1_H
