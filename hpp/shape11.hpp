#ifndef SHAPE11_HPP
#define SHAPE11_HPP
#include <iostream>
#include <vector>
#include "AbstractShape.hpp"
using namespace std;

class Shape11:public AbstractShape{
public :
  Shape11(int,int,int);
  Shape11();
  Shape11(const Shape11&);
  AbstractShape * Clone(int,int,int)const;
  ~Shape11();
};

#endif