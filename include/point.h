//
// Created by martin on 25.8.2024.
//

#ifndef POINT_H
#define POINT_H

struct Point {
    int x, y;
};

struct Size {
    int width, height;

    Size(int width, int height) : width(width), height(height) {
    }
};

#endif //POINT_H
