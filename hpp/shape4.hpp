#ifndef SHAPE4_HPP
#define SHAPE4_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape4:public AbstractShape{
public :
  Shape4(int,int,int);
  Shape4();
  Shape4(const Shape4&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape4();
};
#endif
