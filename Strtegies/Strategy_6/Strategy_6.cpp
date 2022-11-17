//
// Created by я on 15.11.2022.
//
#include "Strategy_6.h"

Strategy_6::Strategy_6() {
    name_of_strategy = "META_STRATEGY";
    conf.open(InputInf::Instance().GetName(6));
    if (!conf) throw ("File \"conf6.txt\" not open");
    conf >> first_strategy >> second_strategy;
    s_1 = TheStrategyFactory::Instance().CreateStrategy(first_strategy);
    s_2 = TheStrategyFactory::Instance().CreateStrategy(second_strategy);
}

char Strategy_6::Move() {
    if (count_of_moves++ % 2 == 0)
        return s_1->Move();
    else
        return s_2->Move();
}
