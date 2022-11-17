//
// Created by я on 04.11.2022.
//
#include "TheStrategyFactory.h"

void TheStrategyFactory::RegisterStrategy(const std::string name, const strategyInstanceGenerator & strategyFn) {
    strtegies_.insert(std::make_pair(name, strategyFn));
}

Strategy* TheStrategyFactory::CreateStrategy(std::string strategy_name) {
    auto it = strtegies_.find(strategy_name);
    if (it == strtegies_.end()) {
        throw ("Неизвестный идентификатор");
    }
    return (it->second());
}
