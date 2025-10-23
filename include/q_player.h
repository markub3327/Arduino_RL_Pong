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

/*const PROGMEM float LEARNING_RATE = 0.40f;
const PROGMEM float GAMMA = 0.90f;
const PROGMEM int EPSILON = 5;*/

const PROGMEM float LEARNING_RATE = 0.40f;
const PROGMEM float GAMMA = 0.90f;
const PROGMEM int EPSILON = 20;

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

char Q_table[8][8][6][3] = {6,0,-14,-19,7,0,-27,-44,-43,-41,-36,-43,-38,-49,-48,-37,-38,-45,12,10,9,13,11,9,-13,12,-35,-34,1,-33,-33,-37,-40,-41,-34,-41,13,12,12,12,16,12,4,13,11,-22,7,-13,-27,9,-31,-33,-17,-31,11,11,13,13,11,10,14,9,9,10,1,-4,-1,2,-18,-13,0,-22,16,15,12,14,26,18,19,14,11,12,18,12,3,21,4,2,9,-10,22,13,17,18,15,34,35,18,19,15,34,13,15,13,14,13,18,10,44,27,23,31,33,32,41,34,54,39,38,33,24,30,38,20,36,25,31,59,40,36,32,43,59,59,61,44,61,51,41,42,57,28,58,38,12,9,10,11,10,-34,-36,10,-36,-35,-42,-42,-42,-38,-41,-50,-41,-53,14,14,12,12,15,12,11,15,-17,-33,11,-32,-37,-6,-36,-39,-34,-35,14,10,10,14,11,9,11,12,-5,-1,10,4,-2,-16,-25,-33,-9,-29,15,12,14,13,11,9,10,15,9,6,12,5,4,-9,-21,-11,-3,-17,13,14,11,11,11,3,10,10,12,2,11,8,6,13,-4,-6,6,-8,20,19,36,15,15,35,14,15,28,28,21,19,12,17,13,16,22,18,14,14,15,18,19,17,17,33,17,12,45,18,13,13,14,5,18,16,27,22,53,22,24,45,54,69,39,52,41,56,50,57,50,55,56,29,3,6,10,12,2,11,10,9,-40,-31,1,-38,-39,-39,-38,-45,-34,-51,7,7,16,14,6,10,12,16,5,8,3,-17,-17,10,-33,-35,-32,-36,1,3,11,10,6,12,14,8,-16,10,-5,-9,-8,6,-15,-26,-23,-27,10,12,16,16,16,12,9,11,6,1,11,-3,-9,11,-11,-1,-11,-14,12,10,12,14,14,14,12,15,11,7,12,8,3,10,-3,-4,-3,-2,19,16,29,13,14,13,11,17,12,11,15,11,14,11,6,3,1,6,14,12,32,15,32,15,14,15,16,13,17,31,30,14,12,32,20,10,15,15,47,25,23,24,50,22,22,23,20,52,51,57,64,58,51,60,-34,-47,4,3,-40,10,11,0,7,4,11,-36,-37,6,-40,-55,-33,-60,-1,-12,-1,-7,-2,28,25,1,10,6,25,12,6,3,-29,-25,7,-12,3,3,9,2,-1,12,11,12,7,-1,10,7,-6,8,-25,-8,11,-16,2,4,-3,3,9,11,35,10,13,4,13,8,-1,6,-20,-3,13,-4,14,10,23,21,13,14,11,9,16,6,12,8,7,14,-3,0,10,-3,10,12,15,10,10,14,11,43,15,14,10,11,14,16,14,9,15,6,21,12,11,18,13,13,14,19,13,13,14,16,13,11,11,11,24,6,21,15,30,43,35,54,37,31,30,19,21,47,35,40,61,38,27,50,-58,-61,-41,-39,-43,6,0,-41,10,12,7,0,7,9,-41,-36,4,-52,-31,-36,3,-7,-23,8,6,4,20,24,9,6,1,21,8,-3,0,10,7,-4,1,-14,-12,-4,9,12,15,8,10,5,0,10,6,-5,2,-1,-16,-15,6,2,-1,12,9,-2,14,19,16,20,9,15,2,4,16,5,2,-5,12,-2,3,17,12,4,7,12,9,8,6,10,4,12,9,10,15,16,18,30,16,19,12,11,18,20,13,12,25,17,17,10,14,13,9,8,29,17,16,15,12,12,15,15,11,21,13,15,15,15,19,15,38,39,27,26,32,30,39,50,21,25,15,37,23,64,47,32,53,25,-40,-51,-51,-53,-47,-40,-38,-44,2,12,-38,4,14,3,5,5,12,6,-41,-36,-17,-15,-38,2,6,-20,6,9,4,18,17,9,4,3,24,3,-31,-10,-17,-9,-27,7,-5,-7,-6,-8,11,22,14,11,9,6,14,6,-3,-10,12,-4,-10,9,8,1,1,7,2,12,14,3,10,13,9,12,-17,-17,10,1,-8,6,6,7,14,10,9,16,13,13,16,26,17,13,-2,17,11,11,12,15,12,9,11,15,15,16,10,13,21,23,27,17,17,1,13,49,15,20,18,17,18,15,22,30,14,17,14,12,13,18,63,46,40,41,39,58,59,42,31,47,19,18,25,17,47,25,18,19,-41,-45,-44,-51,-45,-41,-38,-41,-36,-38,-33,11,10,-37,12,12,9,11,-35,-41,-44,-35,-38,0,-12,-37,13,13,-4,12,18,14,26,17,17,28,-33,-32,-20,-35,-27,2,-10,-1,13,6,-16,16,11,3,10,15,12,12,-14,-14,3,0,-21,9,5,4,15,11,13,18,14,13,12,19,33,24,-15,4,6,4,-10,6,5,12,14,10,10,18,9,10,12,21,13,12,8,10,13,27,11,19,16,16,22,19,14,35,34,33,44,40,20,23,12,12,44,26,31,14,33,15,15,14,9,16,13,12,12,16,17,50,66,46,27,62,37,57,53,47,60,65,25,36,63,41,37,52,27,31,-55,-36,-37,-43,-39,-40,-41,-44,-36,-40,-44,-39,-20,-15,4,6,0,0,-39,-41,-33,-35,-41,-29,-31,-38,-31,5,-29,10,6,8,12,14,9,10,-33,-33,-11,-26,-34,4,-6,-16,11,11,-3,17,22,12,16,20,14,15,-25,-23,0,-8,-20,10,2,1,0,15,9,9,7,9,14,10,9,13,-2,1,0,9,-3,14,12,6,13,14,18,13,14,17,30,16,17,29,29,17,12,24,18,16,21,30,18,21,14,17,15,19,18,20,21,21,40,30,31,35,48,36,39,28,34,37,33,27,24,33,39,26,36,33,46,46,60,52,53,63,41,59,42,56,65,47,60,50,38,53,55,60}; 

