#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include "Snake.h"
#include "food.h"
using namespace std;

#define WIDTH 10
#define HEIGHT 10

void board(Snake& snake, Food& food){
  pair<int, int> snakePosition = snake.get_position();
  pair<int, int> foodPosition = food.getPosition();
  vector<pair<int,int> > snakeBody = snake.getBody();
  int snakeLength = snake.getLength();
  // cout << foodPosition.first << endl;
  // cout << foodPosition.second << endl;
  // cout << snakePosition.first << endl;
  // cout << snakePosition.second << endl;
  // cout << snakeLength << endl;


  for(int i = 0; i != HEIGHT+2; i++){
    cout << '#';
    for(int j = 0; j != WIDTH+2; j++){
      if(i == 0 || i == HEIGHT +1) cout << '#';
      else if(i == snakePosition.first +1 && j == snakePosition.second +1) cout << 'S';
      else if(i == foodPosition.first +1 && j == foodPosition.second +1) cout << 'f';
      else{
        bool isBody = false;
        for(auto block : snakeBody){
          if(i ==  block.first +1 && j == block.second +1){
            isBody = true;
            cout << 's';
          }
        }
        if(!isBody) cout << ' ';
      }
    }
    cout << '#' << '\n';
  }
}


int main() {
    srand (time(NULL) );
    Snake snake;
    Food food;
    bool gameOver = false;
    while(!gameOver){
        pair<int, int> snakePosition = snake.get_position();
        pair<int, int> foodPosition = food.getPosition();
        vector<pair<int,int> > snakeBody = snake.getBody();
        if(snakePosition == foodPosition){
          cout << "eaten" << endl;
          food.updateFoodPosition();
        }
        board(snake, food);
        snake.move();
        snake.eatFood(food.getPosition());
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
        gameOver = snake.eatSelf();
    }
    return 0;
}
