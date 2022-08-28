#include "food.h"
#include <utility>
#define WIDTH 10
#define HEIGHT 10

Food::Food(){
  position.first = rand()%HEIGHT;
  position.second = rand()%WIDTH;
}

void Food::updateFoodPosition(){
  position.first = rand()%HEIGHT;
  position.second = rand()%WIDTH;
}

std::pair<int,int> Food::getPosition(){
  return position;
}
