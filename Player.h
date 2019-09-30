//
// Created by t on 9/29/2019.
//

#ifndef TTA_PLAYER_H
#define TTA_PLAYER_H
#include <string>
using namespace std;

class Player {

public:
    Player(string name) : name(name), ca(4), ma(2), farm{2, 0, 0, 0},
    mine{2, 0, 0, 0}, lab{1, 0, 0, 0}, idle_worker(1), blue_tokens(16), yellow_tokens(18) {};

    endTurn();
private:
    string name;
    int ca;
    int ma;
    int food;
    int food_rating;
    int rock;
    int rock_rating;
    int science;
    int science_rating;
    int culture;
    int culture_rating;
    int idle_worker;
    int blue_tokens;            // not in use
    int yellow_tokens;          // not counting idle

    int farm[4];                // agriculture, irrigation, selective breeding, mechanized ag
    int mine[4];                // bronze, iron, coal, oil
    int lab[4];                 // philosophy, alchemy, scientific method, computers
    int temple[3];              // religion, theology, organized religion
    int arena[3];               // Bread and circuses, team sports, professional sports
    int library[3];             // printing press, journalism, multimedia
    int theater[3];             // drama, opera, movies
};


#endif //TTA_PLAYER_H
