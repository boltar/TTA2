//
// Created by t on 3/21/2020.
//

#ifndef TTA_GAMEDECK_HPP
#define TTA_GAMEDECK_HPP

#include <vector>
#include "Card.hpp"

class GameDeck {

public:
    GameDeck() = delete;
    GameDeck(int num_players);

    Card Draw();
    const int GetCardsRemaining();

private:
    std::vector<Card> age[4];

};


#endif //TTA_GAMEDECK_HPP
