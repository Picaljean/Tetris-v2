#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
using namespace std;
class Player{
private:
  string name;
  int score;
public:
  Player(string);
  int getScore()const;
  string getName();
  void updateScore(int);
};
#endif
