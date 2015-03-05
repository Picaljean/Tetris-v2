#ifndef SHAPE8_HPP
#define SHAPE8_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape8:public AbstractShape{
public :
  Shape8(int,int,int);
  Shape8();
  Shape8(const Shape8&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape8();
};

#endif