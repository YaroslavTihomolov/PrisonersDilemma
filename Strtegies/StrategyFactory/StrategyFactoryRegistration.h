//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_STRATEGYFACTORYREGISTRATION_H
#define PRISONERSDILEMMA_STRATEGYFACTORYREGISTRATION_H

#include "TheStrategyFactory.h"
#include "../ClassStrategy.h"

namespace StrategyFactoryRegistration {
    template <typename T>
    class StrategyFactoryRegistration
    {
    public:
        StrategyFactoryRegistration(const int id) {
            TheStrategyFactory::Instance().RegisterStrategy(
                    id,
                    []() { return static_cast<Strategy*>(new T()); }
            );
        }
    };

}

#endif //PRISONERSDILEMMA_STRATEGYFACTORYREGISTRATION_H
