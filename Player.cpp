//
// Created by t on 9/29/2019.
//

#include "Player.hpp"
#include "GameEngine.hpp"

void Player::StartTurn() {
    ResetActions();
}
void Player::EndTurn() {

// discard military cards if needed
// determine uprising
// if no uprising, then do production phase

    // draw military cards, if military actions available
    if (!GameEngine::GetAngryWorkers(GameEngine::GetDiscontentWorkers(yellow_tokens, GetHappy()), idle_worker)){
        ProductionPhase();

    }

}

void Player::ProductionPhase() {
    int corruption = GameEngine::CalculateCorruption(blue_tokens);
    if (rock >= corruption) {
        rock -= corruption;
    } else if (rock + food >= corruption) {
        // couldn't pay for corruption with rock only, so involve food
        corruption -= rock;
        rock = 0; // remove all rock
        food -= corruption; // remove the rest in food
    } else {
        // couldn't pay for corruption with rock and food, so pay with food
        food -= corruption;
        if (food < 0)
            food = 0;
    }

    food += GetFoodProduction();
    food -= GameEngine::GetFoodConsumed(yellow_tokens);
    // evaluate starvation
    rock += GetRockProduction();
    science += GetScienceProduction();
    culture += GetCultureProduction();

}

Status Player::Build(Building& b, int level) {

    if (!ca) {
        return Status::NOT_ENOUGH_CIVIL_ACTIONS;
    }

    if (!idle_worker) {
//        BOOST_ASSERT_MSG(0, "must have at least one idle worker");
        return Status::NOT_ENOUGH_IDLE_WORKERS;
    }

    if (!b.isTechDeveloped(level)) {
//        BOOST_ASSERT_MSG(0, "not able to build that level of building");
        return Status::NO_TECH_DEVELOPED;
    }

    if (rock < b.GetRockCostToBuild(level)) {
//        BOOST_ASSERT_MSG(0, "not enough rocks");
        return Status::NOT_ENOUGH_ROCKS;
    }

    b.Build(level);
    rock -= b.GetRockCostToBuild(level);
    idle_worker--;
    UseCA();
    return Status::OK;
}
Status Player::BuildTemple(int level) {
    return Build(temple, level);
}

Status Player::BuildFarm(int level) {
    return Build(farm, level);
}

Status Player::BuildMine(int level) {
    return Build(mine, level);
}

Status Player::BuildArena(int level) {
    return Build(arena, level);
}
Status Player::BuildLibrary(int level) {
    return Build(library, level);
}

Status Player::BuildLab(int level) {
    return Build(lab, level);
}
Status Player::BuildTheater(int level) {
    return Build(theater, level);
}


Status Player::IncreasePop() {

//    BOOST_ASSERT_MSG(yellow_tokens, "not enough yellow tokens left");
    if (!yellow_tokens) {
        return Status::NO_YELLOW_TOKENS_LEFT;
    }

    if (GameEngine::GetCostToIncreasePopulation(yellow_tokens) <= GetFood()) {
        yellow_tokens--;
        idle_worker++;
        food -= GameEngine::GetCostToIncreasePopulation(yellow_tokens);
    }

    return Status::OK;
}

Status Player::DevelopTech(Building& b, int level) {
    if (b.GetScienceCostToBuild(level) == Const::InvalidTech) {
        return Status::INVALID_TECH;
    }
    if (b.GetScienceCostToBuild(level) > science) {
        return Status::NOT_ENOUGH_SCIENCE;
    }
    b.DevelopTech(level);
    science -= b.GetScienceCostToBuild(level);
    return Status::OK;
}

Status Player::DevelopLab(int level) {
    return DevelopTech(lab, level);
}
Status Player::DevelopMine(int level) {
    return DevelopTech(mine, level);
}
Status Player::DevelopFarm(int level) {
    return DevelopTech(farm, level);
}
Status Player::DevelopLibrary(int level) {
    return DevelopTech(library, level);
}
Status Player::DevelopTheater(int level) {
    return DevelopTech(theater, level);
}
Status Player::DevelopTemple(int level) {
    return DevelopTech(temple, level);
}
Status Player::DevelopArena(int level) {
    return DevelopTech(arena, level);
}
