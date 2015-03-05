#ifndef SHAPE9_HPP
#define SHAPE9_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape9:public AbstractShape{
public :
  Shape9(int,int,int);
  Shape9();
  Shape9(const Shape9&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape9();
};

#endif