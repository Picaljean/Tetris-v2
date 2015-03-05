#ifndef SHAPE16_HPP
#define SHAPE16_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape16:public AbstractShape{
public :
  Shape16(int,int,int);
  Shape16();
  Shape16(const Shape16&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape16();
};

#endif