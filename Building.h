//
// Created by t on 10/5/2019.
//

#ifndef TTA_BUILDING_H
#define TTA_BUILDING_H
#include <numeric>
#include "Constants.h"


struct BuildingStats {
    int RockCostToBuild[4] = {2, 4, 6, 8};
    int ScienceCostToBuild[4] = {0, 3, 5, 7};
    int RocksProduced[4] = {1, 2, 3, 5};
    int FoodProduced[4] = {1, 2, 3, 5};
    int CultureProduced[4] = {0, 0, 0, 0};
    int ScienceProduced[4] = {0, 0, 0, 0};
    int HappinessProvided[4] = {0, 0, 0, 0};
    int MilitaryProvided[4] = {0, 0, 0, 0};
};

const BuildingStats farmStats;


class Building {

public:
    Building() = delete;
    Building(const BuildingStats& bs): bs(bs) {}
    int GetRockCostToBuild(int level) {return bs.RockCostToBuild[level];}
    int GetScienceCostToBuild(int level) {return bs.ScienceCostToBuild[level];}
    virtual int GetRocksProduced(int level) {return bs.RocksProduced[level];}
    virtual int GetRocksProduced() {return bs.RocksProduced[0] * count[0] + bs.RocksProduced[1]  * count[1] + bs.RocksProduced[2] * count[2] + bs.RocksProduced[3]  * count[3];}
    virtual int GetFoodProduced(int level) {return bs.FoodProduced[level];}
    virtual int GetFoodProduced() {return bs.FoodProduced[0] * count[0] + bs.FoodProduced[1]  * count[1] + bs.FoodProduced[2] * count[2] + bs.FoodProduced[3] * count[3];}
    virtual int GetCultureProduced(int level) {return bs.CultureProduced[level];}
    virtual int GetScienceProduced(int level) {return bs.ScienceProduced[level];}
    virtual int GetHappinessProvided(int level) {return bs.HappinessProvided[level];}
    virtual int GetMilitaryProvided(int level) {return bs.MilitaryProvided[level];}

    void Build(int level) { count[level]++; }
    int GetCount(int level) {return count[level];}
    int GetCount() {return std::accumulate(count, count + Constants::MaxBuildingLevels, 0); }
    const BuildingStats& bs;
protected:

    int count[Constants::MaxBuildingLevels] = {2, 0, 0, 0};
};



#endif //TTA_BUILDING_H
