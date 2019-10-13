//
// Created by t on 10/5/2019.
//

#ifndef TTA_BUILDING_H
#define TTA_BUILDING_H
#include <numeric>
#include "Constants.h"
#include "GameEngine.h"


class BuildingStats {
public:
    virtual BuildingType getBuildingType() const = 0;
    virtual array<int, 4> getRockCostToBuild() const = 0;
    virtual array<int, 4> getScienceCostToBuild() const = 0;
    virtual array<int, 4> getRocksProduced() const = 0;
    virtual array<int, 4> getFoodProduced() const = 0;
    virtual array<int, 4> getCultureProduced() const = 0;
    virtual array<int, 4> getScienceProduced() const = 0;
    virtual array<int, 4> getHappinessProvided() const = 0;
    virtual array<int, 4> getMilitaryProvided() const = 0;
};

class MineStats : public BuildingStats {

public:

    static MineStats& GetInstance() {
        static MineStats instance;
        return instance;
    }

    BuildingType getBuildingType() const override { return BuildingType::Mine;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{2, 5, 8, 11};}
    array<int, 4> getScienceCostToBuild() const override {return array<int, 4>{0, 5, 7, 9};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{1, 2, 3, 5};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};

class FarmStats : public BuildingStats {

public:

    static FarmStats& GetInstance() {
        static FarmStats instance;
        return instance;
    }

    BuildingType getBuildingType() const override { return BuildingType::Farm;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{2, 4, 6, 8};}
    array<int, 4> getScienceCostToBuild() const override {return array<int, 4>{0, 3, 5, 7};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{1, 2, 3, 5};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};
#if 0
class LabStats : public BuildingStats {
    LabStats() {
        b = BuildingType::Lab;
        int RockCostToBuild[4] = {3, 6, 8, 11};
        int ScienceCostToBuild[4] = {0, 4, 6, 8};
        int RocksProduced[4] = {0, 0, 0, 0};
        int FoodProduced[4] = {0, 0, 0, 0};
        int CultureProduced[4] = {0, 0, 0, 0};
        int ScienceProduced[4] = {1, 2, 3, 5};
        int HappinessProvided[4] = {0, 0, 0, 0};
        int MilitaryProvided[4] = {0, 0, 0, 0};
    }
};

class TempleStats : public BuildingStats {
    TempleStats() {
        b = BuildingType::Temple;
        int RockCostToBuild[4] = {3, 5, 7, -1};
        int ScienceCostToBuild[4] = {0, 2, 4, -1};
        int RocksProduced[4] = {0, 0, 0, 0};
        int FoodProduced[4] = {0, 0, 0, 0};
        int CultureProduced[4] = {1, 1, 1, 0};
        int ScienceProduced[4] = {0, 0, 0, 0};
        int HappinessProvided[4] = {1, 2, 3, 0};
        int MilitaryProvided[4] = {0, 0, 0, 0};
    }
};

class ArenaStats : public BuildingStats {
    ArenaStats() {
        b = BuildingType::Arena;
        int RockCostToBuild[4] = {0, 3, 5, 7};
        int ScienceCostToBuild[4] = {0, 3, 5, 7};
        int RocksProduced[4] = {0, 0, 0, 0};
        int FoodProduced[4] = {0, 0, 0, 0};
        int CultureProduced[4] = {0, 0, 0, 0};
        int ScienceProduced[4] = {0, 0, 0, 0};
        int HappinessProvided[4] = {0, 2, 3, 4};
        int MilitaryProvided[4] = {0, 1, 2, 4};
    }
};

class LibraryStats : public BuildingStats {
    LibraryStats() {
        b = BuildingType::Library;
        int RockCostToBuild[4] = {0, 3, 8, 11};
        int ScienceCostToBuild[4] = {0, 3, 6, 9};
        int RocksProduced[4] = {0, 0, 0, 0};
        int FoodProduced[4] = {0, 0, 0, 0};
        int CultureProduced[4] = {0, 1, 2, 3};
        int ScienceProduced[4] = {0, 1, 2, 3};
        int HappinessProvided[4] = {0, 0, 0, 0};
        int MilitaryProvided[4] = {0, 0, 0, 0};
    }
};

class TheaterStats : public BuildingStats {
    TheaterStats() {
        b = BuildingType::Theater;
        int RockCostToBuild[4] = {0, 4, 8, 11};
        int ScienceCostToBuild[4] = {0, 4, 7, 10};
        int RocksProduced[4] = {0, 0, 0, 0};
        int FoodProduced[4] = {0, 0, 0, 0};
        int CultureProduced[4] = {0, 2, 3, 4};
        int ScienceProduced[4] = {0, 0, 0, 0};
        int HappinessProvided[4] = {0, 1, 1, 1};
        int MilitaryProvided[4] = {0, 0, 0, 0};
    }
};
#endif
class Building {

public:
    Building() = delete;
    Building(const BuildingStats& bs): bs(bs) {}
    int GetRockCostToBuild(int level) {
        array<int, 4> ret = bs.getRockCostToBuild();
        return bs.getRockCostToBuild()[level];
    }
    int GetScienceCostToBuild(int level) {return bs.getScienceCostToBuild()[level];}
    virtual int GetRocksProduced(int level) {return bs.getRocksProduced()[level];}
//    virtual int GetRocksProduced() {return bs.getRocksProduced()[0] * + }
    virtual int GetFoodProduced(int level) {return bs.getFoodProduced()[level];}
//    virtual int GetFoodProduced() {return bs.FoodProduced[0] * count[0] + bs.FoodProduced[1]  * count[1] + bs.FoodProduced[2] * count[2] + bs.FoodProduced[3] * count[3];}
    virtual int GetCultureProduced(int level) {return bs.getCultureProduced()[level];}
    virtual int GetScienceProduced(int level) {return bs.getScienceProduced()[level];}
    virtual int GetHappinessProvided(int level) {return bs.getHappinessProvided()[level];}
    virtual int GetMilitaryProvided(int level) {return bs.getMilitaryProvided()[level];}

    void Build(int level) { built[level]++; }
    int GetBuilt(int level) {return built[level];}
    int GetBuilt() {return std::accumulate(built.begin(), built.end(), 0); }

    void DevelopTech(int level) {
        techDeveloped[level] = true;
    }
    bool isTechDeveloped(int level) {
        return techDeveloped[level];
    }

private:
    const BuildingStats& bs;
    array<bool, Const::MaxBuildingLevels> techDeveloped = {false, false, false, false};
    array<int, Const::MaxBuildingLevels> built = {0, 0, 0, 0};

};



#endif //TTA_BUILDING_H
