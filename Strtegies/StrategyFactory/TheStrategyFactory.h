//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_TheStrategyFactory_H
#define PRISONERSDILEMMA_TheStrategyFactory_H

#include <unordered_map>
#include <string>

class Strategy;

typedef Strategy*(*strategyInstanceGenerator)();

class TheStrategyFactory {
public:
    static TheStrategyFactory& Instance()
    {
        static TheStrategyFactory theSingleInstance;
        return theSingleInstance;
    }

    void RegisterStrategy(const std::string, const strategyInstanceGenerator&);
    Strategy* CreateStrategy(std::string);

private:
    std::unordered_map <std::string, strategyInstanceGenerator> strtegies_;
    TheStrategyFactory(){}
    TheStrategyFactory(const TheStrategyFactory& root) = delete;
    TheStrategyFactory& operator=(const TheStrategyFactory) = delete;
};

#endif //PRISONERSDILEMMA_TheStrategyFactory_H
