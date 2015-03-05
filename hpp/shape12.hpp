#ifndef SHAPE12_HPP
#define SHAPE12_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape12:public AbstractShape{
public :
  Shape12(int,int,int);
  Shape12();
  Shape12(const Shape12&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape12();
};

#endif