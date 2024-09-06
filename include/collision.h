//
// Created by martin on 2.9.2024.
//

#ifndef COLLISION_H
#define COLLISION_H

#include "game_object.h"

class Collision {
protected:
  void checkCollision(GameObject* o1, GameObject* o2) {
    if ((o1->getX() + o1->getWidth()) < o2->getX()) return;
    if (o1->getX() > (o2->getX() + o2->getWidth())) return;
    if ((o1->getY() + o1->getHeight()) < o2->getY()) return;
    if (o1->getY() > (o2->getY() + o2->getHeight())) return;
    this->onCollision(o2);
  }
  virtual void onCollision(GameObject* other) = 0;
};

#endif //COLLISION_H
