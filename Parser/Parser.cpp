//
// Created by я on 06.11.2022.
//
#include "Parser.h"

Parser::Parser(int argc, char** argv) {
    po::options_description desc("Generate parameters");
    desc.add_options()
            ("help", "produce help message")
            ("mode", po::value<std::string> (&mode), "--mode=[detailed|fast|tournament]")
            ("strategy", po::value< std::vector<std::string> >(&name), "--strategy={ALWAYS_C|ALWAYS_D|RANDOM_MOVE|TIT_FOR_TAT|GRIM_TRIGGER}")
            ("steps", po::value<int>(&count_of_steps)->default_value(10), "--steps")
            ("configs, c", po::value<std::vector<std::string>  >(&conf_files), "--configs[conf4.txt]")
            ("matrix", po::value<std::string> (&matrix_file), "--matrix[Matrix.txt]")
    ;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    std::vector< std::string > strategies = { "ALWAYS_C", "ALWAYS_D", "RANDOM_MOVE", "TIT_FOR_TAT", "GRIM_TRIGGER", "META_STRATEGY" };
    for (int i = 0; i < 6; i++) {
        int flag = 0;
        for (auto j = name.begin(); j < name.end(); j++) {
            if (strategies[i] == *j) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            throw std::invalid_argument("Wrong name of strategy.\n");
    }

    std::vector< std::string > config_files;
    config_files  = {"conf4.txt", "conf5.txt", "conf6.txt"};
    for (int i = 0; i < 3; i++) {
        int flag = 0;
        for (auto j = conf_files.begin(); j < conf_files.end(); j++) {
            if (config_files[i] == *j) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            throw std::invalid_argument("Wrong name of config file.\n");
    }

    if (matrix_file != "Matrix.txt")
        throw std::invalid_argument("Wrong name of matrix file.\n");

    if (vm.count("help")) {
        std::cout << desc;
        throw ("call --help\n");
    }
    else if (count_of_steps <= 0) {
        throw std::invalid_argument("Choose other value for steps count\n");
    }
    else if (mode != "detailed" && mode != "fast" && mode != "tournament") {
        throw std::invalid_argument("Choose existing mode\n");
    }
}