class Environment;

class QPlayer : public Player {
public:
    QPlayer(Environment *env, const PlayerSide side) : Player(env, side) {
    }

    void update(const State &s) override {
        this->action = getPolicy(s);
        switch (this->action) {
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

    void updatePolicy(const State &s, const State &s2) {
        auto target = this->getReward() + GAMMA * Q_table[s2.ball_x][s2.ball_y][s2.player_x][getPolicy(s2)];
        auto delta = static_cast<char>(lround(
            LEARNING_RATE * (target - Q_table[s.ball_x][s.ball_y][s.player_x][this->action])));
        Q_table[s.ball_x][s.ball_y][s.player_x][this->action] =
                Q_table[s.ball_x][s.ball_y][s.player_x][this->action] + delta;

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

    char Q_table[8][8][6][3] = {}; // init with zeros

private:
    char getPolicy(const State &s) {
        char max = 0;

        // Epsilon-greedy policy
        if (random(0, 100) < EPSILON) {
            max = static_cast<char>(random(0, 3));
        } else {
            for (char a = 1; a < 3; a++) {
                if (Q_table[s.ball_x][s.ball_y][s.player_x][a] > Q_table[s.ball_x][s.ball_y][s.player_x][max]) {
                    max = a;
                }
            }
        }

        return max;
    }

    char action;
};

#endif //Q_PLAYER_H
