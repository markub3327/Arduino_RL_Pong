//
// Created by martin on 2.9.2024.
//

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "game_object.h"
#include "random_player.h"
#include "human_player.h"
#include "q_player.h"
#include "ball.h"

// LED Matrix
#include <MD_MAX72xx.h>

int freeRam() {
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0
                           ? (int) &__heap_start
                           : (int) __brkval);
}

void display_freeram() {
    Serial.print(F("- SRAM left: "));
    Serial.println(freeRam());
}


class Environment {
public:   // layerA(this, A5, PlayerSide::LEFT)
    Environment() : playerA(this, PlayerSide::LEFT), playerB(this, PlayerSide::RIGHT) {
        // Init LED Matrix 8x8
        mx.begin();

        ball = new Ball(this);
    }

    void run() {
        mx.clear();

        // store the current state
        State state{
            .player_x = this->playerB.getX(),
            .ball_x = this->ball->getX(),
            .ball_y = this->ball->getY(),
        };

        // Environment step
        update(&playerA, state);
        update(&playerB, state);
        update(ball, state);

        // store the next state
        State next_state{
            .player_x = this->playerB.getX(),
            .ball_x = this->ball->getX(),
            .ball_y = this->ball->getY(),
        };

        // Update agent's policy
        this->playerB.updatePolicy(state, next_state);
    }

    void update(GameObject *obj, const State &s) {
        obj->show(mx);
        obj->update(s);
    }

    void playerEnd(Player *p) {
        Serial.print("Player ");
        Serial.print(p->getSide() == PlayerSide::LEFT ? F("Left: ") : F("Right: "));
        Serial.println(p->getScore());

        Serial.print(F("Success rate of Player "));
        Serial.print(p->getSide() == PlayerSide::LEFT ? F("Left: ") : F("Right: "));
        Serial.print(p->getScore() * 100.0f / rounds);
        Serial.println(F("%"));

        if ((p->getScore() * 100.0f / rounds) > 85) {
            for (char i = 0; i < 8; i++)
                for (char j = 0; j < 8; j++)
                    for (char k = 0; k < 6; k++)
                        for (char l = 0; l < 3; l++) {
                            Serial.print((int)reinterpret_cast<QPlayer*>(p)->Q_table[i][j][k][l]);
                            Serial.print(';');
                        }
            Serial.println();
        }
        p->Init();

        Serial.print("Rounds: ");
        Serial.println(rounds);

        //display_freeram();
    }

    void handleEnd() {
        this->playerEnd(&playerA);
        this->playerEnd(&playerB);
        ball->Init();
        if (this->rounds > 30000) this->rounds = 0;
        //this->rounds = 0;
    }

    void handleRound() {
        this->rounds++;
    }

    RandomPlayer playerA;
    //HumanPlayer playerA;
    QPlayer playerB;

private:
    MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::GENERIC_HW, 7, 1);
    Ball *ball;
    int rounds = 0;
};

inline void Player::Goal() {
    if (this->score > 30000) this->score = 0;
    this->score += 1;
    this->env->handleRound();
    if ((this->score % 21) == 0) {
        this->env->handleEnd();
    }
}

inline void Ball::playerCollider() {
    // Typically the reward is zero
    this->env->playerA.setReward(0);
    this->env->playerB.setReward(0);

    // check if the goal has been scored
    if (this->env->playerA.getY() == this->position.y &&
        (this->position.x < this->env->playerA.getX() || this->position.x > (this->env->playerA.getX() + this->env->playerA.getWidth() - 1))) {
        this->env->playerA.setReward(-50);
        this->env->playerB.setReward(50);
        this->env->playerB.Goal();
        this->Init();
        return;
    }

    if (this->env->playerB.getY() == this->position.y &&
        (this->position.x < this->env->playerB.getX() || this->position.x > (this->env->playerB.getX() + this->env->playerB.getWidth() - 1))) {
        this->env->playerA.Goal();
        this->env->playerA.setReward(50);
        this->env->playerB.setReward(-50);
        this->Init();
        return;
    }

    this->checkCollision(this, &this->env->playerA);
    this->checkCollision(this, &this->env->playerB);
}


#endif //ENVIRONMENT_H
