//
// Created by t on 3/21/2020.
//

#include "GameDeck.hpp"
#include "Card.hpp"
/*
  Cards to be removed are marked in the upper right corner:
  For a 3-player game, remove the 3 cards
    marked Republic 4 from each deck.
  For a 2-player game, remove the 6 cards
    marked Monarchy 3+ and the 3 cards marked Republic 4 from
    each deck
 */
GameDeck::GameDeck(int num_players) {
//    age[0].push_back(new RichLandA());
//    age[0].push_back(RichLandA());
//    age[0].push_back(FrugalityA());
//    age[0].push_back(FrugalityA());
//    age[0].push_back(UrbanGrowthA());
//    age[0].push_back(UrbanGrowthA());
//    age[0].push_back(CulturalHeritageA());
    age[0].push_back(make_unique<StockPileA>());
//    age[0].push_back(Patriotism());
    //age[0].push_back(EngineeringGeniusA());
//    age[0].push_back(RichLandA());
//    age[0].push_back(RichLandA());
//    age[0].push_back(FrugalityA());
//    age[0].push_back(FrugalityA());
//    age[0].push_back(UrbanGrowthA());
//    age[0].push_back(UrbanGrowthA());
//    age[0].push_back(CulturalHeritageA());
//    age[0].push_back(StockPileA());
//    age[0].push_back(Patriotism()); // 18 cards for now
}

