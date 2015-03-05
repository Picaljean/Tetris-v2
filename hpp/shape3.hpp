#ifndef SHAPE3_HPP
#define SHAPE3_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape3:public AbstractShape{
public :
  Shape3(int,int,int);
  Shape3();
  Shape3(const Shape3&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape3();
};
#endif
