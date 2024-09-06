//
// Created by martin on 25.8.2024.
//

#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Environment;

class HumanPlayer : public Player {
public:
    HumanPlayer(Environment *env, const int pin, const PlayerSide side) : Player(env, side), pin(pin) {
    }

    void update(const State &s) override {
        this->position.x = readJoystick();
    }

private:
    int readJoystick() const {
        int buff[6] = {};

        for (int i = 0; i < 10; i++) {
            buff[map(analogRead(this->pin), 0, 1023, 0, 5)]++;
            // auto y = map(analogRead(A5), 0, 1023, 0, 7);
        }

        // find mode
        int max = 0, maxIdx = 0;
        for (int i = 0; i < 6; i++) {
            if (buff[i] > max) {
                max = buff[i];
                maxIdx = i;
            }
        }

        return maxIdx;
    }

    int pin;
};

#endif //HUMAN_H
