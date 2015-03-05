#ifndef FACTORY_HPP
#define FACTORY_HPP
#include <map>
#include <string>
#include "shape0.hpp"
#include "shape1.hpp"
#include "shape2.hpp"
#include "shape3.hpp"
#include "shape4.hpp"
#include "shape5.hpp"
#include "shape6.hpp"
#include "shape7.hpp"
#include "shape8.hpp"
#include "shape9.hpp"
#include "shape10.hpp"
#include "shape11.hpp"
#include "shape12.hpp"
#include "shape13.hpp"
#include "shape14.hpp"
#include "shape15.hpp"
#include "shape16.hpp"
#include "shape17.hpp"
#include "shape18.hpp"
#include "AbstractShape.hpp"
using namespace std;

class Factory{
private:
  static map <string, AbstractShape *> factory;
public :
  Factory();
  static void Register(const string,AbstractShape*);
  AbstractShape * create(const string,int,int,int);
  AbstractShape * create_random_shape(int,int,int);
  ~Factory();
};
#endif
