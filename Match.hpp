//
// Created by t on 10/16/2019.
//

#ifndef TTA_MATCH_HPP
#define TTA_MATCH_HPP

#include <vector>
#include "Player.hpp"
class Match {

public:
    Match() = delete;
    Match(vector<Player>& v): v(v) {}


    void StartMatch();
    void MainLoop();
    vector<Player>& GetPlayers() { return v;}
private:
    vector<Player>& v;
};


#endif //TTA_MATCH_HPP
