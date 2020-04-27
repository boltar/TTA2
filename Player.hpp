//
// Created by t on 9/29/2019.
//

#ifndef TTA_PLAYER_HPP
#define TTA_PLAYER_HPP
#include <string>
#include <map>
#include <boost/assert.hpp>
#include "Building.hpp"
#include "GameEngine.hpp"

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

    void StartTurn();
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
            total += library.GetScienceProduced(i) * library.GetBuilt(i);
        }
        return total;

    }
    int GetCultureProduction() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += temple.GetCultureProduced(i) * temple.GetBuilt(i);
            total += theater.GetCultureProduced(i) * theater.GetBuilt(i);
            total += library.GetCultureProduced(i) * library.GetBuilt(i);
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
            total += temple.GetHappinessProvided(i) * temple.GetBuilt(i);
            total += arena.GetHappinessProvided(i) * arena.GetBuilt(i);
            total += theater.GetHappinessProvided(i) * theater.GetBuilt(i);
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

    Status DevelopTemple(int level);
    Status DevelopTheater(int farmLevel);
    Status DevelopMine(int level);
    Status DevelopFarm(int level);
    Status DevelopArena(int level);
    Status DevelopLab(int level);
    Status DevelopLibrary(int level);


    int GetIdleWorkers() { return idle_worker;}
    int GetRocks() {return rock;}

    void AddRocks(int r) {
        BOOST_ASSERT_MSG(rock + r >= 0, "sum must be >= 0");
        rock += r;
    }

    void AddFood(int f) {
        BOOST_ASSERT_MSG(food + f >= 0, "sum must be >= 0");
        food += f;
    }

    void AddCulture(int c) {
        BOOST_ASSERT_MSG(culture + c >= 0, "sum must be >= 0");
        culture += c;
    }

    void AddScience(int s) {
        BOOST_ASSERT_MSG(science + s >= 0, "sum must be >= 0");
        science += s;
    }

    int GetFood() {return food;}
    int GetScience() {return science;}
    int GetCulture() {return culture;}
    Status CanIncreasePop();
    Status IncreasePop();
    int GetMA() {return ma;}
    int GetCA() {return ca;}
    int getMAMax() {return ma_max;}
    int getCAMax() {return ca_max;}
    void UseCA() {BOOST_ASSERT_MSG(ca, "CA is ZERO"); ca--;}
    void UseMA() {BOOST_ASSERT_MSG(ma, "MA is ZERO"); ma--;}
    void ResetActions() {ca = ca_max; ma = ma_max;}
    map<BuildingType, bool [Const::MaxBuildingLevels]> tech;
private:
    string name;
    int ca = 4; // civil actions
    int ma = 2; // military actions
    int ca_max = 4;
    int ma_max = 2;
    int food = 0;
    int rock = 0;
    int science = 0;
    int culture = 0;
    int idle_worker = 1;
    int blue_tokens = 16;       // not in use
    int yellow_tokens = 18;     // not counting idle

    Building farm, mine, lab, temple, library, theater, arena;
    bool farm_tech[4] = {true, false, false, false};
    bool mine_tech[4] = {true, false, false, false};
    Status Build(Building& b, int level);
    Status DevelopTech(Building &b, int level);

};


#endif //TTA_PLAYER_HPP
