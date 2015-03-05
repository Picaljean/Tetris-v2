#ifndef ABSTRACTSHAPE_HPP
#define ABSTRACTSHAPE_HPP
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "screen.hpp"
using namespace std;

class AbstractShape{
protected :
  vector<pair<int,int> > shape;
  char c;
  int size;
  int num;
  int first;
  int last;
public :
  virtual AbstractShape * Clone(int,int,int)const =0 ;
  void move_left(int);
  void move_right(int);
  void move_down(int);
  int match_line();
  int match_line_up();
  int x_left_bloc()const;
  int x_right_bloc()const;
  int y_up_bloc()const;
  int y_down_bloc()const;
  char getColor();
  void display(screen *,int)const;
  AbstractShape & operator=(const AbstractShape&);
  int get_location(int,int);
  int next();
  int previous();
  pair<int,int> new_shape();
  pair<int,int> near_bloc(char,int);
  pair<int,int> getBloc(int);
  virtual ~AbstractShape();
};
#endif
