//
// Created by Yifan Li on 26/08/2022.
//

#include "Snake.h"
#include <cstdio>
#define WIDTH 10
#define HEIGHT 10

Snake::Snake() {
    position.first = rand() % HEIGHT;
    position.second = rand() % WIDTH;
}
std::pair<int, int> Snake::get_position() {return position;}

void Snake::move() {
    switch (getchar()) {
        case 'h':
            position.second--;
            if(position.second == -1) position.second = WIDTH -1;
            break;
        case 'l':
            position.second++;
            if(position.second == WIDTH) position.second = 0;
            break;
        case 'j':
            position.first++;
            if(position.first == HEIGHT) position.first = 0;
            break;
        case 'k':
            position.first--;
            if(position.first == -1) position.first = HEIGHT -1;
            break;
    }
}

