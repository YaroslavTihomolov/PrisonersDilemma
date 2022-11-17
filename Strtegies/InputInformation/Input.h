//
// Created by я on 15.11.2022.
//

#ifndef PRISONERSDILEMMA_INPUT_H
#define PRISONERSDILEMMA_INPUT_H
#include "C:\CLionProjects\PrisonersDilemma\Parser\Parser.h"

class InputInf {
public:
    static InputInf& Instance()
    {
        static InputInf theSingleInstance;
        return theSingleInstance;
    }

    void AddInfo(Parser copy);

    std::string GetName(int num);

private:
    Parser input;
    InputInf(){}
    InputInf(const InputInf& root) = delete;
    InputInf& operator=(const InputInf) = delete;
};


#endif //PRISONERSDILEMMA_INPUT_H
