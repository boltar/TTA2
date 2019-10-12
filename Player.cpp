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
    BOOST_ASSERT_MSG(idle_worker > 0, "must have atleast one idle worker");
    BOOST_ASSERT_MSG(rock >= farm.GetRockCostToBuild(farmLevel), "not enough rocks");
    BOOST_ASSERT_MSG(farm_tech[farmLevel], "not able to build that level of farm");
    farm.Build(farmLevel);
    idle_worker--;
}

void Player::DevelopFarmTech(int farmLevel) {
    BOOST_ASSERT_MSG(science >= farm.GetScienceCostToBuild(farmLevel), "not enough science");

}
int Player::GetFoodProduction() {
    return farm.GetFoodProduced();
}
