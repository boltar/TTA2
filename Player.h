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
    explicit Player(string name) : name(name), farm(FarmStats::GetInstance()), mine(MineStats::GetInstance()),
            lab(LabStats::GetInstance()), temple(TempleStats::GetInstance()), arena(ArenaStats::GetInstance()),
            theater(TheaterStats::GetInstance()), library(LibraryStats::GetInstance()){

        // initial starting tech
        farm.DevelopTech(0);
        mine.DevelopTech(0);
        temple.DevelopTech(0);
        lab.DevelopTech(0);

        // initial starting buildings
        farm.Build(0);
        farm.Build(0);
        mine.Build(0);
        mine.Build(0);
        lab.Build(0);
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
            total += lab.GetScienceProduced(i) * lab.GetBuilt(i);
        }
        return total;

    }
    int GetCultureProduction() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += temple.GetCultureProduced(i) * temple.GetBuilt(i);
        }
        return total;
    }
    int GetMilitaryFromBuildings() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += arena.GetMilitaryProvided(i) * temple.GetBuilt(i);
        }
        return total;
    }

    int GetYellowTokens() {
        return yellow_tokens;
    }

    int GetBlueTokens() {
        return blue_tokens;
    }

    int GetHappy() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += temple.GetHappinessProvided(i) * temple.GetBuilt();
            total += arena.GetHappinessProvided(i) * arena.GetBuilt();
            total += theater.GetHappinessProvided(i) * theater.GetBuilt();
        }
        return total;
    }
    Status BuildTemple(int level);
    Status BuildFarm(int farmLevel);
    Status BuildMine(int level);
    Status BuildTheater(int level);
    Status BuildArena(int level);
    Status BuildLab(int level);
    Status BuildLibrary(int level);

    Status Build(Building& b, int level);
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

    Building farm, mine, lab, temple, library, theater, arena;
    bool farm_tech[4] = {true, false, false, false};
    bool mine_tech[4] = {true, false, false, false};

};


#endif //TTA_PLAYER_H
