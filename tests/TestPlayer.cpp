//
// Created by t on 9/28/2019.
//

#include "gtest/gtest.h"
#include "../Player.h"

class PlayerTest : public ::testing::Test {

public:

protected:

    void SetUp() override {
//    cout << "SetUp Alice" << endl;
        player = new Player("Alice");
    }

    void SetUp(string name) {
//    cout << "SetUp Bob" << endl;
        player = new Player(name);
    }

    // void TearDown() override {}
    void TearDown() override {

    }

protected:

    Player *player;

};

TEST_F(PlayerTest, test_initial_conditions) {

    // test initial conditions
    EXPECT_EQ(player->GetName(), "Alice");
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetIdleWorkers(), 1);
}


TEST_F(PlayerTest, test_production_phase) {

    // test after 1st turn (selecting initial cards)
    player->EndTurn();
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);

}

TEST_F(PlayerTest, test_production_phase_after_1_farm) {
    player->EndTurn(); //initial card draw

    // first real turn
    player->BuildFarm(0);
    player->EndTurn();

    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 3);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 2);
}

TEST_F(PlayerTest, test_production_phase_after_2_farms) {
    player->EndTurn(); //initial card draw

    // first real turn
    player->BuildFarm(0);
    player->EndTurn();

    // second turn
    player->IncreasePop();
    player->BuildFarm(0);
    player->EndTurn();

    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 4);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);
}

