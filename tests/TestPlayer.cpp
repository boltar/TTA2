//
// Created by t on 9/28/2019.
//

#include "gtest/gtest.h"
#include "../Player.hpp"
#include "../GameEngine.hpp"

/* First two (real) turn scenarios
 * A = build farm
 * B = build mine
 * C = build lab
 * D = build temple
 * E = nothing
 *
 * 1. A A
 * 2. A B
 * 3. B A
 * 4. B B
 * 5. B C
 * 6. B D
 * 7. E C
 * 8. E D
 * 9. E E
 *
 */
class InitialPhaseTest : public ::testing::Test {
public:
protected:
    void SetUp() override {
        player = new Player("Alice");
    }
    void TearDown() override { }
protected:

    Player *player;

};

class FirstPhaseTestBuildingFarm : public ::testing::Test {
public:
protected:
    void SetUp() override {
        player = new Player("Alice");
        player->EndTurn();

        player->StartTurn();
        player->BuildFarm(0);
        player->EndTurn();
    }
    void TearDown() override { }
protected:
    Player *player;
};

class FirstPhaseTestBuildingMine: public ::testing::Test {
public:
protected:
    void SetUp() override {
        player = new Player("Alice");
        player->EndTurn();

        player->StartTurn(); // real first turn
        player->BuildMine(0);
        player->EndTurn();
    }
    void TearDown() override { }
protected:
    Player *player;
};


TEST_F(InitialPhaseTest, test_initial_conditions) {

    // test initial conditions
    EXPECT_EQ(player->GetName(), "Alice");
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetIdleWorkers(), 1);
    EXPECT_EQ(GameEngine::GetFoodConsumed(player->GetYellowTokens()), 0);
    EXPECT_EQ(GameEngine::GetCostToIncreasePopulation(player->GetYellowTokens()), 2);
    EXPECT_EQ(GameEngine::GetHappyFacesRequired(player->GetYellowTokens()), 0);
    int discontent_workers = GameEngine::GetDiscontentWorkers(player->GetYellowTokens(), player->GetHappy());
    EXPECT_EQ(discontent_workers, 0);
    EXPECT_EQ(GameEngine::GetAngryWorkers(discontent_workers, player->GetIdleWorkers()), 0);
    EXPECT_EQ(GameEngine::CalculateCorruption(player->GetBlueTokens()), 0);
}


TEST_F(InitialPhaseTest, test_production_phase) {

    // test after 1st turn (selecting initial cards)
    player->EndTurn();
    EXPECT_EQ(player->GetFood(), 2);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetFood(), 2);
    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);

}

TEST_F(FirstPhaseTestBuildingFarm, test_production_phase_after_1_farm) {
    EXPECT_EQ(player->GetFood(), 5);
    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 3);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 2);
    EXPECT_EQ(player->GetCA(), 3);
}

TEST_F(FirstPhaseTestBuildingFarm, build_2nd_farm) {

    EXPECT_EQ(player->IncreasePop(), Status::OK);
    player->BuildFarm(0);
    player->EndTurn();

    EXPECT_EQ(player->GetRocks(), 2);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 4);
    EXPECT_EQ(player->GetFood(), 7);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 2);
}


TEST_F(FirstPhaseTestBuildingMine, test_production_phase_after_1_mine) {

    EXPECT_EQ(player->GetRocks(), 3);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 3);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 2);
    EXPECT_EQ(player->GetCA(), 3);
}

TEST_F(FirstPhaseTestBuildingMine, build_2nd_mine) {

    EXPECT_EQ(player->IncreasePop(), Status::OK);
    player->BuildMine(0);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 5);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 4);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 2);
}

TEST_F(FirstPhaseTestBuildingMine, build_lab) {

    EXPECT_EQ(player->IncreasePop(), Status::OK);
    player->BuildLab(0);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 3);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 3);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 2);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 4);
    EXPECT_EQ(player->GetCA(), 2);
}

TEST_F(FirstPhaseTestBuildingMine, build_temple) {

    EXPECT_EQ(player->IncreasePop(), Status::OK);
    EXPECT_EQ(player->BuildTemple(0), Status::OK);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 3);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 3);
    EXPECT_EQ(player->GetCultureProduction(), 1);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 1);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 2);
}

TEST_F(FirstPhaseTestBuildingMine, attempt_to_build_invalid_buildings) {

    EXPECT_EQ(player->IncreasePop(), Status::OK);

    for (int i = 0; i < Const::MaxBuildingLevels; i++) {
        EXPECT_EQ(player->BuildArena(i), Status::NO_TECH_DEVELOPED);
        EXPECT_EQ(player->BuildTheater(i), Status::NO_TECH_DEVELOPED);
        EXPECT_EQ(player->BuildLibrary(i), Status::NO_TECH_DEVELOPED);
    }

    EXPECT_EQ(player->DevelopArena(0), Status::INVALID_TECH);
    EXPECT_EQ(player->DevelopTheater(0), Status::INVALID_TECH);
    EXPECT_EQ(player->DevelopLibrary(0), Status::INVALID_TECH);

    player->EndTurn(); //1 empty turn, 2 full turns
    EXPECT_EQ(player->GetRocks(), 6);
    EXPECT_EQ(player->GetIdleWorkers(), 1);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 3);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 3);
}


