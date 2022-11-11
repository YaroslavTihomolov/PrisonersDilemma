//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_3_H
#define PRISONERSDILEMMA_STRATEGY_3_H
#include "../ClassStrategy.h"
#include <ctime>

class Strategy_3: public Strategy {
public:
    Strategy_3() { num_of_strategy = 3; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_3> Strategy_3(3);
}

#endif //PRISONERSDILEMMA_STRATEGY_3_H
