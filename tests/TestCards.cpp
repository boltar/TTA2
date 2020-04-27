//
// Created by t on 12/19/2019.
//

#include "gtest/gtest.h"
#include "../Card.hpp"

class CardTest : public ::testing::Test {
protected:
    void SetUp() override {
        pPlayer = make_unique<Player>("Bob");
    }

    // void TearDown() override {}
    void TearDown() override {

    }
    unique_ptr<Player> pPlayer;
//    CivilDeck *civilDeck;
};

TEST_F(CardTest, test_stock_pile_a) {

    StockPileA card;
//    Player player("Bob");

    card.Activate(*(pPlayer.get()));

    EXPECT_EQ(pPlayer->GetRocks(), 1);
    EXPECT_EQ(pPlayer->GetFood(), 1);

}

TEST_F(CardTest, test_cultural_heritage) {

    CulturalHeritageA card;

    card.Activate(*(pPlayer.get()));

    EXPECT_EQ(pPlayer->GetScience(), 1);
    EXPECT_EQ(pPlayer->GetCulture(), 4);

}

TEST_F(CardTest, test_frugality_a) {
    FrugalityA card;

    pPlayer->AddFood(2);
    int currIdle = pPlayer->GetIdleWorkers();
    card.Activate(*(pPlayer.get()));

    EXPECT_EQ(pPlayer->GetIdleWorkers(), currIdle + 1);
}