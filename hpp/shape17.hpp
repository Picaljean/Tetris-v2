#ifndef SHAPE17_HPP
#define SHAPE17_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape17:public AbstractShape{
public :
  Shape17(int,int,int);
  Shape17();
  Shape17(const Shape17&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape17();
};

#endif