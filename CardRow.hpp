//
// Created by t on 3/21/2020.
//

#ifndef TTA_CARDROW_HPP
#define TTA_CARDROW_HPP

#include "Card.hpp"
#include "GameDeck.hpp"
#include <vector>
#include <boost/assert.hpp>

class CardRow {
public:
    CardRow() = delete;
    CardRow(GameDeck &game_deck): deck(deck) {};

    int TakeCard(int index) {
        BOOST_ASSERT_MSG(index < MAX_CARDS_IN_ROW, "index must be less than " + MAX_CARDS_IN_ROW);
        if (index >= MAX_CARDS_IN_ROW) {
            return -1;
        }
        return 0;
    }

    constexpr int CostToTake(int index) {
        BOOST_ASSERT_MSG(index < MAX_CARDS_IN_ROW, "index must be less than " + MAX_CARDS_IN_ROW);
        if (index >= MAX_CARDS_IN_ROW) {
            return -1;
        }

        if (index < CARDS_IN_FIRST_SECTION) {
            return 1;
        }
        if (index < CARDS_IN_FIRST_SECTION + CARDS_IN_SECOND_SECTION) {
            return 2;
        }
        if (index < CARDS_IN_FIRST_SECTION + CARDS_IN_SECOND_SECTION + CARDS_IN_THIRD_SECTION) {
            return 3;
        }

        return -1;
    }

private:
    std::vector<Card> row;
    std::vector<Card> &deck;

    static constexpr int CARDS_IN_FIRST_SECTION = 5;
    static constexpr int CARDS_IN_SECOND_SECTION = 4;
    static constexpr int CARDS_IN_THIRD_SECTION = 4;
    static constexpr int MAX_CARDS_IN_ROW = CARDS_IN_FIRST_SECTION + CARDS_IN_SECOND_SECTION + CARDS_IN_THIRD_SECTION; // 13
};


#endif //TTA_CARDROW_HPP
