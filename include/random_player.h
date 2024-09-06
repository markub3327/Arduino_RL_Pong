//
// Created by martin on 25.8.2024.
//

#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include "player.h"

class Environment;

class RandomPlayer : public Player {
public:
    RandomPlayer(Environment *env, const PlayerSide side) : Player(env, side) {
    }

    void update(const State &s) override {
        int action = static_cast<int>(random(0, 3));
        switch (action) {
            // Move up
            case 1:
                if (this->getX() > 0) this->position.x--;
                break;
            // Move down
            case 2:
                if (this->getX() < 5) this->position.x++;
                break;
            // Do nothing
            default:
                break;
        }
    }
};

#endif //RANDOM_PLAYER_H
