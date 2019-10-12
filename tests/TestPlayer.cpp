//
// Created by t on 9/28/2019.
//

#include "gtest/gtest.h"
#include "../Player.h"

class PlayerTest : public ::testing::Test {

public:

protected:

    void SetUp() override {
        player = new Player("Alice");
    }

    void SetUp(string name) {
        player = new Player(name);
    }

    // void TearDown() override {}
    void TearDown() override {

    }

protected:

    Player *player;

};

TEST_F(PlayerTest, test_initial_conditions) {

    SetUp("Bob");
    // test initial conditions
    EXPECT_EQ(player->GetName(), "Bob");
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetIdleWorkers(), 1);
}


TEST_F(PlayerTest, test_production_phase) {

    // test after 1st turn
    player->EndTurn();
    player->ProductionPhase();
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);

}

TEST_F(PlayerTest, test_production_phase_after_1_farm) {
    EXPECT_EQ(player->GetRocks(), 2); // player is alice, not bob?????? <-----------

    player->BuildFarm(0); // 0, 1, 2, 3
    player->ProductionPhase();
    player->EndTurn();

    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 3);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 1);
}

TEST_F(PlayerTest, test_production_phase_after_2_farms) {
    player->BuildFarm(0); // 0, 1, 2, 3
    player->ProductionPhase();
    player->EndTurn();

    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 4);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 1);
}

