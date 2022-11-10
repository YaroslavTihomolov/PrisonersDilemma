//
// Created by я on 04.11.2022.
//
#include "TheStrategyFactory.h"

void TheStrategyFactory::RegisterStrategy(const int id, const strategyInstanceGenerator & strategyFn) {
    strtegies_.insert(std::make_pair(id, strategyFn));
}

Strategy* TheStrategyFactory::CreateStrategy(int strtegyid) {
    auto it = strtegies_.find(strtegyid);
    if (it == strtegies_.end()) {
        throw ("Неизвестный идентификатор");
    }
    return (it->second());
}
