#ifndef SHAPE6_HPP
#define SHAPE6_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape6:public AbstractShape{
public :
  Shape6(int,int,int);
  Shape6();
  Shape6(const Shape6&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape6();
};
#endif