class FirstPhaseTestDoNothing: public ::testing::Test {
public:
protected:
    void SetUp() override {
        player = new Player("Alice");
        player->EndTurn();

        player->StartTurn(); // real first turn
        player->EndTurn(); // do nothing
    }
    void TearDown() override { }
protected:
    Player *player;
};

TEST_F(FirstPhaseTestDoNothing, build_mine) {

    EXPECT_EQ(player->BuildMine(0), Status::OK);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 5);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 3);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 3);
}

TEST_F(FirstPhaseTestDoNothing, build_farm) {

    EXPECT_EQ(player->BuildFarm(0), Status::OK);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 4);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 3);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetFood(), 7);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 3);
}

TEST_F(FirstPhaseTestDoNothing, build_lab) {

    EXPECT_EQ(player->BuildLab(0), Status::OK);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 3);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 0);
    EXPECT_EQ(player->GetScienceProduction(), 2);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 4);
    EXPECT_EQ(player->GetCA(), 3);
}

TEST_F(FirstPhaseTestDoNothing, build_temple) {

    EXPECT_EQ(player->BuildTemple(0), Status::OK);
    player->EndTurn();
    EXPECT_EQ(player->GetRocks(), 3);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetFoodProduction(), 2);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 1);
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 1);
    EXPECT_EQ(player->GetScience(), 3);
    EXPECT_EQ(player->GetCA(), 3);
}

TEST_F(FirstPhaseTestDoNothing, build_arena) {

    player->EndTurn(); // should have enough science to build library/arena
    int starting_rocks = 6;
    EXPECT_EQ(player->GetRocks(), starting_rocks);
    EXPECT_EQ(player->GetIdleWorkers(), 1);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);

    EXPECT_EQ(player->DevelopArena(0), Status::INVALID_TECH);
    EXPECT_EQ(player->DevelopArena(1), Status::OK);
    EXPECT_EQ(player->BuildArena(1), Status::OK);
    EXPECT_EQ(player->GetScience(), 0);
    EXPECT_EQ(player->GetRocks(), starting_rocks - ArenaStats::GetInstance().getRockCostToBuild()[1]);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    EXPECT_EQ(player->GetHappy(), 2);
}

TEST_F(FirstPhaseTestDoNothing, build_lib) {

    player->EndTurn(); // should have enough science to build library/arena
    int starting_rocks = 6;
    EXPECT_EQ(player->GetRocks(), starting_rocks);
    EXPECT_EQ(player->GetIdleWorkers(), 1);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);

    EXPECT_EQ(player->DevelopLibrary(0), Status::INVALID_TECH);
    EXPECT_EQ(player->DevelopLibrary(1), Status::OK);
    EXPECT_EQ(player->BuildLibrary(1), Status::OK);
    EXPECT_EQ(player->GetScience(), 0);
    EXPECT_EQ(player->GetRocks(), starting_rocks - LibraryStats::GetInstance().getRockCostToBuild()[1]);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    player->EndTurn();
    EXPECT_EQ(player->GetScienceProduction(), 2);
    EXPECT_EQ(player->GetCultureProduction(), 1);
    EXPECT_EQ(player->GetCulture(), 1);
    EXPECT_EQ(player->GetScience(), 2);
}

TEST_F(FirstPhaseTestDoNothing, build_theater) {

    player->EndTurn(); // should have enough science to build library/arena
    EXPECT_EQ(player->GetIdleWorkers(), 1);
    EXPECT_EQ(player->GetRockProduction(), 2);
    EXPECT_EQ(player->GetCulture(), 0);
    EXPECT_EQ(player->GetScience(), 3);

    EXPECT_EQ(player->DevelopTheater(0), Status::INVALID_TECH);
    EXPECT_EQ(player->DevelopTheater(1), Status::NOT_ENOUGH_SCIENCE);

    player->EndTurn();
    int starting_rocks = 8;
    EXPECT_EQ(player->DevelopTheater(1), Status::OK);
    EXPECT_EQ(player->BuildTheater(1), Status::OK);
    EXPECT_EQ(player->GetScience(), 0);
    EXPECT_EQ(player->GetRocks(), starting_rocks - TheaterStats::GetInstance().getRockCostToBuild()[1]);
    EXPECT_EQ(player->GetIdleWorkers(), 0);
    player->EndTurn();
    EXPECT_EQ(player->GetScienceProduction(), 1);
    EXPECT_EQ(player->GetCultureProduction(), 2);
    EXPECT_EQ(player->GetCulture(), 2);
    EXPECT_EQ(player->GetScience(), 1);
}

