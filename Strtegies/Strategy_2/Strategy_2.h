//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_2_H
#define PRISONERSDILEMMA_STRATEGY_2_H
#include "../ClassStrategy.h"

class Strategy_2: public Strategy {
public:
    Strategy_2() { name_of_strategy = "ALWAYS_D"; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_2> Strategy_2("ALWAYS_D");
}

#endif //PRISONERSDILEMMA_STRATEGY_2_H
