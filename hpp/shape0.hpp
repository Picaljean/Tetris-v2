#ifndef SHAPE0_HPP
#define SHAPE0_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape0:public AbstractShape{
public :
  Shape0(int,int,int);
  Shape0();
  Shape0(const Shape0 &);
  AbstractShape * Clone(int,int,int)const;
  ~Shape0();
};
#endif
