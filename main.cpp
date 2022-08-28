#include <iostream>
#include <stdio.h>
#include "Snake.h"
#include "food.h"
using namespace std;

#define WIDTH 10
#define HEIGHT 10

void board(pair<int, int> snakePosition, pair<int,int> foodPosition){
  cout << foodPosition.first << endl;
  cout << foodPosition.second << endl;
  cout << snakePosition.first << endl;
  cout << snakePosition.second << endl;


  for(int i = 0; i != HEIGHT+2; i++){
      for(int j = 0; j != WIDTH+2; j++){
          if(i == 0 || i == HEIGHT + 1) {
              if(j <= WIDTH) cout << '#';
              else if ( j == WIDTH +1) cout << '#' << '\n';
          }
          else {
              if (j == 0) cout << '#';
              else if (j == WIDTH + 1) cout << '#' << '\n';
              else if(i == snakePosition.first +1 && j == snakePosition.second + 1) {
                  cout << 'a' ;
              }
              else {
                if(i == foodPosition.first +1 && j == foodPosition.second+1) cout << 'F';
                else cout << ' ';
              }
          }
      }
  }
}


int main() {
    srand (time(NULL) );
    Snake snake;
    Food food;
    while(true){
        pair<int, int> snakePosition = snake.get_position();
        pair<int, int> foodPosition = food.getPosition();
        if(snakePosition == foodPosition){
          cout << "eaten" << endl;
          food.updateFoodPosition();
        }
        board(snakePosition, foodPosition);
        snake.move();
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
    }
    return 0;
}
