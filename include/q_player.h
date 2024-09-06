//
// Created by martin on 2.9.2024.
//

#ifndef Q_PLAYER_H
#define Q_PLAYER_H

#include "player.h"

// Hyperparameters
/*const PROGMEM float LEARNING_RATE = 0.80f;
const PROGMEM float GAMMA         = 0.99f;
const PROGMEM int   EPSILON       =    10;*/

/*const PROGMEM float LEARNING_RATE = 0.60f;
const PROGMEM float GAMMA         = 0.98f;
const PROGMEM int   EPSILON       =    20;*/

/*const PROGMEM float LEARNING_RATE = 0.50f;
const PROGMEM float GAMMA         = 0.98f;
const PROGMEM int   EPSILON       =    30;*/

const PROGMEM float LEARNING_RATE = 0.40f;
const PROGMEM float GAMMA         = 0.90f;
const PROGMEM int   EPSILON       =     5;

/*const PROGMEM float LEARNING_RATE = 0.30f;
const PROGMEM float GAMMA         = 0.97f;
const PROGMEM int   EPSILON       =     1;*/

/*const PROGMEM float LEARNING_RATE = 0.90f;
const PROGMEM float GAMMA         = 0.98f;
const PROGMEM int   EPSILON       =     5;*/

/*const PROGMEM float LEARNING_RATE = 0.70f;
const PROGMEM float GAMMA         = 0.80f;
const PROGMEM int   EPSILON       =    40;*/

/*const PROGMEM float LEARNING_RATE = 0.20f;
const PROGMEM float GAMMA         = 0.85f;
const PROGMEM int   EPSILON       =     5;*/

/*const PROGMEM float LEARNING_RATE = 0.10f;
const PROGMEM float GAMMA         = 0.95f;
const PROGMEM int   EPSILON       =    10;*/

/*const PROGMEM float LEARNING_RATE = 0.40f;
const PROGMEM float GAMMA         = 0.97f;
const PROGMEM int   EPSILON       =    10;*/

/*const PROGMEM float LEARNING_RATE = 0.95f;
const PROGMEM float GAMMA         = 0.90f;
const PROGMEM int   EPSILON       =     1;*/

/*const PROGMEM float LEARNING_RATE = 0.99f;
const PROGMEM float GAMMA         = 0.91f;
const PROGMEM int   EPSILON       =     1;*/

/*const PROGMEM float LEARNING_RATE = 1.00f;
const PROGMEM float GAMMA         = 0.99f;
const PROGMEM int   EPSILON       =     1;*/

/*const PROGMEM float LEARNING_RATE = 0.23f;
const PROGMEM float GAMMA         = 0.91f;
const PROGMEM int   EPSILON       =     0;*/

/*const PROGMEM float LEARNING_RATE = 0.23f;
const PROGMEM float GAMMA         = 0.91f;
const PROGMEM int   EPSILON       =    59;*/

/*const PROGMEM float LEARNING_RATE = 0.00f;
const PROGMEM float GAMMA         = 0.89f;
const PROGMEM int   EPSILON       =    75;*/

/*const PROGMEM float LEARNING_RATE = 1.00f;
const PROGMEM float GAMMA         = 0.83f;
const PROGMEM int   EPSILON       =    12;*/

/*const PROGMEM float LEARNING_RATE =  0.5f;
const PROGMEM float GAMMA         = 0.99f;
const PROGMEM int   EPSILON       =    10;*/

/*const PROGMEM float LEARNING_RATE = 0.75f;
const PROGMEM float GAMMA         = 0.94f;
const PROGMEM int   EPSILON       =    25;*/

class Environment;
class QPlayer : public Player {
public:
    QPlayer(Environment *env, const PlayerSide side) : Player(env, side) {}
    void update(const State& s) override {
        this->action = getPolicy(s);
        switch (this->action) {
            // Move up
            case 1:
                if (this->getX() > 0)  this->position.x--;
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

    void updatePolicy(const State& s, const State& s2) {
        auto target = this->getReward() + GAMMA * Q_table[s2.ball_x][s2.ball_y][s2.player_x][getPolicy(s2)];
        auto delta = static_cast<char>(lround(LEARNING_RATE * (target - Q_table[s.ball_x][s.ball_y][s.player_x][this->action])));
        Q_table[s.ball_x][s.ball_y][s.player_x][this->action] = Q_table[s.ball_x][s.ball_y][s.player_x][this->action] + delta;

        /*if (Q_table[s.ball_x][s.ball_y][s.player_x][this->action] != 0) {
            Serial.print(F("Delta: "));
            Serial.println(delta, DEC);
            Serial.print(F("Q_table: "));
            Serial.println(Q_table[s.ball_x][s.ball_y][s.player_x][this->action], DEC);
            Serial.print(F("Reward: "));
            Serial.println(this->getReward());
            Serial.print(F("Action: "));
            Serial.println(this->action);
        }*/
    }
private:
    int getPolicy(const State& s) {
      int max = 0;

      // Epsilon-greedy policy
      if (random(0, 100) < EPSILON) {
          max = static_cast<int>(random(0, 3));
      } else {
          for (int a = 1; a < 3; a++) {
              if (Q_table[s.ball_x][s.ball_y][s.player_x][a] > Q_table[s.ball_x][s.ball_y][s.player_x][max]) {
                  max = a;
              }
          }
      }

      return max;
    }

    char Q_table[8][8][6][3] = {};        // init with zeros
    int action;
};

#endif //Q_PLAYER_H
