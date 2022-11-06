//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_4_H
#define PRISONERSDILEMMA_STRATEGY_4_H
#include <fstream>
#include "ClassStrategy.h"

class Strategy_4: public Strategy {
private:
    int count_of_moves = 0;
public:
    Strategy_4() { num_of_strategy = 4; }
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_4> Strategy_4(4);
}

#endif //PRISONERSDILEMMA_STRATEGY_4_H