#ifndef SHAPE13_HPP
#define SHAPE13_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape13:public AbstractShape{
public :
  Shape13(int,int,int);
  Shape13();
  Shape13(const Shape13&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape13();
};

#endif