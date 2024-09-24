//
// Created by martin on 25.8.2024.
//

#ifndef BALL_H
#define BALL_H

#include <environment.h>

#include "game_object.h"
#include "collision.h"

const PROGMEM float velocity = 1.5f;

class Ball : public GameObject, Collision {
public:
    Ball(Environment *env) : GameObject(Size(1, 1)) {
        this->Init();
        this->env = env;
    }

    void update(const State &s) override {
        // check if the ball has collided with the player
        this->playerCollider();

        // check if the ball has bounced off the wall
        if (this->position.y > 0 && this->position.y < 7) {
            if (this->position.x == 0 || this->position.x == 7) {
                this->alpha = M_PI - this->alpha;
            }
        }

        // Integral
        this->position.x += static_cast<int>(lround(velocity * cos(this->alpha)));
        this->position.x = constrain(this->position.x, 0, 7);
        this->position.y += static_cast<int>(lround(velocity * sin(this->alpha)));
        this->position.y = constrain(this->position.y, 0, 7);
    }

    void show(MD_MAX72XX &mx) override {
        const auto current = mx.getColumn(this->position.y);
        mx.setColumn(this->position.y, ((1 << this->position.x) | current));
    }

    void Init() override {
        this->position.x = static_cast<int>(random(0, 8));
        this->position.y = static_cast<int>(random(3, 5));

        if (random(0, 2) == 0)
            this->alpha = radians(static_cast<float>(random(45, 135)));
        else
            this->alpha = radians(static_cast<float>(random(225, 315)));
    }

private:
    Environment *env;
    double alpha;

    void onCollision(GameObject *other) override {
        this->alpha = constrain(this->position.x - (other->getX() + (other->getWidth() >> 1)), -1, 1) * (-M_PI_4);
        if (reinterpret_cast<Player *>(other)->getSide() == PlayerSide::RIGHT)
            this->alpha += M_PI_2;
        else
            this->alpha += (M_PI + M_PI_2); // 270 degrees

        // Serial.println("Collision");
        //
        // Serial.print("Ball - X: ");
        // Serial.print(this->position.x);
        // Serial.print(" Y: ");
        // Serial.print(this->position.y);
        // Serial.print(" Alpha: ");
        // Serial.println(this->alpha);
        //
        // Serial.print("Player - X: ");
        // Serial.print(other->getX());
        // Serial.print(" Y: ");
        // Serial.println(other->getY());
    }

    void playerCollider();
};

#endif //BALL_H
