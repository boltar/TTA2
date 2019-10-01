//
// Created by t on 9/29/2019.
//

#include "Player.h"

void Player::endTurn() {
}
//  4   4   4   4   4    2
// ___ ___ ___ ___ ___ |    |
// -6  -4  -3  -2  -1  |    |    consumption
//     7   5   4   3   | 2  |    cost to increase pop
// 2   2   2   1   1   |    |    happy faces

// 4 4 4 4 0 | 1
// 1 discontent

// 4 4 4 4 0 | 0
// 1 angry

// 4 4 4 3 0 | 1
// 1 discontent

int getFoodConsumed(int yellow_tokens) {
    if (yellow_tokens > 16) return 0;
    if (yellow_tokens > 12) return 1;
    if (yellow_tokens > 8) return 2;
    if (yellow_tokens > 4) return 3;
    if (yellow_tokens > 0) return 4;
    return 6; // max
}

int getCostToIncreasePopulation(int yellow_tokens) {
    if (yellow_tokens > 16) return 2;
    if (yellow_tokens > 12) return 3;
    if (yellow_tokens > 8) return 4;
    if (yellow_tokens > 4) return 5;
    if (yellow_tokens > 0) return 7;
    return -1; // can't raise more pop
}

int getHappyFacesRequired(int yellow_tokens) {
    if (yellow_tokens > 16) return 0;
    if (yellow_tokens > 12) return 1;
    if (yellow_tokens > 10) return 2;
    if (yellow_tokens > 8) return 3;
    if (yellow_tokens > 6) return 4;
    if (yellow_tokens > 4) return 5;
    if (yellow_tokens > 2) return 6;
    if (yellow_tokens > 0) return 7;
    return 8; // max
}

int getDiscontentWorkers(int yellow_tokens, int happy_faces) {
    int discontented_workers = getHappyFacesRequired(yellow_tokens) - happy_faces;

    // if all happy is satisfied, then no discontented workers are present
    return discontented_workers > 0 ? discontented_workers : 0;
}

int getAngryWorkers(int yellow_tokens, int idle_workers, int happy_faces) {

    int discontent_workers = getDiscontentWorkers(yellow_tokens, happy_faces);
    int angry_workers = discontent_workers - idle_workers;

    return angry_workers > 0 ? angry_workers : 0;
}