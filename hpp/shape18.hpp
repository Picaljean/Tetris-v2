#ifndef SHAPE18_HPP
#define SHAPE18_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape18:public AbstractShape{
public :
  Shape18(int,int,int);
  Shape18();
  Shape18(const Shape18&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape18();
};

#endif