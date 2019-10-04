//
// Created by t on 9/28/2019.
//

#include "gtest/gtest.h"
#include "../Player.h"

class PlayerTest : public ::testing::Test {

public:
    PlayerTest():player(Player("Alice")) {
    }

protected:
    void SetUp() override {
        Player player("Alice");
    }

    // void TearDown() override {}
    void TearDown() override {

    }

private:
    void TestBody() override;

protected:

    Player player;

};

//TEST_F(PlayerTest, test_initial_conditions) {
//
//
//    // test initial conditions
//    EXPECT_EQ(player.GetName(), "Alice");
//    EXPECT_EQ(player.GetFoodProduction(), 2);
//    EXPECT_EQ(player.GetRockProduction(), 2);
//    EXPECT_EQ(player.GetCultureProduction(), 0);
//    EXPECT_EQ(player.GetScienceProduction(), 1);
//    EXPECT_EQ(player.GetIdleWorkers(), 1);
//
//}


//TEST_F(PlayerTest, test_production_phase) {
//
//    // test after 1st turn
//    player.EndTurn();
//    EXPECT_EQ(player.GetFoodProduction(), 2);
//    EXPECT_EQ(player.GetRockProduction(), 2);
//    EXPECT_EQ(player.GetCultureProduction(), 0);
//    EXPECT_EQ(player.GetScienceProduction(), 1);
//
//}
//
//TEST_F(PlayerTest, test_production_phase_after_1_farm) {
//    player.BuildFarm(0); // 0, 1, 2, 3
//    player.EndTurn();
//
//    EXPECT_EQ(player.GetRocks(), 0);
//    EXPECT_EQ(player.GetIdleWorkers(), 0);
//    EXPECT_EQ(player.GetFoodProduction(), 3);
//    EXPECT_EQ(player.GetRockProduction(), 2);
//    EXPECT_EQ(player.GetCultureProduction(), 0);
//    EXPECT_EQ(player.GetScienceProduction(), 1);
//
//}