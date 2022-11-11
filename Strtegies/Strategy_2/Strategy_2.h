//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_2_H
#define PRISONERSDILEMMA_STRATEGY_2_H
#include "../ClassStrategy.h"

class Strategy_2: public Strategy {
public:
    Strategy_2() { num_of_strategy = 2; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_2> Strategy_2(2);
}

#endif //PRISONERSDILEMMA_STRATEGY_2_H
