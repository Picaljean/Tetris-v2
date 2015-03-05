#ifndef SHAPE15_HPP
#define SHAPE15_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape15:public AbstractShape{
public :
  Shape15(int,int,int);
  Shape15();
  Shape15(const Shape15&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape15();
};

#endif