//
// Created by t on 9/29/2019.
//

#ifndef TTA_PLAYER_H
#define TTA_PLAYER_H
#include <string>
#include <map>
#include "Building.h"
#include "GameEngine.h"

using namespace std;

class Player {

public:
//    explicit Player() = delete;
    explicit Player(string name) : name(name), farm(FarmStats::GetInstance()), mine(MineStats::GetInstance()) {

        farm.DevelopTech(0);
        mine.DevelopTech(0);

        farm.Build(0);
        farm.Build(0);
        mine.Build(0);
        mine.Build(0);

    }

    void EndTurn();
    void ProductionPhase();

    string GetName() { return name;}
    int GetFoodProduction() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += farm.GetFoodProduced(i) * farm.GetBuilt(i);
        }
        return total;
    }
    int GetRockProduction() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += mine.GetRocksProduced(i) * mine.GetBuilt(i);
        }
        return total;
    }
    int GetScienceProduction() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
//            total += lab.GetScienceProduced(i) * lab.GetBuilt(i);
        }
        return total;

    }

//    int GetCultureProduction() {return theater[0] * 2 + theater[1] * 3 + theater[2] * 4 +
//                                       library[0] + library[1]*2 + library[2]*3 +
//                                       temple[0] + temple[1] + temple[2];}
//    int GetHappy() {return temple[0] + temple[1]*2 + temple[2]*3 +
//                           arena[0]*2 + arena[1]*3 + arena[2]*4 +
//                           theater[0] + theater[1] + theater[2];}


    void BuildFarm(int farmLevel);
    void BuildMine(int level);

    void Build(Building& b, int level);
    void DevelopFarmTech(int farmLevel);
    int GetIdleWorkers() { return idle_worker;}
    int GetRocks() {return rock;}
    int GetFood() {return food;}
    int GetScience() {return science;}
    int GetCulture() {return culture;}
    void IncreasePop();
    map<BuildingType, bool [Const::MaxBuildingLevels]> tech;
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

    Building farm, mine;
    bool farm_tech[4] = {true, false, false, false};
    bool mine_tech[4] = {true, false, false, false};

};


#endif //TTA_PLAYER_H
