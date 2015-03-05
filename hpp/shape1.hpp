#ifndef SHAPE1_HPP
#define SHAPE1_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape1:public AbstractShape{
public :
  Shape1(int,int,int);
  Shape1();
  Shape1(const Shape1&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape1();
};
#endif
