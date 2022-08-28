
#include "iostream"
#include <cstdlib>
#include <time.h>
#include <utility>
#define WIDTH 10
#define HEIGHT 10

class Food
{
public:
  Food();
  void updateFoodPosition();
  std::pair<int,int> getPosition();
private:
  std::pair<int,int> position;
  
};


