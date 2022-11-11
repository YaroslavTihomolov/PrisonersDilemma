//
// Created by я on 10.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGY_5_H
#define PRISONERSDILEMMA_STRATEGY_5_H
#include "../ClassStrategy.h"
#include <fstream>

class Strategy_5: public Strategy {
private:
    int flag;
    int count_of_moves;
    std::ifstream conf;
    char NumOfStrategy;
public:
    Strategy_5();
    char Move();
};

namespace {
    StrategyFactoryRegistration::StrategyFactoryRegistration<Strategy_5> Strategy_5(5);
}
#endif //PRISONERSDILEMMA_STRATEGY_5_H
