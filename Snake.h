//
// Created by Yifan Li on 26/08/2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include "iostream"
#include <cstdlib>
#include <time.h>
#include <utility>
#include <vector>
// #include <curses.h>
#define WIDTH 10
#define HEIGHT 10

class Snake {
private:
    std::pair<int ,int> position;
    std::vector<std::pair<int,int> > snakeBody;
    int snakeLength;
public:
    Snake();
    std::pair<int, int> get_position();
    void move();
    std::vector<std::pair<int,int> > getBody();
    void eatFood(std::pair<int,int> foodPosition);
    int getLength();
    bool eatSelf();
};


#endif //SNAKE_SNAKE_H
