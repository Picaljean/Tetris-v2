#ifndef SHAPE7_HPP
#define SHAPE7_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape7:public AbstractShape{
public :
  Shape7(int,int,int);
  Shape7();
  Shape7(const Shape7&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape7();
};

#endif