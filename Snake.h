//
// Created by Yifan Li on 26/08/2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include "iostream"
#include <cstdlib>
#include <time.h>
#define WIDTH 10
#define HEIGHT 10

class Snake {
private:
    std::pair<int ,int> position;
public:
    Snake();
    std::pair<int, int> get_position();
    void move();
};


#endif //SNAKE_SNAKE_H
