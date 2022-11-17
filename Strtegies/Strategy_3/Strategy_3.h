//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_3_H
#define PRISONERSDILEMMA_STRATEGY_3_H
#include "../ClassStrategy.h"
#include <ctime>

class Strategy_3: public Strategy {
public:
    Strategy_3() { name_of_strategy = "RANDOM_MOVE"; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_3> Strategy_3("RANDOM_MOVE");
}

#endif //PRISONERSDILEMMA_STRATEGY_3_H
