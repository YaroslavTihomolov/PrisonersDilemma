//
// Created by я on 11.11.2022.
//
#include <gtest/gtest.h>
#include "GameModes/ClassGame.h"

TEST(Game, fast) {
    int argc = 13;
    char *argv[] = {"C", "--mode=fast", "--strategy=ALWAYS_C", "--strategy=ALWAYS_D", "--strategy=RANDOM_MOVE", "--strategy=TIT_FOR_TAT", "--strategy=GRIM_TRIGGER", "--strategy=META_STRATEGY", "--steps=10", "--matrix=Matrix.txt", "--configs=conf4.txt", "--configs=conf5.txt", "--configs=conf6.txt"};
    Game(argc, argv);
}

TEST(Game, tournament) {
    int argc = 13;
    char *argv[] = {"C", "--mode=fast", "--strategy=ALWAYS_C", "--strategy=ALWAYS_D", "--strategy=RANDOM_MOVE", "--strategy=TIT_FOR_TAT", "--strategy=GRIM_TRIGGER", "--strategy=META_STRATEGY", "--steps=10", "--matrix=Matrix.txt", "--configs=conf4.txt", "--configs=conf5.txt", "--configs=conf6.txt"};
    Game(argc, argv);
}

TEST(Game, exception_in_conf) {
    int argc = 13;
    char *argv[] = {"C", "--mode=fast", "--strategy=ALWAYS_C", "--strategy=ALWAYS_D", "--strategy=RANDOM_MOVE", "--strategy=TIT_FOR_TAT", "--strategy=GRIM_TRIGGER", "--strategy=META_STRATEGY", "--steps=10", "--matrix=Matrix.txt", "--configs=conf4.txt", "--configs=conf5.txt", "--configs=conf7.txt"};
    ASSERT_ANY_THROW( Game(argc, argv););
}

TEST(Game, exception_in_strategy) {
    int argc = 13;
    char *argv[] = {"C", "--mode=fast", "--strategy=ALWAYS_C", "--strategy=ALWAYS_", "--strategy=RANDOM_MOVE", "--strategy=TIT_FOR_TAT", "--strategy=GRIM_TRIGGER", "--strategy=META_STRATEGY", "--steps=10", "--matrix=Matrix.txt", "--configs=conf4.txt", "--configs=conf5.txt", "--configs=conf6.txt"};
    ASSERT_ANY_THROW( Game(argc, argv););
}

TEST(Game, exception_in_matrix) {
    int argc = 13;
    char *argv[] = {"C", "--mode=fast", "--strategy=ALWAYS_C", "--strategy=ALWAYS_", "--strategy=RANDOM_MOVE", "--strategy=TIT_FOR_TAT", "--strategy=GRIM_TRIGGER", "--strategy=META_STRATEGY", "--steps=10", "--matrix=matrix.txt", "--configs=conf4.txt", "--configs=conf5.txt", "--configs=conf6.txt"};
    ASSERT_ANY_THROW( Game(argc, argv););
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
