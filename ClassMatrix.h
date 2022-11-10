//
// Created by я on 22.10.2022.
//

#ifndef PRISONERSDILEMMA_CLASSMATRIX_H
#define PRISONERSDILEMMA_CLASSMATRIX_H

#include <map>
#include <fstream>

class Matrix {
public:
    std::map<int, int[3]> game_matrix;
    Matrix() = default;
    void ReadMatrix(std::string);
};

#endif //PRISONERSDILEMMA_CLASSMATRIX_H
