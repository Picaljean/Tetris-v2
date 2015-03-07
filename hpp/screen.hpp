#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <SDL/SDL.h>
#include <string>
using namespace std;

class screen{
private:
  SDL_Surface *game;
  SDL_Surface *scr;
  SDL_Surface *piece;
  SDL_Surface *background;
  SDL_Surface *cursor;
  SDL_Rect pos_cursor;
  int width;
  int height;
public:
  screen(int, int, string,string);
  void draw_rect(int,int,int,int,char,SDL_Surface *);
  void flip();
  void empty();
  ~screen();
  SDL_Surface* getGame()const;
  SDL_Surface * getScr()const;
  SDL_Surface * getPiece()const;
  void setXcursor(int);
  void setYcursor(int);
  void write_text(string,SDL_Color,int,int,int,string);
  int getHeight();
  int getWidth();
  void resize();
  void blit();
};
#endif
