//
// Created by t on 9/29/2019.
//

#include "Player.h"
#include "GameEngine.h"
#include <boost/assert.hpp>

void Player::EndTurn() {

// discard military cards if needed
// determine uprising
// if no uprising, then do production phase

// draw military cards, if military actions available
// if not uprising
    ProductionPhase();
}

void Player::ProductionPhase() {
    science += science_rating;
    culture += culture_rating;
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

void Player::BuildFarm(int farmLevel) {
    if (!idle_worker) {
        BOOST_ASSERT_MSG(0, "must have at least one idle worker");
        return;
    }

    if (rock < farm.GetRockCostToBuild(farmLevel)) {
        BOOST_ASSERT_MSG(0, "not enough rocks");
        return;
    }

    if (!farm_tech[farmLevel]) {
        BOOST_ASSERT_MSG(0, "not able to build that level of farm");
    }
    farm.Build(farmLevel);
    rock -= farm.GetRockCostToBuild(farmLevel);
    idle_worker--;
}

void Player::DevelopFarmTech(int farmLevel) {
    BOOST_ASSERT_MSG(science >= farm.GetScienceCostToBuild(farmLevel), "not enough science");

}
int Player::GetFoodProduction() {
    return farm.GetFoodProduced();
}

void Player::IncreasePop() {

    BOOST_ASSERT_MSG(yellow_tokens, "not enough yellow tokens left");
    if (!yellow_tokens) return;

    if (GameEngine::GetCostToIncreasePopulation(yellow_tokens) <= GetFood()) {
        yellow_tokens--;
        idle_worker++;
    }
}