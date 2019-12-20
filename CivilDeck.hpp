//
// Created by t on 12/19/2019.
//

#ifndef TTA_CIVILDECK_HPP
#define TTA_CIVILDECK_HPP

#include <vector>
#include "Card.hpp"

class CivilDeck {
public:
    CivilDeck() = default;
private:
    std::vector<CivilCard> deck;
};


#endif //TTA_CIVILDECK_HPP
