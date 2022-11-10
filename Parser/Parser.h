//
// Created by я on 06.11.2022.
//

#ifndef PRISONERSDILEMMA_PARSER_H
#define PRISONERSDILEMMA_PARSER_H

#include <iostream>
#include "boost/program_options.hpp"
#include <string>
#include <vector>


namespace po = boost::program_options;

struct Parser {
    Parser() = default;
    Parser (int, char**);
    int count_of_steps;
    po::variables_map vm;
    std::vector<std::string> name;
    std::string mode;
    std::vector<std::string> conf_files;
    std::string matrix_file;
};

#endif //PRISONERSDILEMMA_PARSER_H
