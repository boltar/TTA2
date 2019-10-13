//
// Created by Tony Cha on 9/29/19.
//

#ifndef TTA_GAMEENGINE_H
#define TTA_GAMEENGINE_H

#include <string>
#include <map>
#include "Constants.h"

using namespace std;

enum class Status {
    OK,
    NOT_ENOUGH_ROCKS,
    NOT_ENOUGH_IDLE_WORKERS,
    NOT_ENOUGH_SCIENCE,
    NO_TECH_DEVELOPED,
};
enum class BuildingType {
    Mine,
    Farm,
    Temple,
    Lab,
    Theater,
    Arena,
    Library,
};

const map<BuildingType, array<string, Const::MaxBuildingLevels>> BuildingNames =
        {{BuildingType::Mine, {"Bronze", "Iron", "Coal", "Oil"}},
         {BuildingType::Farm, {"Agriculture", "Irrigation", "Selective Breeding", "Mechanized Agriculture"}},
         {BuildingType::Temple, {"Religion", "Theology", "Organized Religion", "INVALID TEMPLE"}},
         {BuildingType::Lab, {"Philosophy", "Alchemy", "Scientific Method", "Computers"}},
         {BuildingType::Theater, {"INVALID THEATER", "Drama", "Opera", "Multimedia"}},
         {BuildingType::Arena, {"INVALID ARENA", "Bread and Circuses", "Team Sports", "Professional Sports"}},
         {BuildingType::Library, {"INVALID LIBRARY", "Printing Press", "Journalism", "Printing Press"}}};

class GameEngine {
public:
    static int GetFoodConsumed(int yellow_tokens);
    static int GetCostToIncreasePopulation(int yellow_tokens);
    static int GetHappyFacesRequired(int yellow_tokens);
    static int GetDiscontentWorkers(int yellow_tokens, int happy_faces);
    static int GetAngryWorkers(int discontented_workers, int idle_workers);
    static int CalculateCorruption(int blue_tokens);
};


#endif //TTA_GAMEENGINE_H
