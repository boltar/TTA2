//
// Created by t on 9/28/2019.
//

#include "gtest/gtest.h"
#include "../GameEngine.h"

class GameEngineTest : public ::testing::Test {
protected:
    void SetUp() override {

    }

    // void TearDown() override {}
    void TearDown() override {

    }

};

TEST(basic_check, test_eq) {
    EXPECT_EQ(1, 1);
}

TEST(GameEngineTest, test_food_consumed) {

    EXPECT_EQ(GameEngine::GetFoodConsumed(18), 0);
    EXPECT_EQ(GameEngine::GetFoodConsumed(17), 0);
    EXPECT_EQ(GameEngine::GetFoodConsumed(16), 1);
    EXPECT_EQ(GameEngine::GetFoodConsumed(15), 1);
    EXPECT_EQ(GameEngine::GetFoodConsumed(14), 1);
    EXPECT_EQ(GameEngine::GetFoodConsumed(13), 1);
    EXPECT_EQ(GameEngine::GetFoodConsumed(12), 2);
    EXPECT_EQ(GameEngine::GetFoodConsumed(11), 2);
    EXPECT_EQ(GameEngine::GetFoodConsumed(10), 2);
    EXPECT_EQ(GameEngine::GetFoodConsumed(9), 2);
    EXPECT_EQ(GameEngine::GetFoodConsumed(8), 3);
    EXPECT_EQ(GameEngine::GetFoodConsumed(7), 3);
    EXPECT_EQ(GameEngine::GetFoodConsumed(6), 3);
    EXPECT_EQ(GameEngine::GetFoodConsumed(5), 3);
    EXPECT_EQ(GameEngine::GetFoodConsumed(4), 4);
    EXPECT_EQ(GameEngine::GetFoodConsumed(3), 4);
    EXPECT_EQ(GameEngine::GetFoodConsumed(2), 4);
    EXPECT_EQ(GameEngine::GetFoodConsumed(1), 4);
    EXPECT_EQ(GameEngine::GetFoodConsumed(0), 6);
}

TEST(GameEngineTest, test_cost_to_increase_population) {
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(18), 2);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(17), 2);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(16), 3);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(15), 3);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(14), 3);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(13), 3);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(12), 4);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(11), 4);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(10), 4);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(9), 4);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(8), 5);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(7), 5);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(6), 5);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(5), 5);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(4), 7);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(3), 7);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(2), 7);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(1), 7);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(0), -1);
}
TEST(GameEngineTest, test_happy_faces_required) {
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(18), 0);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(17), 0);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(16), 1);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(15), 1);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(14), 1);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(13), 1);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(12), 2);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(11), 2);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(10), 2);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(9), 2);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(8), 4);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(7), 4);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(6), 4);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(5), 4);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(4), 6);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(3), 6);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(2), 6);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(1), 6);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(0), 8);
}

//  4   4   4   4   4    2
// ___ ___ ___ ___ ___ |    |
// -6  -4  -3  -2  -1  |    |    consumption
//     7   5   4   3   | 2  |    cost to increase pop
// 2   2   2   1   1   |    |    happy faces

TEST(GameEngineTest, test_discontent_workers) {
    int answers[19][9] = { {8, 7, 6, 5, 4, 3, 2, 1, 0},  // 0 yellow tokens, 0-8 happy faces
                           {6, 5, 4, 3, 2, 1, 0, 0, 0},  // 1 yellow token
                           {6, 5, 4, 3, 2, 1, 0, 0, 0},  // 2 yellow token
                           {6, 5, 4, 3, 2, 1, 0, 0, 0},  // 3 yellow token
                           {6, 5, 4, 3, 2, 1, 0, 0, 0},  // 4 yellow token
                           {4, 3, 2, 1, 0, 0, 0, 0, 0},  // 5 yellow token
                           {4, 3, 2, 1, 0, 0, 0, 0, 0},  // 6 yellow token
                           {4, 3, 2, 1, 0, 0, 0, 0, 0},  // 7 yellow token
                           {4, 3, 2, 1, 0, 0, 0, 0, 0},  // 8
                           {2, 1, 0, 0, 0, 0, 0, 0, 0},  //9
                           {2, 1, 0, 0, 0, 0, 0, 0, 0},  //10
                           {2, 1, 0, 0, 0, 0, 0, 0, 0},  //11
                           {2, 1, 0, 0, 0, 0, 0, 0, 0},  //12
                           {1, 0, 0, 0, 0, 0, 0, 0, 0},  //13
                           {1, 0, 0, 0, 0, 0, 0, 0, 0},  //14
                           {1, 0, 0, 0, 0, 0, 0, 0, 0},  //15
                           {1, 0, 0, 0, 0, 0, 0, 0, 0},  //16
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},  //17
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},  //18
    };

    for (int yellow_tokens = 0; yellow_tokens <19; yellow_tokens++) {
        for (int happy_faces = 0; happy_faces < 9; happy_faces++) {
            EXPECT_EQ(GameEngine::GetDiscontentWorkers(yellow_tokens, happy_faces),
                    answers[yellow_tokens][happy_faces]);
        }
    }

}

//  4   4   4   4   4    2
// ___ ___ ___ ___ ___ |    |
// -6  -4  -3  -2  -1  |    |    consumption
//     7   5   4   3   | 2  |    cost to increase pop
// 2   2   2   1   1   |    |    happy faces

TEST(GameEngineTest, test_angry_workers) {
    int answers[9][19] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 0 discontented workers, 0 - 18 idle workers
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 1 discontented workers
                           {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 2 discontented workers
                           {3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 3 discontented workers
                           {4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 4 discontented workers
                           {5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 5 discontented workers
                           {6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6 discontented workers
                           {7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 7 discontented workers
                           {8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 8 discontented workers
    };

    for (int disconted_workers = 0; disconted_workers <9; disconted_workers++) {
        for (int idle_workers = 0; idle_workers < 19; idle_workers++) {
            EXPECT_EQ(GameEngine::GetAngryWorkers(disconted_workers, idle_workers),
                      answers[disconted_workers][idle_workers]);
        }
    }
}