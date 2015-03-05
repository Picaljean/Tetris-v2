#ifndef SHAPE5_HPP
#define SHAPE5_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape5:public AbstractShape{
public :
  Shape5(int,int,int);
  Shape5();
  Shape5(const Shape5&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape5();
};
#endif
