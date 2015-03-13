#ifndef MENU_HPP
#define MENU_HPP
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct menu_element{
  SDL_Surface * Hover;
  SDL_Surface * Normal;
};

class Menu{
private:
  vector <menu_element> elements;
  int size;
  string font_file;
  SDL_Surface * background;
  SDL_Surface * scr;
  SDL_Color Hover_color;
  SDL_Color Normal_color;
  int width;
  int height;
  int posX;
  int posY;
  int currentIndex;

public:
  Menu(int,string,string,string,SDL_Color,SDL_Color,int,int);
  void add_element(string);
  SDL_Surface * Surfacefont(int,string,SDL_Color);
  int getCurrentIndex();
  int getMenuSize();
  void display_elem(SDL_Surface *,int,int);
  void display();
  void flip();
  void reload();
  void move_up();
  void move_down();
  void blit_back();
  ~Menu();
};
#endif
