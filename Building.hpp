//
// Created by t on 10/5/2019.
//

#ifndef TTA_BUILDING_HPP
#define TTA_BUILDING_HPP
#include <numeric>
#include "Constants.hpp"
#include "GameEngine.hpp"


class BuildingStats {
public:
    virtual BuildingType getBuildingType() const = 0;
    virtual array<int, 4> getRockCostToBuild() const = 0;
    virtual array<int, 4> getScienceCostToDevelop() const = 0;
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
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 5, 7, 9};}
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
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 3, 5, 7};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{1, 2, 3, 5};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};
class TempleStats : public BuildingStats {
public:
    static TempleStats& GetInstance() {
        static TempleStats instance;
        return instance;
    }
    BuildingType getBuildingType() const override { return BuildingType::Temple;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{3, 5, 7, 0};}
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 2, 4, Const::InvalidTech};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{1, 1, 1, 0};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{1, 2, 3, 0};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};

class LabStats : public BuildingStats {
public:
    static LabStats& GetInstance() {
        static LabStats instance;
        return instance;
    }
    BuildingType getBuildingType() const override { return BuildingType::Lab;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{3, 6, 8, 11};}
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 4, 6, 8};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{1, 2, 3, 5};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};

class LibraryStats : public BuildingStats {
public:
    static LibraryStats& GetInstance() {
        static LibraryStats instance;
        return instance;
    }
    BuildingType getBuildingType() const override { return BuildingType::Library;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{0, 3, 8, 11};}
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 3, 6, 9};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 1, 2, 3};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 1, 2, 3};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};

class ArenaStats : public BuildingStats {
public:
    static ArenaStats& GetInstance() {
        static ArenaStats instance;
        return instance;
    }
    BuildingType getBuildingType() const override { return BuildingType::Arena;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{0, 3, 5, 7};}
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 3, 5, 7};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 2, 3, 4};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 2, 3, 4};}
};

class TheaterStats : public BuildingStats {
public:
    static TheaterStats& GetInstance() {
        static TheaterStats instance;
        return instance;
    }
    BuildingType getBuildingType() const override { return BuildingType::Theater;}
    array<int, 4> getRockCostToBuild() const override {return array<int, 4>{0, 4, 8, 11};}
    array<int, 4> getScienceCostToDevelop() const override {return array<int, 4>{Const::InvalidTech, 4, 7, 10};}
    array<int, 4> getRocksProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getFoodProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getCultureProduced() const override {return array<int, 4>{0, 2, 3, 4};}
    array<int, 4> getScienceProduced() const override {return array<int, 4>{0, 0, 0, 0};}
    array<int, 4> getHappinessProvided() const override {return array<int, 4>{0, 1, 1, 1};}
    array<int, 4> getMilitaryProvided() const override {return array<int, 4>{0, 0, 0, 0};}
};

class Building {

public:
    Building() = delete;
    Building(const BuildingStats& bs): bs(bs) {}
    int GetRockCostToBuild(int level) {
        array<int, 4> ret = bs.getRockCostToBuild();
        return bs.getRockCostToBuild()[level];
    }
    int GetScienceCostToBuild(int level) {return bs.getScienceCostToDevelop()[level];}
    virtual int GetRocksProduced(int level) {return bs.getRocksProduced()[level];}
    virtual int GetFoodProduced(int level) {return bs.getFoodProduced()[level];}
    virtual int GetCultureProduced(int level) {return bs.getCultureProduced()[level];}
    virtual int GetScienceProduced(int level) {return bs.getScienceProduced()[level];}
    virtual int GetHappinessProvided(int level) {return bs.getHappinessProvided()[level];}
    virtual int GetMilitaryProvided(int level) {return bs.getMilitaryProvided()[level];}

    void Build(int level) { built[level]++; }
    int GetBuilt(int level) {return built[level];}
//    int GetBuilt() {return std::accumulate(built.begin(), built.end(), 0); }

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



#endif //TTA_BUILDING_HPP
