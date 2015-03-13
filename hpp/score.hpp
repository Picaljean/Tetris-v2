#ifndef SCORE_HPP
#define SCORE_HPP
#include <string>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include <fstream>
#include <list>
#include <utility>
#include <algorithm>
#include <SDL/SDL.h>
using namespace std;

class score{
private:
  SDL_Surface * scr;
  SDL_Surface * background;
  string font_file;
  SDL_Color c;
  int size;
  int width;
  int height;
  list<pair<string,int> > s;
public:
  score(string,string,string,int,int,int);
  void write_scores();
  string concat(string,int,int);
  void flip();
  void clear();
  int longest_score();
  void blit_back();
  void resize();
  ~score();
};

#endif
