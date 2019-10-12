//
// Created by t on 9/29/2019.
//

#ifndef TTA_PLAYER_H
#define TTA_PLAYER_H
#include <string>
#include "Building.h"
using namespace std;

class Player {

public:
//    explicit Player() = delete;
    explicit Player(string name) : name(name) {}

    void EndTurn();
    void ProductionPhase();

    string GetName() { return name;}
    int GetFoodProduction();
    int GetRockProduction() {return mine.GetRocksProduced();}
    int GetCultureProduction() {return theater[0] * 2 + theater[1] * 3 + theater[2] * 4 +
                                       library[0] + library[1]*2 + library[2]*3 +
                                       temple[0] + temple[1] + temple[2];}
    int GetScienceProduction() {return lab[0] + lab[1] * 2 + lab[2] * 3 + lab[3] * 5 +
                                       library[0] + library[1]*2 + library[2]*3;}
    int GetHappy() {return temple[0] + temple[1]*2 + temple[2]*3 +
                           arena[0]*2 + arena[1]*3 + arena[2]*4 +
                           theater[0] + theater[1] + theater[2];}

    void BuildFarm(int farmLevel);
    void DevelopFarmTech(int farmLevel);
    int GetIdleWorkers() { return idle_worker;}
    int GetRocks() {return rock;}
    int GetFood() {return food;}
    int GetScience() {return science;}
    int GetCulture() {return culture;}

private:
    string name;
    int ca = 4;
    int ma = 2;
    int food = 0;
//    int food_rating;
    int rock = 0;
//    int rock_rating;
    int science = 0;
    int science_rating = 0;
    int culture = 0;
    int culture_rating = 0;
    int idle_worker = 1;
    int blue_tokens = 16;       // not in use
    int yellow_tokens = 18;     // not counting idle

//    Farm farm[4] = {2, 0, 0, 0}; // agriculture, irrigation, selective breeding, mechanized ag
    Building farm = Building(farmStats);
    Building mine = Building(farmStats);
    bool farm_tech[4] = {false, false, false, false};
//    int mine[4] = {2, 0, 0, 0}; // bronze, iron, coal, oil
    int lab[4] = {1, 0, 0, 0};  // philosophy, alchemy, scientific method, computers
    int temple[3] = {0,0,0};    // religion, theology, organized religion
    int arena[3] = {0,0,0};     // Bread and circuses, team sports, professional sports
    int library[3] = {0,0,0};   // printing press, journalism, multimedia
    int theater[3] = {0,0,0};   // drama, opera, movies
};


#endif //TTA_PLAYER_H
