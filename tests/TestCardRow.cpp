//
// Created by t on 3/21/2020.
//

#include "gtest/gtest.h"
#include "../Player.hpp"
#include "../CardRow.hpp"
#include "../GameDeck.hpp"

class CardRowTest : public ::testing::Test {
public:
protected:
    void SetUp() override {
        GameDeck deck(4);
        card_row = new CardRow(deck);
    }
    void TearDown() override { }
protected:

    CardRow *card_row;

};

TEST_F(CardRowTest, test_initial_conditions) {

    EXPECT_EQ(card_row->TakeCard(0), 0);
//    EXPECT_EQ(card_row->TakeCard(13), -1);
    EXPECT_EQ(card_row->CostToTake(0), 1);
    EXPECT_EQ(card_row->CostToTake(1), 1);
    EXPECT_EQ(card_row->CostToTake(5), 2);
    EXPECT_EQ(card_row->CostToTake(9), 3);
    EXPECT_EQ(card_row->CostToTake(12), 3);
//    EXPECT_EQ(card_row->CostToTake(13), -1);

}
