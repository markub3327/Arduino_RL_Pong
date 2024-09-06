//
// Created by martin on 25.8.2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <MD_MAX72xx.h>
#include "point.h"

struct State {
    int player_x;
    int ball_x;
    int ball_y;
};

// AbstractProduct (interface)
class GameObject {
protected:
    Point position;
    Size size;

public:
    GameObject(const Size size) : size(size) {
    };

    virtual void Init() = 0;

    virtual void update(const State &s) = 0;

    virtual void show(MD_MAX72XX &mx) = 0;

    virtual ~GameObject() = default;

    int getX() const { return this->position.x; }
    int getY() const { return this->position.y; }
    int getWidth() const { return this->size.width; }
    int getHeight() const { return this->size.height; }
};

#endif //GAMEOBJECT_H
