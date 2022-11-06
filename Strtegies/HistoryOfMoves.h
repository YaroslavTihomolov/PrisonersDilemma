//
// Created by я on 04.11.2022.
//

#ifndef PRISONERSDILEMMA_HISTORYOFMOVES_H
#define PRISONERSDILEMMA_HISTORYOFMOVES_H
#include <vector>
#include <string>

class MovesHistory {
public:
    static MovesHistory& Instance()
    {
        static MovesHistory theSingleInstance;
        return theSingleInstance;
    }

    std::vector<char> Last_3_Moves();

    void Clear();

    void AddMoves(char m_1, char m_2, char m_3);

    void Print();

private:
    std::vector <char> matrix;
    MovesHistory(){}
    MovesHistory(const MovesHistory& root) = delete;
    MovesHistory& operator=(const MovesHistory) = delete;
};

#endif //PRISONERSDILEMMA_HISTORYOFMOVES_H
