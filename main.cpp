#include "GameModes/ClassGame.h"

int main(int argc, char **argv) {
    try {
        Game(argc, argv);
    } catch(std::string s) {
        std::cout << "Choose another arguments" << std::endl;
        std::cout << s << std::endl;
    }
    return 0;
}
