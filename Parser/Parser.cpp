//
// Created by я on 06.11.2022.
//
#include "Parser.h"

Parser::Parser(int argc, char** argv) {
    po::options_description desc("Generate parameters");
    desc.add_options()
            ("help", "produce help message")
            ("mode", po::value<std::string> (&mode), "--mode=[detailed|fast|tournament]")
            ("strategy", po::value< std::vector<std::string> >(&name), "--strategy={ALWAYS_C|ALWAYS_D|RANDOM_MOVE|TIT_FOR_TAT}")
            ("steps", po::value<int>(&count_of_steps)->default_value(10), "--steps")
            ("configs, c", po::value<std::vector<std::string>  >(&conf_files), "--configs[conf4.txt]")
            ("matrix", po::value<std::string> (&matrix_file), "--matrix[Matrix.txt] .txt")
    ;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

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