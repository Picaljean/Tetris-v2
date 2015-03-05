#ifndef SHAPE10_HPP
#define SHAPE10_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape10:public AbstractShape{
public :
  Shape10(int,int,int);
  Shape10();
  Shape10(const Shape10&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape10();
};

#endif