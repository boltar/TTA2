//
// Created by Tony Cha on 9/29/19.
//

#ifndef TTA_GAMEENGINE_H
#define TTA_GAMEENGINE_H


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
