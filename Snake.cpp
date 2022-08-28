//
// Created by Yifan Li on 26/08/2022.
//

#include "Snake.h"
#include <cstdio>
#include <iostream>
#define WIDTH 10
#define HEIGHT 10

Snake::Snake() {
    position.first = rand() % HEIGHT;
    position.second = rand() % WIDTH;
    snakeBody.push_back(position);
    snakeLength =1;
}
std::pair<int, int> Snake::get_position() {return position;}

void Snake::move() {
  char input = getchar();
  std::cout << input << std::endl;
  switch (input) {
    case 'h':
      position.second--; 
      if(position.second == 0) position.second = WIDTH-1;
      snakeBody.push_back(position);
      if(snakeLength == snakeBody.size() -1)snakeBody.erase(snakeBody.begin());
      break;
    case 'l':
      position.second++;
      if(position.second == WIDTH) position.second = 0;
      snakeBody.push_back(position);
      if(snakeLength == snakeBody.size() -1)snakeBody.erase(snakeBody.begin());
      break;
    case 'j':
      position.first++;
      if(position.first == HEIGHT) position.first = 0;
      snakeBody.push_back(position);
      if(snakeLength == snakeBody.size() -1)snakeBody.erase(snakeBody.begin());
      break;
    case 'k':
      position.first--;
      if(position.first == -1) position.first = HEIGHT -1;
      snakeBody.push_back(position);
      if(snakeLength == snakeBody.size() -1)snakeBody.erase(snakeBody.begin());
      break;
    default:
      break;
  }
}

std::vector<std::pair<int,int> > Snake::getBody(){ return snakeBody;}

int Snake::getLength(){
  return snakeLength;
}

void Snake::eatFood(std::pair<int,int> foodPosition){
  if(position == foodPosition) snakeLength++;
}

bool Snake::eatSelf(){
  for(int i = 0; i < snakeBody.size()-1; i++){
    if(position == snakeBody[i]) return true;
  }
  return false;
}

