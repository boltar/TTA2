//
// Created by t on 10/16/2019.
//

#include "gtest/gtest.h"
#include "../GameEngine.hpp"
#include "../Player.hpp"
#include "../Match.hpp"

class TestMatch : public ::testing::Test {
protected:
    void SetUp() override {
        Player alice("Alice");
        Player bob("Bob");
        Player charles("Charles");
        Player eddie("Eddie");
        vector<Player> v = {alice, bob, charles, eddie};

        match = new Match(v);
    }

    // void TearDown() override {}
    void TearDown() override {

    }

    Match *match;
};

TEST_F(TestMatch, test_initial_conditions) {

    EXPECT_EQ(match->GetPlayers()[0].GetName(), "Alice");
    EXPECT_EQ(match->GetPlayers()[1].GetName(), "Bob");
    EXPECT_EQ(match->GetPlayers()[2].GetName(), "Charles");
    EXPECT_EQ(match->GetPlayers()[3].GetName(), "Eddie");
}

