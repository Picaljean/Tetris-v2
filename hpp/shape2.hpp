#ifndef SHAPE2_HPP
#define SHAPE2_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape2:public AbstractShape{
public :
  Shape2(int,int,int);
  Shape2();
  Shape2(const Shape2&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape2();
};
#endif
