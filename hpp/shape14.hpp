#ifndef SHAPE14_HPP
#define SHAPE14_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape14:public AbstractShape{
public :
  Shape14(int,int,int);
  Shape14();
  Shape14(const Shape14&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape14();
};

#endif