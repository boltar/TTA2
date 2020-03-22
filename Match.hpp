//
// Created by t on 10/16/2019.
//

#ifndef TTA_MATCH_HPP
#define TTA_MATCH_HPP

#include <vector>
#include <memory>
#include "Player.hpp"
#include "GameDeck.hpp"
#include "CardRow.hpp"
class Match {

public:
    Match() = delete;

    Match(vector<Player> &v) : players(v), deck(new GameDeck(v.size())) {
        card_row.reset(new CardRow(*deck));
    }


    void StartMatch();

    void AdvanceTurn();

    vector<Player> &GetPlayers() { return players; }

private:
    vector<Player> &players;
    //Player &current_player;
    int currentRound;
    std::unique_ptr<GameDeck> deck;
    std::unique_ptr<CardRow> card_row;

};


#endif //TTA_MATCH_HPP
