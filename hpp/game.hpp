#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <vector>
#include <string>
#include "player.hpp"
#include "screen.hpp"
#include "sound.hpp"
#include "AbstractShape.hpp"

class Game{
private :
  Player p;
  int currentlevel;
  vector<char> grid;
  int gridheight;
  int gridwidth;
  AbstractShape * currentpiece;
  AbstractShape * nextpiece;
  int sizecell;
  int nbblocs;
  int lines;
  bool pause;
public:
  Game(string,int,int,int,int);
  void display(screen *)const;
  friend screen & operator <<(screen &,const Game&);
  void save_score(string);
  void add_shape(AbstractShape *);
  bool check_line(int);
  bool is_paused();
  void delete_line(int);
  void add_line();
  int get_lines();
  int getGridWidth();
  int getGridHeight();
  int getCurrentlevel();
  int getNbblocs();
  void resetNbblocs();
  void levelup();
  Player * getPlayer();
  void setPause();
  void setCurrentpiece(AbstractShape *);
  void setNextpiece(AbstractShape *);
  AbstractShape * getCurrentpiece();
  AbstractShape * getNextpiece();
  bool colision(char);
  bool rotation_colision(AbstractShape *);
  ~Game();
};

#endif
