//
// Created by я on 10.11.2022.
//

#ifndef PRISONERSDILEMMA_TOURNAMENT_H
#define PRISONERSDILEMMA_TOURNAMENT_H

#include "../ClassGame.h"

class Tournament: public Game{
private:
    std::vector< std::string > strategies;
public:
    Tournament(std::string, int);
    void ChooseWinner(int&, std::string &, std::string, std::string, std::string);
};

#endif //PRISONERSDILEMMA_TOURNAMENT_H
