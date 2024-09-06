//
// Created by martin on 25.8.2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

enum class PlayerSide : char {
    LEFT,
    RIGHT
};

class Environment;

class Player : public GameObject {
public:
    Player(Environment *env, const PlayerSide side) : GameObject(Size(3, 1)), side(side) {
        this->Init();
        this->env = env;
        this->score = 0;
    }

    void show(MD_MAX72XX &mx) override {
        const auto current = mx.getColumn(this->position.y);
        mx.setColumn(this->position.y, ((0x7 << this->position.x) | current));
    }

    void Init() override {
        this->position = Point{
            .x = static_cast<int>(random(0, 6)),
            .y = this->side == PlayerSide::LEFT ? 0 : 7
        };
        // this->score = 0;
        this->reward = 0;
    }

    void Goal();

    int getScore() const {
        return this->score;
    }

    PlayerSide getSide() const {
        return this->side;
    }

    int getReward() const {
        return this->reward;
    }

    void setReward(int r) {
        this->reward = r;
    }

protected:
    Environment *env;
    PlayerSide side;
    int score;
    int reward;
};

#endif //PLAYER_H
