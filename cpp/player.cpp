#include "../hpp/player.hpp"

Player::Player(string n):name(n),score(0){}

int Player::getScore()const{return score;}

string Player::getName(){return name;}

void Player::updateScore(int s){
  if(score!=0){
    score+=s;
  }else{
    score=s;
  }
}
